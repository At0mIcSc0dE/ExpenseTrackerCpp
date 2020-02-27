#include "Database.h"



Database::Database() {}


int callback(void* p_data, int num_fields, char** p_fields, char** p_col_names)
{
	Records* records = static_cast<Records*>(p_data);
	try {
		records->emplace_back(p_fields, p_fields + num_fields);
	}
	catch (...) {
		// abort select on failure, don't let exception propogate thru sqlite3 call-stack
		return 1;
	}
	return 0;
}


Records Database::getData(const char* sql) {
	Records records;
	char* errMsg;
	int ret = sqlite3_exec(db, sql, callback, &records, &errMsg);
	if (ret != SQLITE_OK) {
		msgDEBUG("Failed to execute sql statement!");
	}
	return records;
}


Database::Database(const char* path, std::string& table, short unsigned int dtbType)
	:path(path), table(table)
{
	if (sqlite3_open(path, &db) != SQLITE_OK) {
		msgDEBUG("Failed to open Database");
	}
	else {
		if (dtbType == EXPENSE) {
			sqlite3_exec(db, ("CREATE TABLE IF NOT EXISTS " + table + " (ID INTEGER, Expense TEXT, Price INTEGER, MoreInfo TEXT, Day INTEGER, Month INTEGER, Year INTEGER, Username TEXT, Category TEXT, PRIMARY KEY(ID))").c_str(), callback, 0, 0);
		}
		else if (dtbType == USER) {
			sqlite3_exec(db, ("CREATE TABLE IF NOT EXISTS " + table + " (ID INTEGER, Username TEXT, Password TEXT, BankBalance INTEGER, Savings INTEGER, PRIMARY KEY(ID))").c_str(), callback, 0, 0);
		}
		else {
			sqlite3_exec(db, ("CREATE TABLE IF NOT EXISTS " + table + " (ID INTEGER, Name TEXT, Username TEXT, PRIMARY KEY(ID))").c_str(), callback, 0, 0);
		}
	}
}



void Database::enterData(const char* sql) {
	char* zErrMsg;
	int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	
	if (rc != SQLITE_OK) {
		msg = new QMessageBox;
		msg->setText(zErrMsg);
		msg->show();
	}
}


Database::~Database() {
	sqlite3_close(db);
}
