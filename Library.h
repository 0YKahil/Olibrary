/*
@Filename: Library.h
@author: Ykahil
*/
#pragma once
#include "User.h"
#include <vector>

using namespace std;

class Library {

public:
    static Library& getInstance() {
        static Library instance;
        return instance;
    }

    /*
    * MODIFIES: this
    * EFFECTS: adds a book to the library if its id does not already exist
    */
    void addBook(Book book);

    /*
    * MODIFIES: this
    * EFFECTS: adds a user to the library if its id does not already exist
    */
    void addUser(User user);

    /*
    * MODIFIES: this
    * EFFECTS: removes a book from the library if it exists
    */
    void removeBook(Book book);

    /*
    * MODIFIES: this
    * EFFECTS: removes a user from the library if it exists
    */
    void removeUser(User user);

    /*
    * EFFECTS: returns all the names of the books in the library with their ids
    * in the format ID | NAME | AUTHOR | GENRE
    */
    vector<string> viewAllBooks();

    /*
    * EFFECTS: returns all the names of the non borrowed books in the library with their ids
    * in the format ID | NAME | AUTHOR | GENRE
    */
    vector<string> viewAvailableBooks();

    /*
    * EFFECTS: returns all the names of the books of the given genre in the library with their ids
    * in the format ID | NAME | AUTHOR | GENRE
    */
    vector<string> viewFilteredBooks(Genre genre);

    /*
    * EFFECTS: returns all the names of the available books of the given genre in the library with their ids
    * in the format ID | NAME | AUTHOR
    */
    vector<string> viewAvailableFilteredBooks(Genre genre);

    /*
    * EFFECTS: returns all the books with the given name in the format ID | NAME | AUTHOR | GENRE
    */
    vector<string> getBookByName(string name);

    /*
    * EFFECTS: returns all the books with the given author in the format ID | NAME | AUTHOR | GENRE
    */
    vector<string> viewBookByAuthor(string author);


    // getters

    // EFFECTS: returns a pointer to the map containing all the books in the library system with their id number as the key
    unordered_map<int, Book>* getlibBooks();

    // EFFECTS: returns a pointer to the map containing all the users in the library system with their userID/username as the key
    unordered_map<string, User>* getUsers();

    // EFFECTS: returns a pointer to the book corresponding to the given bookID
    Book* getBookByID(int bookID);

    // EFFECTS: returns a pointer to the user corresponding to the given userID
    User* getUserByID(string userID);

    // TODO: Implement these
    // !!!
    vector<User> getUserByName(string name);

private:
    /*
    * Constructs a library with an empty collection of user accounts and empty library of books
    */
    Library();

    /* Prevent Copying*/
    Library(const Library&);

    unordered_map<string, User> _users;
    unordered_map<int, Book> _books;
    /*
    * Book list is generated at the initialization of the library and is a visual representation of the books
    * in the form "ID | BOOKNAME | AUTHOR". This is to provide a way to view all the books without having to generate
    * the list by iterating over the hashmap each time viewAllBooks() is used (which takes longer as the library gets larger)
    * instead by having a vector that only changes when a book is donated to the library, it will provide a faster way to view
    * all the books with their ids
    */
    vector<string> _bookList;
};