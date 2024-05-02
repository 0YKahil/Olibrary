/*
@Filename: Book.h
@author: Ykahil
*/
#pragma once
#include <string>

using namespace std;

enum Genre {
    HORROR, FANTASY, SCI_FI, NON_FICTION, MYSTERY, ROMANCE, OTHER
};


class Book {
public:
    /*
    Constructs a new Book object with a given name, author, genre, automatically assigns
    the next available id to it (book ids begin at 1), and sets its borrowed status to false
    */
    Book(string name, string author, Genre genre);

    /*
    Constructs a new book with defaulted empty name and author and genre other
    */
    Book();

    // getters

    // Returns the ID of the book
    int getBookID();

    // Returns True if the book is borrowed; False otherwise
    bool getBorrowed();

    // Returns the Book name
    string getBookName();

    // Returns the Book author
    string getBookAuthor();

    // Returns the genre of the book, one of HORROR, FANTASY, SCI_FI, NON_FICTION, MYSTERY, ROMANCE, OTHER
    Genre getBookGenre();

    // Returns the details of the book in the form "BookID | BookName | BookAuthor"
    string getDetails();

    // setters
    void setBorrowed();
    void setAvailable();
    void setBookName(string name);
    void setBookAuthor(string author);
    void setBookGenre(Genre genre);


private:
    static int _currentBookID;
    int _bookID;
    bool _borrowed;
    string _name;
    string _author;
    Genre _genre;

};