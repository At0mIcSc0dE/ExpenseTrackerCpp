#ifndef EXPENSE_H
#define EXPENSE_H

#include <qstring.h>

class Expense
{
public:
	QString expName;
	QString expInfo;
	QString category;
	double expPrice;
	unsigned short int expID;
	unsigned short int expMulti;
	unsigned short int expType;

	Expense();
	Expense(QString& expName, double expPrice, QString& expInfo, short unsigned int expMulti, QString& category, short unsigned int loggedInType = 1, short unsigned int expType = 1);
	~Expense();

	void writeExpenseToJson();
	void assignExpID();
};


#endif