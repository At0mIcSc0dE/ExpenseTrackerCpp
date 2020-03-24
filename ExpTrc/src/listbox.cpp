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

	if (expName.length() + expPrice.length() > 12) {
		msgDEBUG("Length of name and price exceed allowed length! Please shorten your Expense name or Price");
		return false;
	}

	std::ostringstream streamObj;
	streamObj << std::fixed;
	streamObj << std::setprecision(2);
	streamObj << expPrice.toDouble();

	TIMER("REPAINT TEST");
	//Suspend repaint process
	this->setUpdatesEnabled(false);
	
	//Insert Items
	this->insertItem(0, expName + " || " + streamObj.str().c_str() + QString::fromLocal8Bit(config::currency));

	this->setUpdatesEnabled(true);
	return true;

}
