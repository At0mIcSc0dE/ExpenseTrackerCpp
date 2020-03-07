/*.h file for PlainText class, inherits from QPlainTextEdit*/

#ifndef PLAINTEXT_H
#define PLAINTEXT_H


#include <qplaintextedit.h>

class PlainText : public QPlainTextEdit
{
	Q_OBJECT

public:
	QRect plainTxtSize;

	PlainText(QWidget* parent = Q_NULLPTR);


	void enterEvent(QEvent* Event);
	void leaveEvent(QEvent* Event);
	void focusInEvent(QFocusEvent* Event);
	void focusOutEvent(QFocusEvent* Event);
};


#endif