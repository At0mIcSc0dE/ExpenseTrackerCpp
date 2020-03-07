/*.cpp file for Spinbox class*/

#include "spinbox.h"
#include "WindowDesign.h"


Spinbox::Spinbox(QWidget* parent)
	:QSpinBox(parent)
{

}


void Spinbox::enterEvent(QEvent* Event) {
	this->setStyleSheet("border-color:  #2ecc71");
}


void Spinbox::leaveEvent(QEvent* Event) {
	this->setStyleSheet("border: 2px solid #3498db");
}


void Spinbox::focusInEvent(QFocusEvent* Event) {
	QWidgetAnimation(this, QRect(spinboxSize.x() - 20, spinboxSize.y(), spinboxSize.width() + 40, spinboxSize.height()), 200);
}


void Spinbox::focusOutEvent(QFocusEvent* Event) {
	QWidgetAnimation(this, spinboxSize, 150);
}