#ifndef COMBOBOX_H
#define COMBOBOX_H


#include <qcombobox.h>

class Combobox : public QComboBox
{
	Q_OBJECT

public:
	Combobox(QWidget* parent = Q_NULLPTR);

};


#endif