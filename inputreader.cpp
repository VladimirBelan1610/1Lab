#include "inputreader.h"
#include <QTextStream>
InputReader::InputReader()
    {

    };

QString InputReader::ReadInput()
{
    QTextStream in(stdin);
    in >> r_filePath;
    return r_filePath;

};

QString InputReader::GetPath(){
    return r_filePath;
};

