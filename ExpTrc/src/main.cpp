#include "MainWindow.h"
#include "LoginWindow.h"

#include <qapplication.h>

#include "Database.h"
#include "Declarations.h"

//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES
const std::string folderPath = "D:/Programming/ProgramFiles/ExpenseTracker/";


namespace combobox {
	const char* currency = "€";
}

namespace lstbox {
	short unsigned int lstboxFocus = LSTBOX;
}


//DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE
Database dtbOnce;
Database dtbMonth;
Database dtbTakings;
Database dtbTakingsMonth;
Database dtbUser;
Database dtbCategory;


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainWindow win;
	LoginWindow loginWin;

	//DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE || DATABASE
	dtbOnce = Database((folderPath + "Expense.db").c_str(), std::string("OneTimeExpenseTable"));
	dtbMonth = Database((folderPath + "Expense.db").c_str(), std::string("MonthlyExpenseTable"));
	dtbTakings = Database((folderPath + "Expense.db").c_str(), std::string("OneTimeTakingsTable"));
	dtbTakingsMonth = Database((folderPath + "Expense.db").c_str(), std::string("MonthlyTakingsTable"));
	dtbUser = Database((folderPath + "User.db").c_str(), std::string("User"), USER);
	dtbCategory = Database((folderPath + "Category.db").c_str(), std::string("Category"), CATEGORY);


	loginWin.show();
	win.show();
	return app.exec();
}
