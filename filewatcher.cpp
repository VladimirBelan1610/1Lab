#include "filewatcher.h"

FileWatcher::FileWatcher(QObject *parent) : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout, this, &FileWatcher::checkFile);
}

void FileWatcher::setFilePath(const QString &filePath)
{
    m_filePath = filePath;
    m_file.setFileName(m_filePath);
    m_file.open(QIODevice::ReadOnly);
    m_fileSize = m_file.size();

    m_timer.start(1000); // Проверяем файл каждые 100 мс
}

void FileWatcher::checkFile()
{
    if (!m_file.exists())
    {
        qDebug() << "Файл не существует";
        return;
    }

    qint64 newSize = m_file.size();
    if (newSize != m_fileSize)
    {
        qDebug() << "Файл был изменен. Размер файла: " << newSize;
        emit fileChanged(m_filePath, newSize);
        m_fileSize = newSize;
    }
    else
    {
        qDebug() << "Файл существует. Размер файла: " << newSize;
        emit fileExists(m_filePath, newSize);
    }
}
