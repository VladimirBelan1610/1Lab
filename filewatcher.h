#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QDebug>
class FileWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileWatcher(QObject *parent = nullptr);
    void setFilePath(const QString &filePath);

signals:
    void fileExists(QString filePath, qint64 fileSize);
    void fileChanged(QString filePath, qint64 fileSize);

private slots:
    void checkFile();

private:
    QString m_filePath;
    QFile m_file;
    qint64 m_fileSize;
    QTimer m_timer;
};



#endif // FILEWATCHER_H
