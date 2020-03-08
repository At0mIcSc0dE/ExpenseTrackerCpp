#include "Expense.h"
#include "Config.h"

Expense::Expense() {

}


Expense::Expense(QString& expName, double expPrice, QString& expInfo, short unsigned int expMulti, QString& category, short unsigned int loggedInType, short unsigned int expType)
	:expName(expName), expPrice(expPrice), expInfo(expInfo), category(category), expMulti(expMulti), expType(expType)
{

}


Expense::~Expense() {

}


void Expense::writeExpenseToJson() {
	//Takes data and writes it to json
	//ORDER ---> ExpenseID, expName, expPrice, expInfo, Day, Month, Year, UserID, Category
	//TODO -> ExpenseID, Day, Month, Year are not included properly yet

	//Getting time
	time_t now = time(0);
	tm* ltm = localtime(&now);

	for (int i = 0; i < expMulti; ++i) {
		Value inUserLstEntry(kArrayType);
		inUserLstEntry.PushBack(Value().SetInt(expID + 1), config::json.alloc);  //ID
		inUserLstEntry.PushBack(Value().SetString(expName.toStdString().c_str(), config::json.alloc), config::json.alloc);
		inUserLstEntry.PushBack(Value().SetDouble(expPrice), config::json.alloc);
		inUserLstEntry.PushBack(Value().SetString(expInfo.toStdString().c_str(), config::json.alloc), config::json.alloc);
		inUserLstEntry.PushBack(Value().SetString(std::to_string(ltm->tm_mday).c_str(), config::json.alloc), config::json.alloc);
		inUserLstEntry.PushBack(Value().SetString(std::to_string(ltm->tm_mon).c_str(), config::json.alloc), config::json.alloc);
		inUserLstEntry.PushBack(Value().SetString(std::to_string(ltm->tm_year).c_str(), config::json.alloc), config::json.alloc);
		inUserLstEntry.PushBack(Value().SetString(config::user.userID, config::json.alloc), config::json.alloc);
		inUserLstEntry.PushBack(Value().SetString(category.toStdString().c_str(), config::json.alloc), config::json.alloc);


		switch (expType) {
		case ONETIME:
			config::json.addExpMember("OneTimeExpense", "1", inUserLstEntry); //TODO --> Correct User ID
			break;
		case MONTHLY:
			config::json.addExpMember("MonthlyExpense", "1", inUserLstEntry);
			break;
		case ONETIME_T:
			config::json.addExpMember("OneTimeTakings", "1", inUserLstEntry);
			break;
		case MONTHLY_T:
			config::json.addExpMember("MonthlyTakings", "1", inUserLstEntry);
			break;
		}

		config::json.write();
	}
}
