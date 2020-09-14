#ifndef FILE_H
#define FILE_H
#include <QObject>

class File{

public:
    File(QString fileName);
    ~File();
    QStringList readFile();
    bool writeFile(QStringList  variableToWriteFile);
    bool writeAllInfoFile(QStringList  variableToWriteFile);
    QString m_fileName;
    QString m_bookFileName;
};


#endif // FILE_H
