#include "stdafx.h"
#include "olibrary.h"
#include "filter.h"
#include "successdialog.h"
#include <iostream>

/*
 * lastFilter will remember the last view button clicked and is used
 * for refreshing the book table after removing a book from the library
 * to add it to the account
 * 
 * 0 = viewall, 1 = viewavailable
 */
int lastFilter = 0;

/*
 * Helper Function to convert String to Genre enumeration values
 *
 * @returns: Genre as string
 */
static const Genre stringToGenre(const QString string) {
    if (string == "HORROR") return HORROR;
    else if (string == "FANTASY") return FANTASY;
    else if (string == "SCI-FI") return SCI_FI;
    else if (string == "NON-FICTION") return NON_FICTION;
    else if (string == "MYSTERY") return MYSTERY;
    else if (string == "ROMANCE") return ROMANCE;
    else return OTHER;

}

/*
 * Sets up sample books for the library to use once instantiated
 *
 * @returns: an array of initial books
 */
static vector<Book> setupBooks() {
    vector<Book> initBooks = {
    Book("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", FANTASY),
    Book("It", "Stephen King", HORROR),
    Book("And Then There Were None", "Agatha Christie", MYSTERY),
    Book("Percy Jackson and the Olympians: The Lightning thief", "Rick Riordan", FANTASY),
    Book("Discrete Mathematics with Applications", "Susanna S. Epp", NON_FICTION),
    Book("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", NON_FICTION),
    Book("Frankenstein", "Mary Shelley", SCI_FI),
    Book("Pride and Prejudice", "Jane Austen", ROMANCE),
    Book("The Hobbit", "J. R. R. Tolkien", FANTASY),
    Book("The Lord of the Rings", "J. R. R. Tolkien", FANTASY),
    Book("Dracula", "Bram Stoker", HORROR),
    Book("The Shining", "Stephen King", HORROR),
    Book("Gone Girl", "Gillian Flynn", MYSTERY),
    Book("Murder on the Orient Express", "Agatha Christie", MYSTERY),
    Book("The Love Hypothesis", "Ali Hazelwood", ROMANCE)
    };
    return initBooks;
}

Olibrary::Olibrary(QWidget *parent)
    : QMainWindow(parent), lib(Library::getInstance()), currentUser("admin", "admin")
{
    lib.addBooks(setupBooks());
    lib.getBookByID(15)->setBorrowed();
    lib.getBookByID(14)->setBorrowed();
    lib.getBookByID(13)->setBorrowed();
    ui.setupUi(this);
}

Olibrary::~Olibrary()
{}

void Olibrary::setupTableColumns() {
    int tableWidth = ui.booksTable->width();

    ui.booksTable->setColumnWidth(0, tableWidth * 0.1);
    ui.booksTable->setColumnWidth(1, tableWidth * 0.5);
    ui.booksTable->setColumnWidth(2, tableWidth * 0.2);
    ui.booksTable->setColumnWidth(3, tableWidth * 0.2);
}

void Olibrary::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    setupTableColumns();
}


void Olibrary::setupTableFromList(vector<string> books) {
    vector<string> bookDetails = books;
    ui.booksTable->clearContents();
    ui.booksTable->setRowCount(0); // clear existing rows
    ui.booksTable->setColumnCount(4); // ID, Name, Author, Genre columns

    /* Update headers to show ID, Title, Author, Genre*/
    QStringList headers = { "ID", "Title", "Author", "Genre" };
    ui.booksTable->setHorizontalHeaderLabels(headers);

    for (const auto& details : bookDetails) {
        int row = ui.booksTable->rowCount();
        ui.booksTable->insertRow(row);
        QStringList book = QString::fromStdString(details).split('|');

        // Insert the corresponding details for ID, Name, Author
        for (int col = 0; col < book.size(); ++col) {
            ui.booksTable->setItem(row, col, new QTableWidgetItem(book.at(col).trimmed()));
        }

    }

    setupTableColumns();
    ui.booksTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Olibrary::on_viewAllButton_clicked() {
    setupTableFromList(lib.viewAllBooks());
    lastFilter = 0;
}

void Olibrary::on_viewAvailableButton_clicked() {
    setupTableFromList(lib.viewAvailableBooks());
    lastFilter = 1;
}

void Olibrary::on_viewFilteredButton_clicked() {
    filter filter(this);
    if (filter.exec()) {
        QString genre = filter.selectGenre->currentText();
        std::cout << genre.toStdString() << endl;
        if (genre != "Select Genre...") {
            setupTableFromList(lib.viewFilteredBooks(stringToGenre(genre)));
        }
    }
}

void Olibrary::on_addButton_clicked() {
    QModelIndexList selection = ui.booksTable->selectionModel()->selectedRows();
    bool booksAdded = false;
    for (const QModelIndex& row : selection) {
        QVariant data = row.sibling(row.row(), 0).data();
        int id = data.toInt();
        Book* b = lib.getBookByID(id);
        if (b) {
            currentUser.addBook(b);
            booksAdded = true;
        }
    }

    if (booksAdded) {
        successDialog successdialog(this);
        successdialog.exec();
    }

    if (lastFilter == 1) {
        on_viewAvailableButton_clicked();
    }
    
}


