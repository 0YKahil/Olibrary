#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_olibrary.h"
#include "Library.h"

class Olibrary : public QMainWindow
{
    Q_OBJECT

public:
    Olibrary(QWidget *parent = nullptr);
    ~Olibrary();

private:
    Ui::OlibraryClass ui;
    Library& lib;

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

private slots:
    /*
     * Displays all the books in the Library instance once the "View All Books" button is pressed, 
     * seperates the details by there splits "|" and places them into their corresponding columns.
     */
    void on_viewAllButton_clicked();



};
