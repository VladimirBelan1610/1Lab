#include "filewatcher.h"

// Конструктор класса FileWatcher
FileWatcher::FileWatcher(QObject *parent) : QObject(parent) {
    connect(&m_timer, &QTimer::timeout, this, &FileWatcher::checkFile);
}

// Конструктор класса fileInform
fileInform::fileInform(QString path) {
    QFileInfo file(path);
    exist = file.exists();
    size = file.size();
}

// Метод check класса fileInform
int fileInform::check(QString newpath) {
    QFileInfo fileinfo(newpath);
    int currsize = fileinfo.size();
    bool currexist = fileinfo.exists();

    if (currexist != exist || currsize != size) {
        if (!currexist && exist) {
            exist = currexist;
            size = currsize;
            return 5; // Файл был удален
        }
        if (currexist && !exist) {
            exist = currexist;
            size = currsize;
            return 2; // Файл был создан
        }
        if(currexist != exist || currsize != size){
        exist = currexist;
        size = currsize;
        return 4;} // Изменился размер или существование файла
    }

    return 0; // Нет изменений
}

// Метод инициализации файла в FileWatcher
void FileWatcher::initializationOfFile(const QString &filePath) {
    QFileInfo MN(filePath);
    fileInform massCharacterFile(filePath);
    massOfFiles.append(massCharacterFile);
    massOfFiles2.append(MN);
    m_timer.start(1000); // Проверяем файл каждые 1000 мс
}
// Метод проверки файла в FileWatcher
void FileWatcher::checkFile() {
    QTextStream out(stdout);
    int n = massOfFiles.size();
    for (int i = 0; i < n; i++) {
        int result = massOfFiles[i].check(massOfFiles2[i].absoluteFilePath());
        if (result == 2) {
            massOfFiles2[i].refresh();
            emit LoggerRequest(2, massOfFiles2[i].size(), massOfFiles2[i].absoluteFilePath());
        } else if (result == 4) {
            massOfFiles2[i].refresh();
            emit LoggerRequest(4, massOfFiles2[i].size(), massOfFiles2[i].absoluteFilePath());
        } else if (result == 5) {
            massOfFiles2[i].refresh();
            emit LoggerRequest(5, massOfFiles2[i].size(), massOfFiles2[i].absoluteFilePath());
        }
    }
}

// Геттер для размера файла
int FileWatcher::GetSize(int i) {
    return massOfFiles2[i].size();
}

// Геттер для размера массива
int FileWatcher::GetSizeMass() {
    return massOfFiles2.size();
}

// Геттер для пути файла
QString FileWatcher::GetPath(int i) {
    return massOfFiles2[i].absoluteFilePath();
}
