/*.cpp file for Button class*/

#include "button.h"
#include "WindowDesign.h"

Button::Button(QWidget* parent)
	:QPushButton(parent)
{

}


Button::~Button() {

}


void Button::enterEvent(QEvent* Event) {
	this->setStyleSheet("border-color:  #2ecc71");
	QWidgetAnimation(this, QRect(btnRect.x() - 20, btnRect.y(), btnRect.width() + 40, btnRect.height()), 200, Event);
}


void Button::leaveEvent(QEvent* Event) {
	this->setStyleSheet("border: 2px solid #3498db");
	QWidgetAnimation(this, btnRect, 150, Event);
}