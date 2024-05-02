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
    void setupTableColumns();
    void resizeEvent(QResizeEvent* event);

private slots:
    void on_viewAllButton_clicked();



};
