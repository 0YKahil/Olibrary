#pragma once

#include <QDialog>
#include "ui_filter.h"
#include <string>
#include "book.h"
#include <QString>
class filter : public QDialog, public Ui::filterClass
{
	Q_OBJECT

public:
	filter(QWidget *parent = nullptr);
	~filter();

private:


};
