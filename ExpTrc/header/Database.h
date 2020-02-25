#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite\sqlite3.h>
#include <qmessagebox.h>
#include <string>


#define EXPENSE 1
#define USER 2
#define CATEGORY 3


class Database
{
public:

	sqlite3* dtb;
	const char* path;
	std::string table;

	//DEBUG
	QMessageBox* msg;
	//DEBUG END

	Database();

	Database(const char* path, std::string& table, short unsigned int dtbType = EXPENSE);
	~Database();

	//DEBUG
	Database(const Database& dtb) {
		msg = new QMessageBox(QMessageBox::Icon::Critical, "Copy", "Database copy constructor called");
		msg->show();
	}
	//DEBUG END

};


#endif //DATABASE_H