#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <Logger.h>


class FileWatcher : public QObject
{
    Q_OBJECT
public:
    FileWatcher(QObject *parent = nullptr);
    void initializationOfFile(const QString &filePath);
    int checkFile();
    int GetSize();

signals:
    void fileExists(QString filePath, qint64 fileSize);
    void fileChanged(QString filePath, qint64 fileSize);
    void LoggerRequest(int e, int t, QString z);

private:
    QString m_filePath;
    QFile m_file;
    qint64 m_fileSize;
    QTimer m_timer;
    bool m_exist;
    Logger Logger;

};



#endif // FILEWATCHER_H
