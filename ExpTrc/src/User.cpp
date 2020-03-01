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

	}
}


User::~User() {
	delete msg;
}


bool User::exists() {
	return false;
}


bool User::hasCorrectLoginInformation() {
	return false;
}