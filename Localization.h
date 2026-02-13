#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

enum Language
{
    ENGLISH =1,
    GERMAN
};

class Localization
{
private:
    Language currentlanguage;
    map<string,string>EN;
    map<string,string>DE;

public:
    Localization(Language lang)
    {
        currentlanguage = lang;

        EN=
        {
            {"enter_admin_name","Enter Admin Name: "},
            {"enter_password","Enter Your Password: "},
            {"login_success","Login Successful"},
            {"logout","Logout"},
            {"add_q","Add Question"},
            {"view_q","View Question"},
            {"update_q","Modify Question"},
            {"delete_q","Delete Question"},
            {"choice","Choice: "},
            {"q-added","Question added"},
            {"q_not_found","Question not found"},
            {"q_deleted","Question Deleted"},
            {"q_updated","Question Updated"},
            {"qid","Question ID: "},
            {"qtext","Question Text: "},
            {"option","Option "},
            {"enter_qid_delete", "Enter Question ID to delete: "},
            {"question_label", "Question: "},
            {"correct_answer", "Correct Answer: "},
            {"enter_new_data", "Enter new data: "},
            {"new_question_text", "New Question text: "},
            {"new_answer", "New Answer: "},
            {"enter_qid_modify", "Enter Question ID to modify: "},
            {"enter_name_or_id", "Enter your name or ID: "},
            {"name_id_empty", "Name/ID cannot be empty. Enter again: "},
            {"file_open_error", "ERROR: Cannot open file: "},
            {"no_valid_questions", "ERROR: No valid questions found in "},
            {"exam_instructions", "\n--- Exam Instructions ---\n"},
            {"exam_instr_1", "1) Answer questions one by one.\n"},
            {"exam_instr_2", "2) Choose A, B, C, or D.\n"},
            {"exam_instr_3", "3) Your score will be calculated automatically.\n"},
            {"exam_instr_end", "--------------------------\n"},
            {"of_total", " of "},
            {"result_header", "\n=== Result ===\n"},
            {"result_correct", "Correct: "},
            {"result_score", "Final Score: "},
            {"result_status", "Status: "},
            {"file_write_error", "ERROR: Cannot write to file: "},
            {"fix_questions_file", "Fix questions.txt format then run again.\n"},
            {"pass", "PASS"},
            {"fail", "FAIL"},
            {"your_answer", "Your answer (A/B/C/D): "},
            {"invalid_input", "Invalid input. Please enter A, B, C, or D.\n"},
            {"id_exists", "ERROR: Question ID already exists. Please enter another ID.\n"},
            {"already_taken_exam","You have already taken the exam. You cannot take it again."},
            {"invalid_student_id","Invalid ID format."},
            {"access_denied", "Access denied.\n"},
            {"invalid_admin_credentials", "ERROR: Invalid admin credentials!\n"},
            {"remaining_time", "[Remaining time: "},
            {"time_up", "\n[Timer] Time is up. Exam submitted automatically.\n"},
            {"exam_duration", "\n[Timer] Exam duration = "},
            {"student_not_found","Student ID not found."}


        };


        DE=
        {
            {"enter_admin_name","Admin Name eingeben: "},
            {"enter_password","Passwort eingeben: "},
            {"login_success","Anmeldung erfolgreich"},
            {"logout","Abmeldung"},
            {"add_q","Frage hinzufugen"},
            {"view_q","Fragen anzeigen"},
            {"update_q","Frage bearbeiten"},
            {"delete_q","Frage loschen"},
            {"choice","Ausmahl: "},
            {"q-added","Frage hinzugefuget"},
            {"q_not_found","Frage nicht gefunden"},
            {"q_deleted","Frage geloscht"},
            {"q_updated","Frage aktualisiert"},
            {"qid","Fragen-ID: "},
            {"qtext","FrageText: "},
            {"option","Option"},
            {"enter_qid_delete", "Geben Sie die Frage-ID zum Löschen ein: "},
            {"question_label", "Frage: "},
            {"correct_answer", "Richtige Antwort: "},
            {"enter_new_data", "Neue Daten eingeben: "},
            {"new_question_text", "Neuer Fragetext: "},
            {"new_answer", "Neue Antwort: "},
            {"enter_qid_modify", "Geben Sie die Frage-ID zum Bearbeiten ein: "},
            {"enter_name_or_id", "Geben Sie Ihren Namen oder Ihre ID ein: "},
            {"name_id_empty", "Name/ID darf nicht leer sein. Bitte erneut eingeben: "},
            {"file_open_error", "FEHLER: Datei kann nicht geöffnet werden: "},
            {"no_valid_questions", "FEHLER: Keine gültigen Fragen gefunden in "},
            {"exam_instructions", "\n--- Prüfungsanweisungen ---\n"},
            {"exam_instr_1", "1) Beantworten Sie die Fragen nacheinander.\n"},
            {"exam_instr_2", "2) Wählen Sie A, B, C oder D.\n"},
            {"exam_instr_3", "3) Ihre Punktzahl wird automatisch berechnet.\n"},
            {"exam_instr_end", "--------------------------\n"},
            {"question_number", "\nFrage "},
            {"of_total", " von "},
            {"result_header", "\n=== Ergebnis ===\n"},
            {"result_correct", "Richtig: "},
            {"result_score", "Endpunktzahl: "},
            {"result_status", "Status: "},
            {"file_write_error", "FEHLER: Kann nicht in die Datei schreiben: "},
            {"fix_questions_file", "Format der questions.txt korrigieren und erneut ausführen.\n"},
            {"pass", "BESTANDEN"},
            {"fail", "NICHT BESTANDEN"},
            {"your_answer", "Ihre Antwort (A/B/C/D): "},
            {"invalid_input", "Ungültige Eingabe. Bitte A, B, C oder D eingeben.\n"},
            {"id_exists", "FEHLER: Die Frage-ID existiert bereits. Bitte eine andere ID eingeben.\n"},
            {"already_taken_exam","Sie haben die Prüfung bereits abgelegt. Sie können sie nicht erneut ablegen."},
            {"invalid_student_id","Ungültige ID."},
            {"access_denied", "Zugriff verweigert.\n"},
            {"invalid_admin_credentials", "FEHLER: Ungültige Admin-Zugangsdaten!\n"},
            {"remaining_time", "[Verbleibende Zeit: "},
            {"time_up","\n[Timer] Zeit ist abgelaufen. Prüfung wurde automatisch abgegeben.\n"},
            {"exam_duration", "\n[Timer] Prüfungsdauer = "},
            {"student_not_found","Student-ID nicht gefunden."}

        };
    };


    string get(const string& key)
    {
        if (currentlanguage ==GERMAN && DE.count(key))
            return DE[key];
        if(EN.count(key))
            return EN[key];


        return key;
    }
};


#endif

