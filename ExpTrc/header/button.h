/*.h file for Button class, inherits from QPushButton*/


#ifndef BUTTON_H
#define BUTTON_H

#include <qpropertyanimation.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include "Declarations.h"

class Button : public QPushButton
{
	Q_OBJECT

public:
	QRect btnRect;

	Button(QWidget* parent = Q_NULLPTR);

	~Button();

	//Events for animation
	void enterEvent(QEvent* Event);

	void leaveEvent(QEvent* Event);
signals:

protected slots:
	
private:
	QMessageBox* msg;
};


#endif