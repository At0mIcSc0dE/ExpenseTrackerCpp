/*.cpp file for User class*/

#include "User.h"
#include "Config.h"

User::User()
{
	this->userID = "1";
}


bool User::initUser(QString& username, QString& password) {
	this->username = username;
	this->password = password;

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


bool User::hasCorrectLoginInformation() {
	return false;
}