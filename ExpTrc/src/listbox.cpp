#include "Declarations.h"
#include "listbox.h"


//namespace combobox {
//	//QString& currency;
//	extern const char* currency;
//}


Listbox::Listbox(QWidget* parent)
	:QListWidget(parent)
{
	this->installEventFilter(this);
}


void Listbox::clearLstFocus(std::array<Listbox*, 3> lstboxes) {
	for (Listbox* lst : lstboxes) {
		lst->clearFocus();
		lst->clearSelection();
	}
}


bool Listbox::ItemInsert(QString& expName, QString& expPrice, short unsigned int expMulti) {

	for (int i = 0; i <= expMulti; ++i) {
		this->insertItem(0, expName + " || " + expPrice + QString::fromLocal8Bit(config::currency));
		return true;
	}

	return false;
}
