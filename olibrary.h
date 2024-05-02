#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_olibrary.h"

class Olibrary : public QMainWindow
{
    Q_OBJECT

public:
    Olibrary(QWidget *parent = nullptr);
    ~Olibrary();

private:
    Ui::OlibraryClass ui;
};
