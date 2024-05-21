#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <QObject>
#include <QDebug>
#include <locale.h>
using namespace std;
class Logger : public QObject
{
    Q_OBJECT
public:
    Logger();
    void Output(int q, int fileSize, QString filePath);
    void Input(int q);
};

#endif // LOGGER_H
