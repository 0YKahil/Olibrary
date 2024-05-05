/*
@Filename: User.h
@author: Ykahil
*/
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "Book.h"

using namespace std;

class User {
public:
    /*
    Constructs a new user with an empty name, password, books, and provides next id to it
    */
    User();
    /*
    Constructs a new user with given name, password, empty map of books
    and assigns the next available user id to it
    */
    User(string username, string password);

    // getters
    const string getUserID();
    const string getUserName();
    const string getPassword();

    // returns a map of the books currently borrowed by this user, or empty map
    unordered_map<int, Book> getBooks();

    /*
    EFFECTS: returns the names of the books on this account and their authors
    in the format "BookName | BookAuthor" as a vector of type string
    */
    vector<string> getNamesAndAuthors();

    /*
    MODIFIES: this
    EFFECTS: adds given book to books_ with the book id as the key and the book object as the value
    */
    void addBook(Book book);

    // Adds a copy of the book pointer's book to the account and sets the original book to borrowed
    void addBook(Book* book);

    /*
    MODIFIES: this
    EFFECTS: removes given book from _books
    */
    void removeBook(Book book);

    // removes the book with the given id from _books and returns the id
    int removeBook(int id);

private:
    string _userID;
    string _password;
    /*
    Inventory of books is controlled using an unordered_map with the book id
    as the key to speed up the retrieval of a book in large book inventories,
    as well as not allowing 2 books with the same id
    */
    unordered_map<int, Book> _books;

};
