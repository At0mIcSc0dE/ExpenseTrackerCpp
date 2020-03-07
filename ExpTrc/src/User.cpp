/*.cpp file for User class*/

#include "User.h"


User::User(char* username, char* password)
	:username(username), password(password)
{
	if (this->exists()) {
		if (this->hasCorrectLoginInformation()) {

		}
		else {
			msgDEBUG("Invalid Username or Password");
		}
	}
	else {
		msgDEBUG("User does not exist");
	}
}


User::~User() {
	if(msg != nullptr)
		delete msg;
}


bool User::exists() {
	return false;
}


bool User::hasCorrectLoginInformation() {
	return false;
}