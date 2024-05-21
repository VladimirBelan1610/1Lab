#include <QCoreApplication>
#include <QTextStream>
#include "filewatcher.h"
#include "Logger.h"
#include <locale.h>
#include <inputreader.h>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"ru_RU.UTF-8");

    QCoreApplication a(argc, argv);

    InputReader InputReader;
    FileWatcher FileWatcher; //созданы объекты класса
    Logger Logger;


    Logger.Input(1);
    QString path = InputReader.ReadInput();
    FileWatcher.initializationOfFile(path);






    return a.exec();
}
