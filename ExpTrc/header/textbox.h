/*.h file for Textbox class, inherits from QLineEdit*/

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <qlineedit.h>

class Textbox : public QLineEdit
{
	Q_OBJECT

public:
	QRect txtboxSize;

	Textbox(QWidget* parent = Q_NULLPTR);


	void enterEvent(QEvent* Event);
	void leaveEvent(QEvent* Event);
	void focusInEvent(QFocusEvent* Event);
	void focusOutEvent(QFocusEvent* Event);
};


#endif