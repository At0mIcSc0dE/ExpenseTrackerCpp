/*.cpp file for LoginWindow class*/

#include "LoginWindow.h"
#include "WindowDesign.h"

LoginWindow::LoginWindow(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);

	ui.loginBtn->btnRect = ui.loginBtn->geometry();
	ui.usernameTxt->txtboxSize = ui.usernameTxt->geometry();
	ui.passwordTxt->txtboxSize = ui.passwordTxt->geometry();

	this->setMaximumSize(280, 400);
	this->setMinimumSize(280, 400);

	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(login()));

}


LoginWindow::~LoginWindow() {
	
}


bool LoginWindow::login() {
	return false;
}

