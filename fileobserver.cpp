#include "fileobserver.h"

FileObserver::FileObserver(QObject *parent) : QObject(parent)
{

}

void FileObserver::handleFileExists(QString filePath, qint64 fileSize)
{
    qDebug() << "Файл существует. Размер файла: " << fileSize;
}

void FileObserver::handleFileChanged(QString filePath, qint64 fileSize)
{
    qDebug() << "Файл был изменен. Размер файла: " << fileSize;
}
