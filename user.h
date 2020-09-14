#ifndef USER_H
#define USER_H

#include <QObject>
#include <iostream>
#include "file.h"
class User
{
public:

    User();
    ~User();
    File *fileObj;
    void addNewUser(QString userName , QString userPassword , QString userId);
    bool checkUser(QString userName , QString userPassword , QString userId);

};

#endif // USER_H
