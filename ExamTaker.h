#ifndef EXAMTaker_H
#define EXAMTaker_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>
#include <chrono>
#include "Question.h"
#include "Localization.h"
#include <algorithm>
#include <random>

using namespace std;

class Student {
private:
    string nameOrId;

public:
    Localization& lang;
    Student(Localization& L) : lang(L) {}

    void login() {
        cout << lang.get("enter_name_or_id");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nameOrId);

        if(!isValid(nameOrId))
        {
            cout <<lang.get("invalid_student_id");
            exit(5);
        }

        if (nameOrId.empty()) {
            cout << lang.get("name_id_empty");
            exit(5);
        }
        if(!existInFile())
        {
            cout <<lang.get("student_not_found");
            exit(5);
        }
    }

    const string& getNameOrId() const {
        return nameOrId;
    }

    bool isValid(const string& id)
    {
        if(id.length()!=4)
            return false;
        for(char c:id)
        {
            if(!isdigit(c))
                return false;
        }

        return true;
    }

    bool existInFile(const string& filename="students.txt")
    {
        ifstream file(filename);
        if(!file.is_open())
        {
            cout<<lang.get("file_open_error")<<filename<<endl;
            return false;
        }
        string line;
        while(getline(file,line))
        {
            if(line == nameOrId)
            {
                file.close();
                return true;

            }
        }
        file.close();
        return false;
    }
};

class Exam {
private:
    vector<Question> questions;
    int correctCount{0};

    //  Timer settings
    int durationSeconds{60};          // default 60 seconds
    bool timeExpired{false};

public:
    Localization& lang;
    Exam(Localization& l) : lang(l) {}

    void setDurationSeconds(int seconds) {
        if (seconds <= 0) seconds = 60;
        durationSeconds = seconds;
    }

    bool loadQuestions(const string &filename = "questions.txt") {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << lang.get("file_open_error") << filename << "\n";
            return false;
        }

        questions.clear();
        Question q;
        while (q.loadFromFile(file)) {
            questions.push_back(q);
        }

        file.close();


        if (questions.empty()) {
            cout << lang.get("no_valid_questions") << filename << "\n";
            return false;
        }

        random_device rd;
        mt19937 g(rd());
        shuffle(questions.begin(),questions.end(),g);
        return true;
    }

    void showInstructions() const {
        cout << lang.get("exam_instructions");
        cout << lang.get("exam_instr_1") << endl;
        cout << lang.get("exam_instr_2") << endl;
        cout << lang.get("exam_instr_3") << endl;
        cout << lang.get("exam_instr_end") << endl;

        cout << lang.get("exam_duration") << durationSeconds << " seconds\n";
    }

    void start() {
        using namespace std::chrono;

        correctCount = 0;
        timeExpired = false;

        auto startTime = steady_clock::now();
        auto deadline  = startTime + seconds(durationSeconds);

        for (size_t i = 0; i < questions.size(); i++) {
            int remaining = (int)duration_cast<seconds>(deadline - steady_clock::now()).count();

            if (remaining <= 0) {
                timeExpired = true;
                break;
            }

            cout << lang.get("question_label") << (i + 1)
                 << lang.get("of_total") << questions.size() << ":\n";

            cout << lang.get("remaining_time") << remaining << " sec]\n";

            bool timeUp = false;
            bool correct = questions[i].askAndCheck(remaining, timeUp);

            if (timeUp) {
                timeExpired = true;
                break;
            }

            if (correct) correctCount++;
        }
    }

    int finalScorePercent() const {
        if (questions.empty()) return 0;
        return (int)((correctCount * 100) / (int)questions.size());
    }

    string passFail() const {
        return (finalScorePercent() >= 50) ? lang.get("pass") : lang.get("fail");
    }

    void showResult() const {
        cout << lang.get("result_header");
        cout << lang.get("result_correct") << correctCount << " / " << questions.size() << "\n";
        cout << lang.get("result_score") << finalScorePercent() << "%\n";
        cout << lang.get("result_status") << passFail() << "\n";

        if (timeExpired) {
            cout << lang.get("time_up");
        }
    }

    void saveResult(const Student &student, const string &filename = "results.txt") const {
        ofstream out(filename, ios::app);
        if (!out.is_open()) {
            cout << lang.get("file_write_error") << filename << "\n";
            return;
        }

        out << student.getNameOrId()
            << " - " << finalScorePercent() << "% - " << passFail();

        if (timeExpired) out << " - TIME UP";
        out << "\n";

        out.close();
    }

    bool alreadyTaken(const Student &student, const string &filename="results.txt")
    {
        ifstream file(filename);
        if(!file.is_open())
            return false;

        string line;
        while(getline(file, line))
        {
            if(line.find(student.getNameOrId())==0)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

};

#endif
