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
	short unsigned int expID;
	short unsigned int expMulti;
	short unsigned int expType;

	Expense();
	Expense(QString& expName, double expPrice, QString& expInfo, short unsigned int expMulti, QString& category, short unsigned int loggedInType = 1, short unsigned int expType = 1);
	~Expense();

	void writeExpenseToJson();
};


#endif