#include "MainWindow.h"
#include "LoginWindow.h"

#include <qapplication.h>

#include "Database.h"
#include "Declarations.h"

//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES
const std::string folderPath = "D:/Programming/ProgramFiles/ExpenseTracker/";


namespace combobox {
	const char* currency = "€";
}

namespace lstbox {
	short unsigned int lstboxFocus = LSTBOX;
}



int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainWindow win;
	LoginWindow loginWin;

	//DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE
	Database dtbOnce((folderPath + "Expense.db").c_str(), std::string("OneTimeExpenseTable"));
	Database dtbMonth((folderPath + "Expense.db").c_str(), std::string("MonthlyExpenseTable"));
	Database dtbTakings((folderPath + "Expense.db").c_str(), std::string("OneTimeTakingsTable"));
	Database dtbTakingsMonth((folderPath + "Expense.db").c_str(), std::string("MonthlyTakingsTable"));
	Database dtbUser((folderPath + "User.db").c_str(), std::string("User"), USER);
	Database dtbCategory((folderPath + "Category.db").c_str(), std::string("Category"), CATEGORY);


	Records records = dtbOnce.getData("SELECT * FROM OneTimeExpenseTable");
	QString text;
	for (auto& record : records) {
		for (auto& value : record) {
			text.append(value.c_str() + QString("\n"));
		}
	}

	QMessageBox msg;
	msg.setText(text);
	msg.show();

	loginWin.show();
	win.show();
	return app.exec();
}
