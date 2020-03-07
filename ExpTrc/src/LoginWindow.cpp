/*.cpp file for LoginWindow class*/

#include "LoginWindow.h"
#include "WindowDesign.h"

LoginWindow::LoginWindow(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);

	this->setMaximumSize(280, 400);
	this->setMinimumSize(280, 400);

	ui.loginBtn->installEventFilter(this);
	ui.usernameTxt->installEventFilter(this);
	ui.passwordTxt->installEventFilter(this);

	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(login()));

}


LoginWindow::~LoginWindow() {
	if(animation != nullptr)
		delete animation;
}


bool LoginWindow::login() {
	return false;
}


bool LoginWindow::eventFilter(QObject* watched, QEvent* Event) {
	if (Event->type() == QEvent::FocusIn) {
		if (watched == ui.usernameTxt) {
			QWidgetAnimation(ui.usernameTxt, QRect(-20, 60, 320, 111), 200, Event);
			ui.usernameTxt->setStyleSheet("border-color:  #2ecc71");
		}
		else if (watched == ui.passwordTxt) {
			QWidgetAnimation(ui.passwordTxt, QRect(-20, 150, 320, 111), 200, Event);
			ui.passwordTxt->setStyleSheet("border-color:  #2ecc71");
		}
		return true;
	}
	else if (Event->type() == QEvent::FocusOut) {
		if (watched == ui.usernameTxt) {
			QWidgetAnimation(ui.usernameTxt, QRect(0, 60, 280, 111), 150, Event);
			ui.usernameTxt->setStyleSheet("border: 2px solid #3498db");
		}
		else if (watched == ui.passwordTxt) {
			QWidgetAnimation(ui.passwordTxt, QRect(0, 150, 280, 111), 150, Event);
			ui.passwordTxt->setStyleSheet("border: 2px solid #3498db");
		}
		return true;
	}
	else if (Event->type() == QEvent::HoverEnter) {
		if (watched == ui.loginBtn) {
			QWidgetAnimation(ui.loginBtn, QRect(30, 250, 220, 111), 200, Event);
		}
		else if (watched == ui.usernameTxt) {
			ui.usernameTxt->setStyleSheet("border-color:  #2ecc71");
		}
		else if (watched == ui.passwordTxt) {
			ui.passwordTxt->setStyleSheet("border-color:  #2ecc71");
		}
		return true;
	}
	else if (Event->type() == QEvent::HoverLeave) {
		if (watched == ui.loginBtn) {
			QWidgetAnimation(ui.loginBtn, QRect(50, 250, 180, 111), 150, Event);
		}
		else if (watched == ui.usernameTxt) {
			ui.usernameTxt->setStyleSheet("border: 2px solid #3498db");
		}
		else if (watched == ui.passwordTxt) {
			ui.passwordTxt->setStyleSheet("border: 2px solid #3498db");
		}
		return true;
	}
	return false;
}
