/*
@Filename: Book.cpp
implementation of Book

@author: Ykahil
*/
#include "stdafx.h"
#include "Book.h"
#include <string>

// initialize BookID with 0
int Book::_currentBookID = 0;

Book::Book(string name, string author, Genre genre) {
    _bookID = ++_currentBookID;
    _name = name;
    _author = author;
    _genre = genre;
    _borrowed = false;
}

Book::Book() {
    _bookID = ++_currentBookID;
    _name = "BOOK_";
    _author = "";
    _genre = OTHER;
}

string Book::getBookName() {
    return this->_name;
}

string Book::getBookAuthor() {
    return this->_author;
}

Genre Book::getBookGenre() {
    return this->_genre;
}

bool Book::getBorrowed() {
    return this->_borrowed;
}

int Book::getBookID() {
    return this->_bookID;
}

string Book::getDetails() {
    return to_string(_bookID) + " | " + _name + " | " + _author;
}

void Book::setBorrowed() {
    this->_borrowed = true;
}

void Book::setAvailable() {
    this->_borrowed = false;
}

void Book::setBookName(string name) {
    _name = name;
}

void Book::setBookAuthor(string author) {
    _author = author;
}

void Book::setBookGenre(Genre genre) {
    _genre = genre;
}

