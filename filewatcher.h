#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <Logger.h>
#include <QFileInfo>


class fileInform:public QFileInfo
{
private:
    bool exist;
    int size;
public:
    fileInform(QString path);
    int check(QString file);
};


class FileWatcher : public QObject
{
    Q_OBJECT //макрос для работы с механизмом сигналов и слотов
public:
    FileWatcher(QObject *parent = nullptr); //Конструктор класса. Принимает указатель на родительский объект (по умолчанию nullptr).
    void initializationOfFile(const QString &filePath); //Метод для инициализации файла, который будет отслеживаться. Принимает путь к файлу.
    void checkFile(); //Метод для проверки состояния файла (существует ли он, изменился ли и т.д.).
    int GetSize(int i); // Метод для получения размера файла.
    int GetSizeMass();
    QString GetPath(int i);
signals:
    void fileExists(QString filePath, qint64 fileSize); //Сигнал, который эмитируется, когда файл существует. Передает путь к файлу и его размер.
    void fileChanged(QString filePath, qint64 fileSize); //Сигнал, который эмитируется, когда файл изменился. Передает путь к файлу и его размер.
    void LoggerRequest(int e, int t, QString z); //Сигнал для запроса к логгеру. Передает три параметра (вероятно, тип события, размер файла и путь к файлу).

private:
    QString m_filePath; //Строка, содержащая путь к файлу.
    QFile m_file; //Объект класса QFile, представляющий файл.
    qint64 m_fileSize; //Переменная для хранения размера файла.
    QTimer m_timer; //Таймер для периодической проверки состояния файла.
    bool m_exist; //Логическая переменная, указывающая на существование файла.
    Logger Logger; //Объект класса Logger, используемый для ведения логов.
    QVector<fileInform> massOfFiles;//Этот вектор будет использоваться для хранения информации о файлах в виде объектов fileInform.
    QVector<QFileInfo> massOfFiles2; //вектор будет использоваться для хранения информации о файлах и каталогах в виде объектов QFileInfo.

};



#endif // FILEWATCHER_H
