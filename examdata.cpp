#include "examdata.h"
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

ExamData& ExamData::instance()
{
    static ExamData instance;
    return instance;
}

ExamData::ExamData() {}

QString ExamData::getDataPath(const QString& filename)
{
    // Search from current/app directories and walk up parents so GUI and console
    // resolve the same shared data files in the project root.
    const QStringList roots = {
        QDir::currentPath(),
        QCoreApplication::applicationDirPath()
    };

    for (const QString& root : roots) {
        QDir dir(root);
        for (int i = 0; i < 8; ++i) {
            const QString candidate = dir.filePath(filename);
            if (QFile::exists(candidate)) {
                return candidate;
            }
            if (!dir.cdUp()) {
                break;
            }
        }
    }

    return QDir::current().filePath(filename);
}

QVector<Question> ExamData::loadQuestions()
{
    QVector<Question> questions;
    QString path = getDataPath("questions.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open questions file:" << path;
        return questions;
    }
    
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        Question q;
        if (q.loadFromFile(stream)) {
            questions.append(q);
        }
    }
    
    file.close();
    return questions;
}

bool ExamData::saveQuestion(const Question& q)
{
    QString path = getDataPath("questions.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Cannot open questions file for writing:" << path;
        return false;
    }
    
    QTextStream stream(&file);
    q.saveToFile(stream);
    file.close();
    return true;
}

bool ExamData::deleteQuestion(int id)
{
    QVector<Question> questions = loadQuestions();
    bool found = false;
    
    QString path = getDataPath("questions.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return false;
    }
    
    QTextStream stream(&file);
    for (const Question& q : questions) {
        if (q.id != id) {
            q.saveToFile(stream);
        } else {
            found = true;
        }
    }
    
    file.close();
    return found;
}

bool ExamData::questionExists(int id)
{
    QVector<Question> questions = loadQuestions();
    for (const Question& q : questions) {
        if (q.id == id) return true;
    }
    return false;
}

bool ExamData::updateQuestion(const Question& updatedQ)
{
    QVector<Question> questions = loadQuestions();
    
    QString path = getDataPath("questions.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return false;
    }
    
    QTextStream stream(&file);
    for (const Question& q : questions) {
        if (q.id == updatedQ.id) {
            updatedQ.saveToFile(stream);
        } else {
            q.saveToFile(stream);
        }
    }
    
    file.close();
    return true;
}

bool ExamData::studentExists(const QString& studentId)
{
    QString path = getDataPath("students.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();
        if (line == studentId) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

QVector<QString> ExamData::loadStudents()
{
    QVector<QString> students;
    QString path = getDataPath("students.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return students;
    }
    
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();
        if (!line.isEmpty()) {
            students.append(line);
        }
    }
    
    file.close();
    return students;
}

bool ExamData::hasTakenExam(const QString& studentId)
{
    QString path = getDataPath("results.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    
    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.startsWith(studentId)) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

bool ExamData::saveResult(const QString& studentId, int score, const QString& status, bool timeExpired)
{
    QString path = getDataPath("results.txt");
    QFile file(path);
    
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        return false;
    }
    
    QTextStream stream(&file);
    stream << studentId << " - " << score << "% - " << status;
    if (timeExpired) {
        stream << " - TIME UP";
    }
    stream << "\n";
    
    file.close();
    return true;
}
