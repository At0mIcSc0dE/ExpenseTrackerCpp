/*.cpp file for Textbox class*/

#include "textbox.h"
#include "WindowDesign.h"

Textbox::Textbox(QWidget* parent)
	:QLineEdit(parent)
{

}


void Textbox::enterEvent(QEvent* Event) {
	this->setStyleSheet("border-color:  #2ecc71");
}


void Textbox::leaveEvent(QEvent* Event) {
	this->setStyleSheet("border: 2px solid #3498db");
}


void Textbox::focusInEvent(QFocusEvent* Event) {
	QWidgetAnimation(this, QRect(txtboxSize.x() - 20, txtboxSize.y(), txtboxSize.width() + 40, txtboxSize.height()), 200);
}


void Textbox::focusOutEvent(QFocusEvent* Event) {
	QWidgetAnimation(this, txtboxSize, 150);
}