/*.cpp file for User class*/

#include "User.h"


User::User()
{
	
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
	return false;
}


bool User::hasCorrectLoginInformation() {
	return false;
}