/*.h file for User class, can check if
 *User exists
 *User has correct login info*/

#ifndef USER_H
#define USER_H

#include "Declarations.h"
#include "JSON.h"

extern JSON json;

class User
{
public:
	char* username;
	char* password;
	unsigned int ID;

	User(char* username, char* passwordd);

	~User();

	bool exists();

	bool hasCorrectLoginInformation();

private:
	QMessageBox* msg;
};


#endif