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
	
	switch (expType) {
	case ONETIME:
		this->expID = config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["OneTimeExpense"].GetInt();
		config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["OneTimeExpense"] = Value().SetInt(this->expID + 1);
		break;
	case MONTHLY:
		this->expID = config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["MonthlyExpense"].GetInt();
		config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["MonthlyExpense"] = Value().SetInt(this->expID + 1);
		break;
	case ONETIME_T:
		this->expID = config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["OneTimeTakings"].GetInt();
		config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["OneTimeTakings"] = Value().SetInt(this->expID + 1);
		break;
	case MONTHLY_T:
		this->expID = config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["MonthlyTakings"].GetInt();
		config::json.d["General"]["expID"][std::to_string(config::user.userID).c_str()]["MonthlyTakings"] = Value().SetInt(this->expID + 1);
		break;
	}
	
	config::json.write();
}


void Expense::writeExpenseToJson() {
	//Takes data and writes it to json
	//ORDER ---> expName, expPrice, expInfo, Day, Month, Year, Category
	//TODO -> ExpenseID, Day, Month, Year are not included properly yet

	//Getting current time
	auto& _time = std::chrono::system_clock::now();
	std::time_t time__t = std::chrono::system_clock::to_time_t(_time);
	struct tm* tmp = gmtime(&time__t);

	Value expAttr(kObjectType);

	expAttr.AddMember("expName", Value().SetString(expName.toStdString().c_str(), config::json.alloc), config::json.alloc);
	expAttr.AddMember("expPrice", Value().SetDouble(expPrice), config::json.alloc);
	expAttr.AddMember("expInfo", Value().SetString(expInfo.toStdString().c_str(), config::json.alloc), config::json.alloc);
	expAttr.AddMember("expDay", Value().SetInt(tmp->tm_mday), config::json.alloc);
	expAttr.AddMember("expMonth", Value().SetInt(tmp->tm_mon + 1), config::json.alloc);
	expAttr.AddMember("expYear", Value().SetInt(tmp->tm_year + 1900), config::json.alloc);
	expAttr.AddMember("expCat", Value().SetString(category.toStdString().c_str(), config::json.alloc), config::json.alloc);

	switch (expType) {
	case ONETIME:
		config::json.d["OneTimeExpense"][std::to_string(config::user.userID).c_str()].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);
		break;
	case MONTHLY:
		config::json.d["MonthlyExpense"][std::to_string(config::user.userID).c_str()].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);
		break;
	case ONETIME_T:
		config::json.d["OneTimeTakings"][std::to_string(config::user.userID).c_str()].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);
		break;
	case MONTHLY_T:
		config::json.d["MonthlyTakings"][std::to_string(config::user.userID).c_str()].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);
		break;
	}

	config::json.write();
}
