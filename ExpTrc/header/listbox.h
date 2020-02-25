#ifndef LISTBOX_H
#define LISTBOX_H


#include <qlistwidget.h>
#include <array>

class Listbox : public QListWidget
{
	Q_OBJECT

public:
	Listbox(QWidget* parent = Q_NULLPTR);

	bool ItemInsert(QString& expName, QString& expPrice, short unsigned int expMulti);

	static void clearLstFocus(std::array<Listbox*, 3> lstboxes);

};


#endif