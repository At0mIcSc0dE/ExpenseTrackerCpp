/*.cpp file for Listbox class*/

#include "Config.h"
#include "Declarations.h"
#include "listbox.h"
#include <iomanip>
#include <limits>
#include <sstream>

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


std::pair<const char*, double> _Insert(int i, int expType, QStringList& lst)
{
	ExpenseData expData = config::fm->ReadExpense(i, expType);
	const char* expName = expData.Name.c_str();
	double expPrice = expData.Price;

	std::ostringstream streamObj;
	streamObj << std::fixed;
	streamObj << std::setprecision(2);
	streamObj << expPrice;

	lst.append(QString::fromLocal8Bit((std::string(expName) + " || " + streamObj.str() + "€").c_str()));
	
	return { expName, expPrice };
}


void Listbox::insertAllItems(int expType)
{
	TIMER("");

	const char* expName;
	double expPrice;

	QStringList lst;

	const GeneralData& gd = config::fm->GetGeneralData();
	

	switch (expType)
	{
	case ONETIME:
		for (int i = 1; i <= gd.CurrOneTimeExpCount; ++i)
		{
			_Insert(i, ONETIME, lst);
		}
		break;
	case MONTHLY:
		for (int i = 1; i <= gd.CurrMonthlyExpCount; ++i)
		{
			_Insert(i, MONTHLY, lst);
		}
		break;
	case ONETIME_T:
		for (int i = 1; i <= gd.CurrOneTimeTakCount; ++i)
		{
			_Insert(i, ONETIME_T, lst);
		}
		break;
	case MONTHLY_T:
		for (int i = 1; i <= gd.CurrMonthlyTakCount; ++i)
		{
			_Insert(i, MONTHLY_T, lst);
		}
		break;
	}
	this->insertItems(0, lst);
}

bool Listbox::ItemInsert(QString& expName, QString& expPrice, short unsigned int expMulti) {

	//if (expName.length() + expPrice.length() > 12) {
	//	msgDEBUG("Length of name and price exceed allowed length! Please shorten your Expense name or Price");
	//	return false;
	//}

	std::ostringstream streamObj;
	streamObj << std::fixed;
	streamObj << std::setprecision(2);
	streamObj << expPrice.toDouble();

	TIMER("REPAINT TEST");
	//Suspend repaint process
	//this->setUpdatesEnabled(false);
	
	//Insert Items
	this->insertItem(0, expName + " || " + streamObj.str().c_str() + QString::fromLocal8Bit(config::currency));

	//this->setUpdatesEnabled(true);
	return true;

}
