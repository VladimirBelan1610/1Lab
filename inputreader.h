#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <QObject>

class InputReader : public QObject
{
    Q_OBJECT
public:
    InputReader();
    QString ReadInput();
    QString GetPath();
private:
    QString r_filePath;

};

#endif // INPUTREADER_H
