#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_olibrary.h"
#include "Library.h"
#include "filter.h"
#include "successdialog.h"
#include "accountdialog.h"

class Olibrary : public QMainWindow
{
    Q_OBJECT

public:
    Olibrary(QWidget *parent = nullptr);
    ~Olibrary();

private:
    Ui::OlibraryClass ui;
    Library& lib;
    User currentUser;

protected:
    /*
     * Sets up the main tables column sizes to a reasonable size depending on 
     * what they represent.
     */
    void setupTableColumns();

    /*
     * Adjusts the size of the table when the window is resized depending
     * on the size of the new window after being resized .
     * 
     * @param event - specifies the resize event
     */
    void resizeEvent(QResizeEvent* event);

    /*
     * Sets up the view books table from the given list of books
     * @param books - specifies the list from which the view books table will represent
     */
    void setupTableFromList(vector<string> books);

private slots:
    /*
     * Displays all the books in the Library instance once the "View All Books" button is pressed, 
     * seperates the details by there splits "|" and places them into their corresponding columns.
     */
    void on_viewAllButton_clicked();

    /*
     * Displays all the available books in the Library instance once the "View Available Books" button is pressed,
     * seperates the details by there splits "|" and places them into their corresponding columns.
     * (Available meaning the book.isborrowed() = false;)
     */
    void on_viewAvailableButton_clicked();

    /*
     * Displays a new window to select the Genre needed then once OK is clicked
     * displays the books with that selected genre in the book table
     */
    void on_viewFilteredButton_clicked();


    /*
     * Adds the Books selected in the book table, if they are available, to the current User's account
     * and refreshes the table
     */
    void on_addButton_clicked();

    /*
     * Opens the current account's account widget with a booktable of owned books and
     * functionality to return the books to the library
     */
    void on_accountButton_clicked();
};
