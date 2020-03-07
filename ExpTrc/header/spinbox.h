/*.h file for Spinbox class, inherits from QSpinBox*/

#ifndef SPINBOX_H
#define SPINBOX_H


#include <qspinbox.h>

class Spinbox : public QSpinBox
{
	Q_OBJECT

public:
	QRect spinboxSize;

	Spinbox(QWidget* parent = Q_NULLPTR);


	void enterEvent(QEvent* Event);
	void leaveEvent(QEvent* Event);
	void focusInEvent(QFocusEvent* Event);
	void focusOutEvent(QFocusEvent* Event);
};


#endif