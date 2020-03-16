/*.h file for LoginWindow class, inherits from QDialog*/

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <qdialog.h>
#include <ui_LoginWindow.h>
#include <qpropertyanimation.h>

namespace Ui {
	class LoginWindow;
}

class LoginWindow : public QDialog
{
	Q_OBJECT
public:
	bool successfullLogin;
	LoginWindow(QWidget* parent = Q_NULLPTR);

	~LoginWindow();

public slots:
	bool login();

private:
	Ui::LoginWindow ui;
};



#endif