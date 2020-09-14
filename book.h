#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <QObject>
#include "file.h"

class Book
{
public:

    Book();
    ~Book();
    File *bookfileObj;
    bool insertBook(QString bookName,QString authorName,QString ISBN,int pageNumber,int publishYear,QString keywords);
    bool deleteBook(QString ISBN );
    void sortBook(int publishYear);
    void displayAllBook( );


    QString m_bookName;
    QString m_authorName;
    QString m_ISBN;
    int m_pageNumber;
    int m_publishYear;
    QString m_keywords;
};

#endif // BOOK_H
