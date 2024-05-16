#include <QCoreApplication>
#include <QTextStream>
#include "filewatcher.h"
#include "fileobserver.h"
#include <locale.h>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"rus");

    QCoreApplication a(argc, argv);

    QTextStream cin(stdin);

    FileWatcher watcher;
    FileObserver observer;

    QObject::connect(&watcher, &FileWatcher::fileExists, &observer, &FileObserver::handleFileExists);
    QObject::connect(&watcher, &FileWatcher::fileChanged, &observer, &FileObserver::handleFileChanged);

    QString filePath;
    qDebug() << "Введите путь к файлу для отслеживания:";

    cin >> filePath;

    watcher.setFilePath(filePath);

    return a.exec();
}
