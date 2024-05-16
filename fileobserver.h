#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H


#include <QObject>
#include <QDebug>

class FileObserver : public QObject
{
    Q_OBJECT
public:
    explicit FileObserver(QObject *parent = nullptr);

public slots:
    void handleFileExists(QString filePath, qint64 fileSize);
    void handleFileChanged(QString filePath, qint64 fileSize);
};

#endif // FILEOBSERVER_H
