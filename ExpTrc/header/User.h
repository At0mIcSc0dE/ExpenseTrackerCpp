/*.h file for User class, can check if
 *User exists
 *User has correct login info*/

#ifndef USER_H
#define USER_H

#include "Declarations.h"
#include "JSON.h"
#include <array>


class User
{
public:
	QString username;
	QString password;
	unsigned short int userID;

	User();

	~User();

	bool initUser(QString& username, QString& password);
	bool exists();
	bool hasCorrectLoginInformation();
	void registerUser();


private:
	
};


#endif