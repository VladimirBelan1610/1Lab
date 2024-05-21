#include "filewatcher.h"

FileWatcher::FileWatcher(QObject *parent) : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout, this, &FileWatcher::checkFile);
    connect(this, &FileWatcher::LoggerRequest,&Logger, &Logger::Output);

}

void FileWatcher::initializationOfFile(const QString &filePath)
{
    m_filePath = filePath;
    m_file.setFileName(m_filePath);
    m_fileSize = m_file.size();
    m_exist = m_file.exists();
    m_timer.start(100); // Проверяем файл каждые 100 мс
}

int FileWatcher::checkFile()
{


    bool newexist = m_file.exists();
    qint64 newSize = m_file.size();
    if (m_exist != newexist || newSize != m_fileSize)
    {
        if(newexist == m_exist){
            m_fileSize = newSize;
            emit LoggerRequest(4,m_fileSize, m_filePath);
            return 4;
        }
        if (newexist == true && newSize != 0){
            m_exist = newexist;
            emit LoggerRequest(2,m_fileSize, m_filePath);
            return 2;
        }
        if(newexist == false && newSize == 0){
            m_exist = newexist;
            emit LoggerRequest(5,m_fileSize, m_filePath);
            return 5;
        }


    }

    //if (newSize != m_fileSize)
    //{
       //  m_fileSize = newSize;
       // emit LoggerRequest(4,m_fileSize, m_filePath);
       // return 4;

   // }
    return 0;
}


int FileWatcher::GetSize(){
    return m_fileSize;
};
