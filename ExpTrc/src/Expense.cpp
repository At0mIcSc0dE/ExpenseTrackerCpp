#include "Expense.h"
#include "Config.h"
#include <chrono>
#include <ctime>


Expense::Expense() {
	
}


Expense::Expense(QString& expName, double expPrice, QString& expInfo, short unsigned int expMulti, QString& category, short unsigned int loggedInType, short unsigned int expType)
	:expName(expName), expPrice(expPrice), expInfo(expInfo), category(category), expMulti(expMulti), expType(expType)
{
	assignExpID();
}


Expense::~Expense() {

}


void Expense::assignExpID() {
	
	GeneralData gData = config::fm->GetGeneralData();
	switch (expType) {
	case ONETIME:
		this->expID = gData.CurrOneTimeExpCount;
		++gData.CurrOneTimeExpCount;
		break;
	case MONTHLY:
		this->expID = gData.CurrMonthlyExpCount;
		++gData.CurrMonthlyExpCount;
		break;
	case ONETIME_T:
		this->expID = gData.CurrOneTimeTakCount;
		++gData.CurrOneTimeTakCount;
		break;
	case MONTHLY_T:
		this->expID = gData.CurrMonthlyTakCount;
		++gData.CurrMonthlyTakCount;
		break;
	}
	config::fm->WriteGeneral(gData);
}


void Expense::correctJsonExpID() {
	//Function will sync expID in .json file to the IDs used in the QListWidget (reverse .json IDs)

	const char* expTime;

	switch (expType) {
	case ONETIME:
		expTime = "OneTimeExpense";
		break;
	case MONTHLY:
		expTime = "MonthlyExpense";
		break;
	case ONETIME_T:
		expTime = "OneTimeTakings";
		break;
	case MONTHLY_T:
		expTime = "MonthlyTakings";
		break;
	}

	//config::json.updateIndex(TOCHARPTR(config::user.userID), 0, expTime, ADDEXP);

}


void Expense::writeExpenseToJson() {
	//Takes data and writes it to json
	//ORDER ---> expName, expPrice, expInfo, Day, Month, Year, Category

	//Getting current time
	auto& _time = std::chrono::system_clock::now();
	std::time_t time__t = std::chrono::system_clock::to_time_t(_time);
	struct tm* tmp = gmtime(&time__t);

	ExpenseData expData = { expName.toStdString(), expPrice, expInfo.toStdString(), tmp->tm_mday, tmp->tm_mon + 1, tmp->tm_year + 1900 };
	GeneralData gd = config::fm->GetGeneralData();

	switch (expType) {
	case ONETIME:
		config::fm->WriteExpense(ONETIME, std::move(expData));
		gd.balance -= expPrice;
		break;
	case MONTHLY:
		config::fm->WriteExpense(MONTHLY, std::move(expData));
		gd.balance -= expPrice;
		break;
	case ONETIME_T:
		config::fm->WriteExpense(ONETIME_T, std::move(expData));
		gd.balance += expPrice;
		break;
	case MONTHLY_T:
		config::fm->WriteExpense(MONTHLY_T, std::move(expData));
		gd.balance += expPrice;
		break;
	}

	config::fm->WriteGeneral(gd);
	correctJsonExpID();
}
