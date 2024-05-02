#include "stdafx.h"
#include "olibrary.h"
#include <iostream>



Olibrary::Olibrary(QWidget *parent)
    : QMainWindow(parent), lib(Library::getInstance())
{
    lib.addBook(Book("Harry Potter and The Philisopher's Stone", "J.K. Rowling", FANTASY));
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


void Olibrary::on_viewAllButton_clicked() {
    auto bookDetails = lib.viewAllBooks();
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
    // ui.booksTable->resizeColumnsToContents();
    ui.booksTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}



