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


void Expense::correctJsonExpID() {
	//Function will sync expID in .json file to the IDs used in the QListWidget (reverse .json IDs)

	const char* expTime;
	std::vector<int> listOfAllIndices;
	for (unsigned int i = 0; i < config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["OneTimeExpense"].GetInt(); ++i) {
		listOfAllIndices.emplace_back(i);
	}

	std::reverse(listOfAllIndices.begin(), listOfAllIndices.end());

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

	for (unsigned int i = 0; i < config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)][expTime].GetInt(); ++i) {
		Value::MemberIterator itrExpID = config::json.d[expTime][TOCHARPTR(config::user.userID)].FindMember(Value().SetString(TOCHARPTR(i), config::json.alloc));

		Value copyAttrVal(kObjectType);
		copyAttrVal.AddMember("expName", Value().SetString(config::json.d[expTime][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expName"].GetString(), config::json.alloc), config::json.alloc);
		copyAttrVal.AddMember("expPrice", Value().SetDouble(config::json.d[expTime][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expPrice"].GetDouble()), config::json.alloc);
		copyAttrVal.AddMember("expInfo", Value().SetString(config::json.d[expTime][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expInfo"].GetString(), config::json.alloc), config::json.alloc);
		copyAttrVal.AddMember("expDay", Value().SetInt(config::json.d[expTime][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expDay"].GetInt()), config::json.alloc);
		copyAttrVal.AddMember("expMonth", Value().SetInt(config::json.d[expTime][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expMonth"].GetInt()), config::json.alloc);
		copyAttrVal.AddMember("expYear", Value().SetInt(config::json.d[expTime][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expYear"].GetInt()), config::json.alloc);
		copyAttrVal.AddMember("expCat", Value().SetString(config::json.d[expTime][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expCat"].GetString(), config::json.alloc), config::json.alloc);

		//Replace member by removing it first and adding it witch the correct index
		config::json.d[expTime][TOCHARPTR(config::user.userID)].RemoveMember(itrExpID);

		config::json.d[expTime][TOCHARPTR(config::user.userID)].AddMember(Value().SetString(TOCHARPTR(i + 1), config::json.alloc), copyAttrVal, config::json.alloc);
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
		config::json.d["OneTimeExpense"][TOCHARPTR(config::user.userID)].AddMember(Value().SetString(TOCHARPTR(0), config::json.alloc), expAttr, config::json.alloc);
		break;
	case MONTHLY:
		config::json.d["MonthlyExpense"][TOCHARPTR(config::user.userID)].AddMember(Value().SetString(TOCHARPTR(0), config::json.alloc), expAttr, config::json.alloc);
		break;
	case ONETIME_T:
		config::json.d["OneTimeTakings"][TOCHARPTR(config::user.userID)].AddMember(Value().SetString(TOCHARPTR(0), config::json.alloc), expAttr, config::json.alloc);
		break;
	case MONTHLY_T:
		config::json.d["MonthlyTakings"][TOCHARPTR(config::user.userID)].AddMember(Value().SetString(TOCHARPTR(0), config::json.alloc), expAttr, config::json.alloc);
		break;
	}

	config::json.write();

	correctJsonExpID();
}
