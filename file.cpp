#include "file.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <fstream>
#include <QDir>
File::File(QString fileName)
{

    m_fileName = fileName;
    QString path = QDir().currentPath();
    qDebug() <<    "PATH:  " << path;
    qDebug() <<  "FILE: " << m_fileName;
    m_fileName = path +"/"+ m_fileName;
    qDebug() <<  "FULL PATH " << m_fileName;
}

File::~File()
{

}
bool File::writeAllInfoFile(QStringList variableToWriteFile)
{

    QFile mFile(m_fileName);

    if (mFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){

        QTextStream out(&mFile);

        for (int i = 0; i < variableToWriteFile.size(); i++) {

            out << variableToWriteFile[i]<<" ";
            out << endl;

        }
        mFile.flush();
        mFile.close();
        qDebug() << "file written.";
        return true;
    }
    else
        qDebug() << "file can not written";


}

bool File::writeFile(QStringList variableToWriteFile)
{

    QFile mFile(m_fileName);

    if (mFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){

        QTextStream out(&mFile);

        for (int i = 0; i < variableToWriteFile.size(); i++) {

            out << variableToWriteFile[i]<<" ";

        }
        out << endl;
        mFile.flush();
        mFile.close();
        qDebug() << "file written.";
        return true;
    }
    else
        qDebug() << "file can not written";


}

QStringList File::readFile()
{
    QStringList variableToReadFile;
    QFile mFile(m_fileName);

    if(!mFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "file can not reading";
        return QStringList();
    }

    QTextStream in(&mFile);

    while(!in.atEnd()){
        QString Line = in.readLine();

        variableToReadFile.append(Line);
    }

    mFile.close();
    return variableToReadFile;

}





