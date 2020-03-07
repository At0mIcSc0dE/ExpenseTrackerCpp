/*.cpp file for Listbox class*/

#include "Declarations.h"
#include "listbox.h"


Listbox::Listbox(QWidget* parent)
	:QListWidget(parent)
{
	this->installEventFilter(this);
}


Listbox::~Listbox() {
	if(msg != nullptr)
		delete msg;
	}


void Listbox::clearLstFocus(std::array<Listbox*, 3> lstboxes) {
	for (Listbox* lst : lstboxes) {
		lst->clearFocus();
		lst->clearSelection();
	}
}


bool Listbox::ItemInsert(QString& expName, QString& expPrice, short unsigned int expMulti) {

	if (expName.length() + expPrice.length() > 10) {
		msgDEBUG("Length of name and price exceed allowed length! Please shorten your Expense name or Price");
		return false;
	}

	for (int i = 0; i <= expMulti; ++i) {
		this->insertItem(0, expName + " || " + expPrice + QString::fromLocal8Bit(config::currency));
		return true;
	}

	return false;
}
