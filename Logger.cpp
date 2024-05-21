#include "Logger.h"

Logger::Logger(){
    setlocale(LC_ALL,"ru_RU.UTF-8");
}

void Logger::Input(int q)
{
    switch(q){
    case(1):
        cout << "Enter the file path\n";
        break;
    }

}
void Logger::Output(int q, int fileSize, QString filePath)
{
    QTextStream out(stdout); //Потоковый вывод QT
    switch(q){
    case(2):
        out << "File has been created\n";
        out.flush();
        break;
    case(3):
        out << "\nFile exists. " << filePath << " Size: "<< fileSize;
        out.flush();
        break;
    case(4):
        out << "\nFile was changed. " << filePath << " Size: " << fileSize;
        out.flush();
        break;
    case(5):
        out << "\nFile was delete.\n";
        out.flush();
        break;
    case(6):
        out << "\nFile is not exists.\n";
        out.flush();
        break;

    }

}
