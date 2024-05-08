#pragma once

#include <QDialog>
#include "ui_accountdialog.h"

class accountDialog : public QDialog, public Ui::accountDialogClass
{
	Q_OBJECT

public:
	accountDialog(QWidget *parent = nullptr);
	~accountDialog();

private:
	 
};
