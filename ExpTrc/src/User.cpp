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

	registerUser();

	if (this->exists()) {
		if (this->hasCorrectLoginInformation()) {
			return true;
		}
		else {
			msgDEBUG("Invalid Username or Password");
		}
	}
	else {
		msgDEBUG("User does not exist");
	}
	return false;
}


User::~User() {
	
}


bool User::exists() {
	/*checks in .json file if user exists*/

	if (config::json["User"][userID].IsArray()) {
		return true;
	}

	return false;
}


bool User::registerUser() {
	this->userID = config::json.d["General"]["userID"].GetInt();

	config::json.d["General"]["userID"] = Value().SetInt(this->userID + 1);
	
	//Add userID to Expense keys
	config::json.d["OneTimeExpense"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);
	config::json.d["MonthlyExpense"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);
	config::json.d["OneTimeTakings"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);
	config::json.d["MonthlyTakings"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), Value(kObjectType), config::json.alloc);

	//Value userIDVal(kObjectType);
	Value expTypeID(kObjectType);

	expTypeID.AddMember("OneTimeExpense", 0, config::json.alloc);
	expTypeID.AddMember("MonthlyExpense", 0, config::json.alloc);
	expTypeID.AddMember("OneTimeTakings", 0, config::json.alloc);
	expTypeID.AddMember("MonthlyTakings", 0, config::json.alloc);

	//userIDVal.AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), expTypeID, config::json.alloc);

	config::json.d["General"]["expID"].AddMember(Value().SetString(std::to_string(userID).c_str(), config::json.alloc), expTypeID, config::json.alloc);
	//config::json.d["General"].AddMember("expID", userIDVal, config::json.alloc);

	config::json.write();
	return false;

}


bool User::hasCorrectLoginInformation() {
	return false;
}