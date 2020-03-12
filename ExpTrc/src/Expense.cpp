#include "Expense.h"
#include "Config.h"

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

	if (this->expID == 31032) {
		std::vector<const char*> allKeys;
		for (Value::ConstMemberIterator iter = config::json.d["OneTimeExpense"][config::user.userID].MemberBegin(); iter != config::json.d["OneTimeExpense"][config::user.userID].MemberEnd(); ++iter) {
			allKeys.emplace_back(iter->name.GetString());
		}

		if (allKeys.size() > 0)
			this->expID = std::stoi(allKeys.back()) + 1;
		else
			this->expID = 0;
	}
	else
		this->expID++;
}


void Expense::writeExpenseToJson() {
	//Takes data and writes it to json
	//ORDER ---> ExpenseID, expName, expPrice, expInfo, Day, Month, Year, UserID, Category
	//TODO -> ExpenseID, Day, Month, Year are not included properly yet

	//Getting time
	//time_t now = time(0);
	//tm* ltm = localtime(&now);




	Value expAttr(kObjectType);

	expAttr.AddMember("expName", Value().SetString(expName.toStdString().c_str(), config::json.alloc), config::json.alloc);
	expAttr.AddMember("expPrice", Value().SetDouble(expPrice), config::json.alloc);

	config::json.d["OneTimeExpense"][config::user.userID].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);

	config::json.write();
}
