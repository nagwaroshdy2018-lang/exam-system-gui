#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

class QTextStream;
class QString;
class QChar;


class Question {
public:

    int id{};
    string text;
    string options[4];
    char correctAnswer{'A'};

    Question() = default;
    Question(int id, const QString& text, const QString opt[4], QChar correct);


    bool loadFromFile(ifstream &file) {

        if (!(file >> id)) return false;
        file.ignore(numeric_limits<streamsize>::max(), '\n');


        if (!getline(file, text) || text.empty()) return false;


        for (int i = 0; i < 4; i++) {
            if (!getline(file, options[i]) || options[i].empty()) return false;
        }


        if (!(file >> correctAnswer)) return false;
        correctAnswer = (char)toupper((unsigned char)correctAnswer);
        file.ignore(numeric_limits<streamsize>::max(), '\n');


        if (correctAnswer < 'A' || correctAnswer > 'D') return false;

        return true;
    }

    bool loadFromFile(QTextStream& stream);
    void saveToFile(QTextStream& stream) const;

    bool askAndCheck(int remainingSeconds, bool &timeUp) const {
        (void)remainingSeconds;
        (void)timeUp;
        cout << "\n" << text << "\n";
        for (int i = 0; i < 4; i++) {
            cout << char('A' + i) << ") " << options[i] << "\n";
        }

        char answer;
        while (true) {
            cout << "Your answer (A/B/C/D): ";
            cin >> answer;
            answer = (char)toupper((unsigned char)answer);

            if (answer >= 'A' && answer <= 'D') break;
            cout << "Invalid input. Please enter A, B, C, or D.\n";
        }

        return answer == correctAnswer;
    }
};
#endif
