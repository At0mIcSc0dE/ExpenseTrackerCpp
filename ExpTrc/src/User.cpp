/*.cpp file for User class*/

#include "User.h"
#include "Config.h"

User::User()
{
	this->userID = 0;
}


bool User::initUser(QString& username, QString& password) {
	this->username = username;
	this->password = password;


	if (exists()) {
		if (hasCorrectLoginInformation()) {
			return true;
		}
		else {
			msgDEBUG("Invalid Username or Password");
		}
	}
	else {
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(0, "User not found", "User does not exist! Do you want to create it?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) {
			registerUser();
			return true;
		}
		else
			exit(0);
	}
	return false;
}


User::~User() {
	
}


bool User::exists() {
	/*checks in .json file if user exists*/

	for (unsigned short int i = 0; i < config::json.d["General"]["userID"].GetInt(); ++i) {
		Value::MemberIterator itrFindUserID = config::json.d["User"].FindMember(Value().SetString(TOCHARPTR(i), config::json.alloc));
		if (itrFindUserID != config::json.d["User"].MemberEnd())
			return true;
	}
	return false;
}


void User::registerUser() {
	this->userID = config::json.d["General"]["userID"].GetInt();

	config::json.d["General"]["userID"] = Value().SetInt(this->userID + 1);
	
	//Add userID to Expense keys
	if(config::json.d["OneTimeExpense"].FindMember(Value().SetString(TOCHARPTR(config::user.userID), config::json.alloc)) == config::json.d["OneTimeExpense"].MemberEnd())
		config::json.d["OneTimeExpense"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);

	if (config::json.d["MonthlyExpense"].FindMember(Value().SetString(TOCHARPTR(config::user.userID), config::json.alloc)) == config::json.d["MonthlyExpense"].MemberEnd())
		config::json.d["MonthlyExpense"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);

	if (config::json.d["OneTimeTakings"].FindMember(Value().SetString(TOCHARPTR(config::user.userID), config::json.alloc)) == config::json.d["OneTimeTakings"].MemberEnd())
		config::json.d["OneTimeTakings"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);

	if (config::json.d["MonthlyTakings"].FindMember(Value().SetString(TOCHARPTR(config::user.userID), config::json.alloc)) == config::json.d["MonthlyTakings"].MemberEnd())
		config::json.d["MonthlyTakings"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);

	Value expTypeID(kObjectType);

	expTypeID.AddMember("OneTimeExpense", 0, config::json.alloc);
	expTypeID.AddMember("MonthlyExpense", 0, config::json.alloc);
	expTypeID.AddMember("OneTimeTakings", 0, config::json.alloc);
	expTypeID.AddMember("MonthlyTakings", 0, config::json.alloc);

	config::json.d["General"]["expID"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), expTypeID, config::json.alloc);

	//Add username and password to .json
	config::json.d["User"][TOCHARPTR(userID)].PushBack(Value().SetString(username.toStdString().c_str(), config::json.alloc), config::json.alloc);
	config::json.d["User"][TOCHARPTR(userID)].PushBack(Value().SetString(password.toStdString().c_str(), config::json.alloc), config::json.alloc);

	config::json.write();

}


bool User::hasCorrectLoginInformation() {
	for (unsigned short int i = 0; i < config::json.d["General"]["userID"].GetInt(); ++i) {
		auto& userInfo = config::json.d["User"][TOCHARPTR(i)].GetArray();
		if (userInfo.Empty())
			return false;

		if (userInfo[0].GetString() == username && userInfo[1].GetString() == password)
			return true;
	}
	return true;
}