/*.cpp file for Listbox class*/

#include "Config.h"
#include "Declarations.h"
#include "listbox.h"


Listbox::Listbox(QWidget* parent)
	:QListWidget(parent)
{

}


Listbox::~Listbox() {
	
}


void Listbox::clearLstFocus(std::array<Listbox*, 3> lstboxes) {
	for (Listbox* lst : lstboxes) {
		lst->clearFocus();
		lst->clearSelection();
	}
}


bool Listbox::ItemInsert(QString& expName, QString& expPrice, short unsigned int expMulti) {

	if (expName.length() + expPrice.length() > 13) {
		msgDEBUG("Length of name and price exceed allowed length! Please shorten your Expense name or Price");
		return false;
	}

	for (int i = 0; i <= expMulti; ++i) {
		this->insertItem(0, expName + " || " + expPrice + QString::fromLocal8Bit(config::currency));
		return true;
	}

	return false;
}
