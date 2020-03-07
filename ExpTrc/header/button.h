/*.h file for Button class, inherits from QPushButton*/


#ifndef BUTTON_H
#define BUTTON_H

#include <qpushbutton.h>

class Button : public QPushButton
{
	Q_OBJECT

signals:
	

protected slots:
	

public:
	Button(QWidget* parent = Q_NULLPTR);
};


#endif