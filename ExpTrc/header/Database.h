#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite\sqlite3.h>
#include <qmessagebox.h>
#include <string>
#include <vector>
#include "Declarations.h"


#define EXPENSE 1
#define USER 2
#define CATEGORY 3

using Record = std::vector<std::string>;
using Records = std::vector<Record>;

class Database
{
public:

	sqlite3* db;
	const char* path;
	std::string table;
	Records records;

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

	Records getData(const char* sql);

	void enterData(const char* sql);
};


#endif //DATABASE_H