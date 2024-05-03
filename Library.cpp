/*
@Filename: Library.cpp
implementation of Library

@author: Ykahil
*/
#include "stdafx.h"
#include "Library.h"
#include <iostream>
using namespace std;

/*
 * HELPERS
 */


 /*
  * convert string to uppercase
 */
string to_upper(string& in) {
    for (int i = 0; i < in.length(); i++)
        in[i] = in[i] - 'a' + 'A';
    return in;
}

/*
* returns true if s2 contains all the letters in s1
*/
bool containsLetters(string s1, string s2) {
    // chars1 and 2 will contain the characters in s1 and s2 as the key 
    // and the amount of times they appear as the value (starting at 0)
    unordered_map<char, int> chars1 = {};
    unordered_map<char, int> chars2 = {};

    // if char is in the map, increment its count by one, otherwise add it to the map
    for (int i = 0; i < s1.length(); i++) {
        if (chars1.find(s1[i]) != chars1.end()) {
            chars1[s1[i]] += 1;
        }
        chars1.insert({ s1[i], 0 });
    }
    for (int i = 0; i < s2.length(); i++) {
        if (chars2.find(s2[i]) != chars2.end()) {
            chars2[s2[i]] += 1;
        }
        chars2.insert({ s2[i], 0 });
    }

    for (auto it = chars1.begin(); it != chars1.end(); it++) {
        if (chars2.find(it->first) != chars2.end()) {
            if (chars2[it->first] < chars1[it->first]) {
                return false;
            }
        }
        else {
            return false;
        }
    }

    return true;
}

/*
 * END OF HELPERS
 */


Library::Library() {
    _users = {};
    _books = {};
    _bookList = {};
}

void Library::addBook(Book book) {
    _books.insert({ book.getBookID(), book });
    _bookList.push_back(book.getDetails());
}

void Library::addBooks(vector<Book> books) {
    for (Book b : books) {
        this->addBook(b);
    }
}

void Library::addUser(User user) {
    _users.insert({ user.getUserID(), user });
}

void Library::removeUser(User user) {
    _users.erase(user.getUserID());
}

void Library::removeBook(Book book) {
    for (int i = 0; i < _bookList.size(); i++) {
        if (_bookList[i] == book.getDetails()) {
            _bookList.erase(_bookList.begin() + i);
            break;
        }
    }
    _books.erase(book.getBookID());
}

vector<string> Library::viewAllBooks() {
    return this->_bookList;
}


vector<string> Library::viewAvailableBooks() {
    vector<string> books = {};
    for (int i = 1; i <= _books.size(); i++) {
        if (!_books[i].getBorrowed()) {
            books.push_back(_books[i].getDetails());
        }
    }
    return books;
}

vector<string> Library::viewFilteredBooks(Genre genre) {
    vector<string> books = {};
    for (int i = 1; i <= _books.size(); i++) {
        if (_books[i].getBookGenre() == genre) {
            books.push_back(_books[i].getDetails());
        }
    }
    return books;
}

vector<string> Library::viewAvailableFilteredBooks(Genre genre) {
    vector<string> books = {};
    for (int i = 1; i <= _books.size(); i++) {
        if (_books[i].getBookGenre() == genre && !_books[i].getBorrowed()) {
            books.push_back(_books[i].getDetails());
        }
    }
    return books;
}

vector<string> Library::getBookByName(string name) {
    vector<string> books = {};
    string book_name = "";
    for (int i = 1; i <= _books.size(); i++) {
        book_name = _books[i].getBookName();
        if (to_upper(book_name) == to_upper(name)) {
            books.push_back(_books[i].getDetails());
        }
    }
    return books;
}

vector<string> Library::viewBookByAuthor(string author) {
    vector<string> books = {};
    string author_name = "";
    for (int i = 1; i <= _books.size(); i++) {
        author_name = _books[i].getBookAuthor();
        if (to_upper(author_name) == to_upper(author)) {
            books.push_back(_books[i].getDetails());
        }
    }
    return books;
}


unordered_map<int, Book>* Library::getlibBooks() {
    return &_books;
}

unordered_map<string, User>* Library::getUsers() {
    return &_users;
}

Book* Library::getBookByID(int id) {
    return &_books[id];
}

User* Library::getUserByID(string userID) {
    return &_users[userID];
}


