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
	//time_t now = time(0);
	//tm* ltm = localtime(&now);




	Value expAttr(kObjectType);
	//Value expIDVal(kObjectType);
	Value userIDVal(kObjectType);

	expAttr.AddMember("expName", Value().SetString(expName.toStdString().c_str(), config::json.alloc), config::json.alloc);
	expAttr.AddMember("expPrice", Value().SetDouble(expPrice), config::json.alloc);

	//expIDVal.AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);

	//userIDVal.AddMember(Value().SetString(std::to_string(expID + 1).c_str(), config::json.alloc), expAttr, config::json.alloc);


	//Value::MemberIterator itrUserID = config::json.d["OneTimeExpense"].FindMember(config::user.userID);
	//if (itrUserID == config::json.d["OneTimeExpense"].MemberEnd()) {
	//	userIDVal.AddMember(Value().SetString(std::to_string(expID + 1).c_str(), config::json.alloc), expAttr, config::json.alloc);
	//	config::json.d["OneTimeExpense"].AddMember(Value().SetString(config::user.userID, config::json.alloc), userIDVal, config::json.alloc);
	//}
	//else
	//	config::json.d["OneTimeExpense"].AddMember(Value().SetString(config::user.userID, config::json.alloc), userIDVal, config::json.alloc);

	//Value::MemberIterator itrExpTime = config::json.d.FindMember("OneTimeExpense");
	//if (itrExpTime == config::json.d.MemberEnd()) {
	//	config::json.d.AddMember("OneTimeExpense", userIDVal, config::json.alloc);
	//}
	//else {
	//	//config::json.d["OneTimeExpense"].AddMember(Value().SetString(config::user.userID, config::json.alloc), userIDVal, config::json.alloc);
	//}


	/*Value valExpID(kObjectType);
	Value valUserID(kObjectType);

	valExpID.AddMember(Value().SetString(config::user.userID, config::json.alloc), expAttr, config::json.alloc);
	
	Value::MemberIterator itrUserID = config::json.d["OneTimeExpense"].FindMember(Value().SetString(config::user.userID, config::json.alloc));
	if (itrUserID == config::json.d["OneTimeExpense"].MemberEnd())
		valUserID.AddMember(Value().SetString(config::user.userID, config::json.alloc), valExpID, config::json.alloc);
	else
		config::json.d["OneTimeExpense"][config::user.userID].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);


	Value::MemberIterator itrExpTime = config::json.d.FindMember("OneTimeExpense");
	if (itrExpTime == config::json.d.MemberEnd())
		config::json.d.AddMember("OneTimeExpense", valUserID, config::json.alloc);
	else {
		config::json.d["OneTimeExpense"].AddMember(Value().SetString(config::user.userID, config::json.alloc), Value().SetString(std::to_string(expID).c_str(), config::json.alloc), config::json.alloc);
	}*/

	//Value expIDVal(kObjectType);
	//expIDVal.AddMember(Value().SetString(expID, config::json.alloc), expAttr, config::json.alloc);
	//config::json.d["OneTimeExpense"].AddMember(Value().SetString(config::user.userID, config::json.alloc), expIDVal, config::json.alloc);

	//userIDVal.AddMember(Value().SetString(config::user.userID, config::json.alloc), expIDVal, config::json.alloc);
	//Value::MemberIterator itrUserID = config::json.d["OneTimeExpense"].FindMember(Value().SetString(config::user.userID, config::json.alloc));
	//if (itrUserID == config::json.d["OneTimeExpense"].MemberEnd()) {
	//	config::json.d["OneTimeExpense"].AddMember(Value().SetString(config::user.userID, config::json.alloc), expIDVal, config::json.alloc);
	//}
	//else {
	//	config::json.d["OneTimeExpense"][config::user.userID].AddMember(Value().SetString(config::user.userID, config::json.alloc), expAttr, config::json.alloc);
	//}

	Value expIdVal(kObjectType);

	expIdVal.AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);

	Value::MemberIterator itrFindUser = config::json.d["OneTimeExpense"].FindMember(Value().SetString(config::user.userID, config::json.alloc));
	if (itrFindUser == config::json.d["OneTimeExpense"].MemberEnd())
		config::json.d["OneTimeExpense"].AddMember(Value().SetString(config::user.userID, config::json.alloc), expIdVal, config::json.alloc);
	else {
		config::json.d["OneTimeExpense"][config::user.userID].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);
		config::json.write();
		config::json.d["OneTimeExpense"][config::user.userID][std::to_string(expID).c_str()].AddMember(Value().SetString(std::to_string(expID).c_str(), config::json.alloc), expAttr, config::json.alloc);
		//config::json.d["OneTimeExpense"][config::user.userID].AddMember(Value().SetString(expID, config::json.alloc), expAttr, config::json.alloc);
	}

	this->expID++;

	config::json.write();
}
