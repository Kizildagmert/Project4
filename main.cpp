#include <QCoreApplication>
#include <QDebug>
#include "user.h"
#include "book.h"
#include <iostream>
#include <QString>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char key;


    std::string m_userName;
    std::string m_userPassword;
    std::string m_userId;

    User obj;

    std::cout << "Username: ";
    std::cin>>m_userName;
    std::cout << "Password: ";
    std::cin >> m_userPassword;
    std::cout << "UserId: ";
    std::cin >> m_userId;


    QString userName = QString::fromStdString(m_userName);
    QString userPassword = QString::fromStdString(m_userPassword);
    QString userId = QString::fromStdString(m_userId);

    obj.checkUser(userName,userPassword,userId);



    std::cout << "Press A to insert a book. "<<std::endl;
    std::cout << "Press D to delete a book. "<<std::endl;
    std::cout << "Press S to sort a book. "<<std::endl;
    std::cout << "Press X to display a book. "<<std::endl;
    std::cout << "Press Q to exit. "<<std::endl;

    std::string m_bookName;
    std::string m_authorName;
    std::string m_ISBN;
    std::string m_keywords;
    std::string m_pageNumber;
    std::string m_publishYear;

    Book obj1;



    while (key != 'Z') {
        std::cout << "Enter Character Please:  "<< std::endl;
        std::cin >> key;

        if(key == 'A'){

            std::cout << "Insert Book"<<std::endl;

            std::cout << "Book Name: ";
            std::cin>>m_bookName;
            std::cout << "Author Name: ";
            std::cin>>m_authorName;
            std::cout << "ISBN: ";
            std::cin>>m_ISBN;
            std::cout << "Page Number:";
            std::cin>>m_pageNumber;
            std::cout << "Publish Year:";
            std::cin>>m_publishYear;
            std::cout << "keywords: ";
            std::cin>>m_keywords;

            QString bookName = QString::fromStdString(m_bookName);
            QString authorName = QString::fromStdString(m_authorName);
            QString ISBN = QString::fromStdString(m_ISBN);
            int pageNumber = atoi(m_pageNumber.c_str());
            int publishYear = atoi(m_publishYear.c_str());
            QString keywords = QString::fromStdString(m_keywords);


            obj1.insertBook(bookName,authorName,ISBN,pageNumber,publishYear,keywords);

        }


        if(key == 'D' ){
            std::cout << "Delete Book" << std::endl;
            //QString ISBN = QString::fromStdString(m_ISBN);
            obj1.displayAllBook();
            std::cout << "Enter ISBN: " << std::endl;
            std::cin >> m_ISBN;
            QString ISBN = QString::fromStdString(m_ISBN);

            obj1.deleteBook(ISBN);

            qDebug() << "ISBN deleted.";

        }

        if(key == 'S'){

            int publishYear = atoi(m_publishYear.c_str());
            obj1.sortBook(publishYear);

        }


        if(key == 'X'){

            obj1.displayAllBook();

        }
        if(key=='Q'){

            return 0;
            exit(0);
            // exit(EXIT_SUCCESS);
        }


    }

    return a.exec();
}
