/*.cpp file for Plaintext class*/

#include "plaintext.h"
#include "WindowDesign.h"

PlainText::PlainText(QWidget* parent)
	:QPlainTextEdit(parent) 
{
	
}


void PlainText::enterEvent(QEvent* Event) {
	this->setStyleSheet("border-color:  #2ecc71");
}


void PlainText::leaveEvent(QEvent* Event) {
	this->setStyleSheet("border: 2px solid #3498db");
}


void PlainText::focusInEvent(QFocusEvent* Event) {
	QWidgetAnimation(this, QRect(plainTxtSize.x() - 20, plainTxtSize.y(), plainTxtSize.width() + 40, plainTxtSize.height()), 200);
}


void PlainText::focusOutEvent(QFocusEvent* Event) {
	QWidgetAnimation(this, plainTxtSize, 150);
}