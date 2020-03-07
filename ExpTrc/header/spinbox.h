/*.h file for Spinbox class, inherits from QSpinBox*/

#ifndef SPINBOX_H
#define SPINBOX_H


#include <qspinbox.h>

class Spinbox : public QSpinBox
{
	Q_OBJECT

public:
	Spinbox(QWidget* parent = Q_NULLPTR);
};


#endif