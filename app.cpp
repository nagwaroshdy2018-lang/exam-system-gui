#include <iostream>
#include "Localization.h"
#include "Admin.h"
#include "ExamTaker.h"
using namespace std;

int main() {
    int langChoice, userChoice;

    cout << " 1. Admin\n 2. Student\nChoose user type: ";
    cin >> userChoice;

    system("CLS");
    cout << " 1. English \n 2. German\nChoose language: ";
    cin >> langChoice;
    Localization lang((Language)langChoice);
    system("CLS");


    if (userChoice == 1) {
        Admin admin(lang);
        if(!admin.login())
        {
            cout <<lang.get("access_denied");
            return 0;
        }
        system("CLS");
        admin.menu();
    }
    else if (userChoice == 2) {
    Student student(lang);
    Exam exam(lang);

    exam.setDurationSeconds(30); // تحديد الوقت بالثواني

    student.login();
    if(exam.alreadyTaken(student))
    {
        cout <<lang.get("already_taken_exam")<<endl;
        return 0;
    }

    if (!exam.loadQuestions("questions.txt")) {
        cout << lang.get("fix_questions_file");
        return 1;
    }

    system("CLS");
    exam.showInstructions();
    exam.start();
    system("CLS");
    exam.showResult();
    exam.saveResult(student);
}

    return 0;
}
