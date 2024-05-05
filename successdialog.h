#pragma once

#include <QDialog>
#include "ui_successdialog.h"

class successDialog : public QDialog, public Ui::successDialogClass
{
	Q_OBJECT

public:
	successDialog(QWidget *parent = nullptr);
	~successDialog();

private:
	 
};
