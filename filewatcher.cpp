#include "filewatcher.h"

FileWatcher::FileWatcher(QObject *parent) : QObject(parent) //Инициализирует объект FileWatcher. Он принимает указатель на родительский объект (по умолчанию nullptr).
{
    connect(&m_timer, &QTimer::timeout, this, &FileWatcher::checkFile); //Используется метод connect для подключения
                                                                        //сигнала timeout от QTimer к методу checkFile.
                                                                        //Это означает, что метод checkFile будет вызываться каждый раз,
                                                                        //когда таймер сработает.

    connect(this, &FileWatcher::LoggerRequest,&Logger, &Logger::Output);
//Используется метод connect для подключения сигнала LoggerRequest к слоту Output объекта Logger.
//Это означает, что при эмиссии сигнала LoggerRequest будет вызван метод Output у объекта Logger.
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


    bool newexist = m_file.exists(); //получаем текущие данные о файле
    qint64 newSize = m_file.size();
    if (m_exist != newexist || newSize != m_fileSize)
    {
        if(newexist == m_exist){
            m_fileSize = newSize;
            emit LoggerRequest(4,m_fileSize, m_filePath);

        }
        if (newexist == true && newSize != 0){
            m_exist = newexist;
            emit LoggerRequest(2,m_fileSize, m_filePath);

        }
        if(newexist == false && newSize == 0){
            m_exist = newexist;
            emit LoggerRequest(5,m_fileSize, m_filePath);

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


int FileWatcher::GetSize(){ //геттер для размера файла
    return m_fileSize;
};
