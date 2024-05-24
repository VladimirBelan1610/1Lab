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

    QObject::connect(&FileWatcher,&FileWatcher::LoggerRequest,&Logger, &Logger::Output);
    //Используется метод connect для подключения сигнала LoggerRequest к слоту Output объекта Logger.
    //Это означает, что при эмиссии сигнала LoggerRequest будет вызван метод Output у объекта Logger.
    Logger.Input(2);
    QString number = InputReader.ReadInput();
    int n = number.toInt();
    for(int i=0;i<n;i++)
    {
        Logger.Input(1);
        QString path = InputReader.ReadInput();
        FileWatcher.initializationOfFile(path);
    }
    int massSiz = FileWatcher.GetSizeMass();
    for(int i=0;i<massSiz;i++)
    {
        Logger.Output(3,FileWatcher.GetSize(i),FileWatcher.GetPath(i));
    }

    return a.exec();
}
