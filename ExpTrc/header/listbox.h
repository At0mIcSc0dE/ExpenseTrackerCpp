#ifndef LISTBOX_H
#define LISTBOX_H

#include <qmessagebox.h>
#include <qlistwidget.h>
#include <array>

class Listbox : public QListWidget
{
	Q_OBJECT

public:

	Listbox(QWidget* parent = Q_NULLPTR);
	~Listbox();


	bool ItemInsert(QString& expName, double expPrice, short unsigned int expMulti);
	static void clearLstFocus(std::array<Listbox*, 3> lstboxes);

private:

};


#endif