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
	LoginWindow(QWidget* parent = Q_NULLPTR);

	~LoginWindow();


	template<typename widget>
	void QWidgetAnimation(widget* obj, QRect endValues, unsigned short int mSecTimer, QEvent* Event);

	bool eventFilter(QObject* watched, QEvent* Event);

public slots:
	bool login();

private:
	Ui::LoginWindow ui;
	QPropertyAnimation* animation;
};



#endif