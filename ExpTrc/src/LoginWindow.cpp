/*.cpp file for LoginWindow class*/

#include "LoginWindow.h"
#include "WindowDesign.h"
#include "Config.h"


LoginWindow::LoginWindow(QWidget* parent)
	:QDialog(parent), successfullLogin(false)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon("ExpenseTrackerIcon.ico"));

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

	this->close();
	window::initMainWindow(config::win);
	return true;
}

