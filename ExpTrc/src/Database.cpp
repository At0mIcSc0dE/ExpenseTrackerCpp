#include "Database.h"


Database::Database() {}


Database::Database(const char* path, std::string& table, short unsigned int dtbType)
	:path(path), table(table)
{
	sqlite3_open(path, &dtb);
	if (dtbType == EXPENSE) {
		sqlite3_exec(dtb, ("CREATE TABLE IF NOT EXISTS " + table + " (ID INTEGER, Expense TEXT, Price INTEGER, MoreInfo TEXT, Day INTEGER, Month INTEGER, Year INTEGER, Username TEXT, Category TEXT, PRIMARY KEY(ID))").c_str(), 0, 0, 0);
	}
	else if (dtbType == USER) {
		sqlite3_exec(dtb, ("CREATE TABLE IF NOT EXISTS " + table + " (ID INTEGER, Username TEXT, Password TEXT, BankBalance INTEGER, Savings INTEGER, PRIMARY KEY(ID))").c_str(), 0, 0, 0);
	}
	else {
		sqlite3_exec(dtb, ("CREATE TABLE IF NOT EXISTS " + table + " (ID INTEGER, Name TEXT, Username TEXT, PRIMARY KEY(ID))").c_str(), 0, 0, 0);
	}
}


Database::~Database() {
	sqlite3_close(dtb);
}
