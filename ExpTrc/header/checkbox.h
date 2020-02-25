#ifndef CHECKBOX_H
#define CHECKBOC_H


#include <qcheckbox.h>
#include <qmessagebox.h>
#include <array>

class Checkbox : public QCheckBox
{
	Q_OBJECT

public:
	Checkbox(QWidget* parent = Q_NULLPTR);

	void uncheckAny(std::array<Checkbox*, 3> chbs);

protected slots:

signals:


};


#endif