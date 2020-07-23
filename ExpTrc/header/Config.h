#ifndef CONFIG_H
#define CONFIG_H

#include "Expense.h"
#include "MainWindow.h"
#include "FileManager.h"

#include <memory>


namespace config {
	extern short unsigned int lstboxFocus;
	extern char* currency;
	//extern JSON json;
	extern std::unique_ptr<FileManager> fm;
	extern Expense exp;
	extern MainWindow* win;
	
	extern bool dirExists(const std::string& dirName_in);

	void initVariables();
}


namespace window {
	extern void initMainWindow(MainWindow* win);
}

#endif //CONFIG_H
