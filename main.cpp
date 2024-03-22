#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>
#include <iostream>
#include <QThread>
#include <QString>

using namespace std;

void checkFile(const QString& filePath) {
    QFileInfo fileInfo(filePath);

    if (fileInfo.exists()) {
        qDebug() << "exist true, file size:" << fileInfo.size();

        QDateTime lastModified = fileInfo.lastModified();
        qDebug() << "Last modified:" << lastModified.toString();
    } else {
        qDebug() << "exist false";
    }
}

istream& operator >>(std::istream& in, QString& str) {
    std::string temp;
    in >> temp;
    str = QString::fromStdString(temp);
    return in;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList filesList;

    while (true) {
        qDebug() << "Enter file path to add to watch list (or 'exit' to quit):";
        QString filePath;
        cin >> filePath;

        if (filePath == "exit") {
            break;
        }

        filesList.append(filePath);
    }

    qDebug() << "Watching files for changes...";

    while (true) {
        for (const QString& filePath : filesList) {
            checkFile(filePath);
        }

        QThread::sleep(1); // Check every 1 second
    }

    return a.exec();
}

