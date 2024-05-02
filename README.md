# Olibrary

## UI version

**Description**:
- The application will act as a library's system which can keep track of books from a 
    Book class (containing the name, genre, and initially empty rating of the book)
    and lend them out for a set amount of time before the book is due to return. The app will also
    ask for a rating once a book is returned and store that in the Book then re-add the book into the Library.
    The library will also separate the books by genre allowing duplicate books. 
    *The application will not connect to a library or any website and books will manually have to be added 
    or generated using the Book class*.


- This version is The UI version of the Library-Management-System project and makes use of Qt to create a GUI for the user to navigate the library.
- source code and any changes to it are in https://github.com/0YKahil/Library-Management-System
- Features include:
   - Login System with Admin or User accounts and their respective privileges connecting them to the database
   - Borrowing Books
   - Viewing Account
   - Viewing Library
   - Filtering Books by genre and availability
   - Saving the state of the library using JSON parsing
To be added:
 - Wishlist
 - Book reccomendation algorithm
 - Review system
 - SQL database and SQL server integration
