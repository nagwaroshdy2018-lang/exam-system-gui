#ifndef EXAMDATA_H
#define EXAMDATA_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "Question.h"

class ExamData
{
public:
    static ExamData& instance();
    
    // Questions
    QVector<Question> loadQuestions();
    bool saveQuestion(const Question& q);
    bool deleteQuestion(int id);
    bool questionExists(int id);
    bool updateQuestion(const Question& q);
    
    // Students
    bool studentExists(const QString& studentId);
    QVector<QString> loadStudents();
    
    // Results
    bool hasTakenExam(const QString& studentId);
    bool saveResult(const QString& studentId, int score, const QString& status, bool timeExpired);
    
private:
    ExamData();
    QString getDataPath(const QString& filename);
};

#endif // EXAMDATA_H
