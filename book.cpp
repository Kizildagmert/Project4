#include "book.h"
#include <QDebug>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFile>
Book::Book()
{
    QString m_bookFileName = "booksFile.txt";
    bookfileObj = new File(" booksFile.txt");

}

Book::~Book()
{

}

bool Book::insertBook(QString bookName,QString authorName,QString ISBN,int pageNumber,int publishYear,QString keywords)
{
    QStringList tBookInsert;

    tBookInsert.append(bookName);
    tBookInsert.append(authorName);
    tBookInsert.append(ISBN);
    tBookInsert.append(QString::number(pageNumber));
    tBookInsert.append(QString::number(publishYear));
    tBookInsert.append(keywords);


    bookfileObj->writeFile(tBookInsert);

    return true;
}

bool Book::deleteBook(QString ISBN)
{
    QStringList updatedDeleteList;
    QStringList tDeleteInfo = bookfileObj->readFile();
    QStringList ListEachISBN;


    for (int i = 0; i < tDeleteInfo.size(); i++) {
        ListEachISBN = tDeleteInfo[i].split(QRegExp("\\s+"),Qt::SkipEmptyParts);

        if(ISBN == ListEachISBN[2]){
            tDeleteInfo.removeAt(i);

        }

        bookfileObj->readFile();
    }

    qDebug() << "After Deleted. "<< endl;
    for (int i = 0; i < tDeleteInfo.size(); ++i) {

        qDebug() << i+1 <<"." << tDeleteInfo[i];
        updatedDeleteList.append(tDeleteInfo[i]);

    }

    bookfileObj->writeAllInfoFile(updatedDeleteList);
}

void Book::sortBook(int publishYear)
{
    QStringList tSortInfo;
    tSortInfo.append(bookfileObj->readFile());
    QStringList ListEachBook;

    for (int i = 0; i < tSortInfo.size(); i++) {
        ListEachBook = tSortInfo[i].split(QRegExp("\\s+"),Qt::SkipEmptyParts);
        int firstyear =ListEachBook[4].toInt();

        for (int  j =i+ 1;  j <= tSortInfo.size()-1; j++) {
            ListEachBook = tSortInfo[j].split(QRegExp("\\s+"),Qt::SkipEmptyParts);
            int secondyear = ListEachBook[4].toInt();
            if(firstyear < secondyear){
                QString temp =  tSortInfo[i];
                tSortInfo[i] = tSortInfo[j];
                tSortInfo[j] = temp;
                firstyear = tSortInfo[i].split(QRegExp("\\s+"), QString::SkipEmptyParts)[4].toInt();

            }

        }
    }

    for (int i = 0; i < tSortInfo.size(); i++) {
        qDebug() << "Sorted tsortInfo" << i << ": "<< tSortInfo[i];

    }


}

void Book::displayAllBook()
{
    QStringList tBookInfo;
    QStringList tSplitBookInfo;
    bookfileObj->readFile();
    tBookInfo.append(bookfileObj->readFile());
    std::cout << "Display All Book:"<< std::endl;
    for (int i = 0; i < tBookInfo.size(); i++) {
        qDebug() << i+1<<"."<<"Book: " << tBookInfo[i];

    }

}


