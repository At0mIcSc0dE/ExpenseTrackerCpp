#ifndef TEXTBOX_H
#define TEXTBOX_H


#include <qlineedit.h>

class Textbox : public QLineEdit
{
	Q_OBJECT

public:
	Textbox(QWidget* parent = Q_NULLPTR);
};


#endif