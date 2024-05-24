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
    case(2):
        cout << "Enter number of files\n";
        break;
    }

}
void Logger::Output(int q, int fileSize, QString filePath)
{
    QTextStream out(stdout); //Потоковый вывод QT
    switch(q){
    case(2):
        out << "\nFile has been created\n" << filePath << " Size: "<< fileSize;
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
