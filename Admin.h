#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>
#include<fstream>
#include<string>
#include "Question.h"
#include "Localization.h"
using namespace std;

class Admin
{

private:
    string AdminName, AdminPass;

    const string NAME = "admin";
    const string PASS = "admin";

public:


     Localization& lang;
    Admin(Localization& L) : lang(L) {}


    void addQuestion()
    {
        Question q;

        ofstream file("questions.txt",ios::app	);

        while(true)
        {
            cout<<lang.get("qid");
            cin>>q.id;

            if(isQuestionExists(q.id))
            {
                cout<<lang.get("id_exists");
            }
            else
                break;

        }

        cout<<lang.get("qtext");
        cin.ignore();
        getline(cin,q.text);

        for(int i=0;i<4;i++)
        {
            cout<<lang.get("option")<<i+1<<": ";
            getline(cin,q.options[i]);
        }
        cout<<lang.get("correct_answer");
        cin>>q.correctAnswer;

        file << q.id<<endl;
        file << q.text<<endl;
        for(int i=0;i<4;i++)
        {
            file << q.options[i]<<endl;
        }
        file << q.correctAnswer<<endl;

        file.close();
        cout<<lang.get("q-added")<<endl;

    }

    void viewQuestions()
    {
        ifstream file("questions.txt");
        Question q;
        int num=1;

        while (file>>q.id)
        {
            file.ignore();
            getline(file,q.text);

            for(int i=0;i<4;i++)
            {
                getline(file,q.options[i]);
            }
            file >> q.correctAnswer;
            file.ignore();



            cout << num <<")";
            cout << q.text << endl;
            cout << "A) " << q.options[0] << endl;
            cout << "B) " << q.options[1] << endl;
            cout << "C) " << q.options[2] << endl;
            cout << "D) " << q.options[3] << endl;
            cout << lang.get("correct_answer") << q.correctAnswer << endl<<endl;

            num++;
        }
        file.close();
    }

    void updateQuestion()
    {
        int u_id;
        cout<<lang.get("enter_qid_modify");
        cin>>u_id;

        ifstream file("questions.txt");
        ofstream temp("temp.txt");

        Question q;
        bool found=false;

        while(file >>q.id)
        {
            file.ignore();
            getline(file,q.text);

            for(int i=0;i<4;i++)
            {
                getline(file,q.options[i]);
            }
            file >> q.correctAnswer;
            file.ignore();

            if(q.id==u_id)
            {
                found = true;
                cout <<lang.get("question_label")<<q.text<<endl;
                for(int i=0;i<4;i++)
                {
                    cout<<lang.get("option")<<i+1<<": "<<q.options[i]<<endl;
                }
                cout<<lang.get("correct_answer")<<q.correctAnswer<<endl;

                cout<<lang.get("enter_new_data")<<endl;
                cin.ignore();

                cout<<lang.get("new_question_text");
                getline(cin,q.text);
                for(int i=0;i<4;i++)
                {
                    cout<<lang.get("option")<<i+1<<": ";
                    getline(cin,q.options[i]);
                }
                cout<<lang.get("new_answer");
                cin>>q.correctAnswer;
                cout<<endl;
            }
            temp << q.id <<endl;
            temp << q.text <<endl;
            for(int i=0;i<4;i++)
            {
                temp << q.options[i]<<endl;
            }
            temp << q.correctAnswer<<endl;

        }
        file.close();
        temp.close();

        remove("questions.txt");
        rename("temp.txt","questions.txt");

        if(found)
            cout<<lang.get("q_updated")<<endl;
        else
            cout<<lang.get("q_not_found")<<endl;
    }

    void deleteQuestion()
    {
        int u_id;
        cout<<lang.get("enter_qid_delete");
        cin>>u_id;

        ifstream file("questions.txt");
        ofstream temp("temp.txt");

        Question q;
        bool found=false;

        while(file >>q.id)
        {
            file.ignore();
            getline(file,q.text);

            for(int i=0;i<4;i++)
            {
                getline(file,q.options[i]);
            }
            file >> q.correctAnswer;
            file.ignore();

            if(q.id!=u_id)
            {
                temp << q.id <<endl;
                temp << q.text <<endl;
                for(int i=0;i<4;i++)
                {
                    temp << q.options[i]<<endl;
                }
                temp << q.correctAnswer<<endl;
            }
            else
                found = true;

        }
        file.close();
        temp.close();

        remove("questions.txt");
        rename("temp.txt","questions.txt");

        if(found)
            cout <<lang.get("q_deleted")<<endl;
        else
            cout<<lang.get("q_not_found")<<endl;

    }

    bool login()
    {
        cout<<lang.get("enter_admin_name");
        cin>>AdminName;
        cout<<lang.get("enter_password");
        cin>>AdminPass;

        if (AdminName == NAME && AdminPass == PASS) {
            cout << lang.get("login_success") << endl;
            return true;
        }

        cout << lang.get("invalid_admin_credentials");
        return false;

    }

    void menu()
    {
        int choice;
        do
        {
            cout<<"1. "<<lang.get("add_q")<<endl;
            cout<<"2. "<<lang.get("view_q")<<endl;
            cout<<"3. "<<lang.get("update_q")<<endl;
            cout<<"4. "<<lang.get("delete_q")<<endl;
            cout<<"0. "<<lang.get("logout")<<endl;
            cout<<lang.get("choice");

            cin>>choice;
             system("CLS");

            if(choice==1)
            {
                addQuestion();}
            else if(choice==2)
            {
                viewQuestions();
            }

            else if(choice==3)
            {
                updateQuestion();
            }

            else if(choice==4)
            {
                deleteQuestion();
            }

        }while(choice!=0);


    }


    bool isQuestionExists(int checkid)
    {
        ifstream file("questions.txt");
        if(!file.is_open())
            return false;

        Question q;
        while(q.loadFromFile(file))
        {
            if(q.id ==checkid)
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

