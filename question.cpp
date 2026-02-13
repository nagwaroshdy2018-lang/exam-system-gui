#include "Question.h"

#include <QChar>
#include <QString>
#include <QTextStream>

Question::Question(int questionId, const QString& questionText, const QString opt[4], QChar correct)
    : id(questionId), text(questionText.toStdString()), correctAnswer(correct.toUpper().toLatin1())
{
    for (int i = 0; i < 4; ++i) {
        options[i] = opt[i].toStdString();
    }
}

bool Question::loadFromFile(QTextStream& stream)
{
    QString idStr;
    do {
        if (stream.atEnd()) return false;
        idStr = stream.readLine().trimmed();
    } while (idStr.isEmpty());

    bool ok = false;
    int parsedId = idStr.toInt(&ok);
    if (!ok) return false;
    id = parsedId;

    QString questionText = stream.readLine();
    if (questionText.isEmpty()) return false;
    text = questionText.toStdString();

    for (int i = 0; i < 4; ++i) {
        QString option = stream.readLine();
        if (option.isEmpty()) return false;
        options[i] = option.toStdString();
    }

    QString answer = stream.readLine().trimmed();
    if (answer.isEmpty()) return false;
    correctAnswer = answer.at(0).toUpper().toLatin1();

    return (correctAnswer >= 'A' && correctAnswer <= 'D');
}

void Question::saveToFile(QTextStream& stream) const
{
    stream << id << "\n";
    stream << QString::fromStdString(text) << "\n";
    for (int i = 0; i < 4; ++i) {
        stream << QString::fromStdString(options[i]) << "\n";
    }
    stream << QChar(correctAnswer) << "\n";
}
