#ifndef CONFIG_H
#define CONFIG_H

#include "User.h"
#include "Expense.h"
#include "MainWindow.h"

namespace config {
	extern short unsigned int lstboxFocus;
	extern char* currency;
	extern User user;
	extern JSON json;
	extern Expense exp;
	extern MainWindow* win;
	
	extern bool dirExists(const std::string& dirName_in);

	void initVariables();
}


namespace window {
	extern void initMainWindow(MainWindow* win);
}

#endif //CONFIG_H
