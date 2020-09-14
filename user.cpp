#include "user.h"
#include <QDebug>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QDir>
User::User()
{

    QString m_fileName = "UserFile.txt";

    fileObj = new File(m_fileName);

}
User::~User()
{

}

void User::addNewUser(QString userName, QString userPassword, QString userId )
{

    QStringList tUserInfo;

    tUserInfo.append(userName);
    tUserInfo.append(userPassword);
    tUserInfo.append(userId);

    fileObj->writeFile(tUserInfo);

}

bool User::checkUser(QString userName , QString userPassword , QString userId)
{
    QStringList tCheckInfo;
    tCheckInfo.append(userName);
    tCheckInfo.append(userPassword);
    tCheckInfo.append(userId);

    QStringList returnAllUsers = fileObj->readFile();
    returnAllUsers.append(fileObj->readFile());

    for(int i =0;  i < returnAllUsers.size();  i++){
        QStringList listEachLine = returnAllUsers[i].split(QRegExp("\\s+"),Qt::SkipEmptyParts);

        if(userId == listEachLine[2] ){

            qDebug() << "Böyle bir kullanıcı var . Yeniden dene";
            return true;

        }
    }

    addNewUser(userName,userPassword,userId);
    qDebug() << "Böyle bir kullanıcı yok. Kayıt başarılı";


}





