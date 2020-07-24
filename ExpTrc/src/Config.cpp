/*.cpp file for Declarations.h assigns global variables*/

#include "Config.h"
#include "Declarations.h"


namespace config {
	short unsigned int lstboxFocus = LSTBOX;
	char* currency = "€";
	Expense exp;

	bool dirExists(const std::string& dirName_in)
	{
		DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
		if (ftyp == INVALID_FILE_ATTRIBUTES)
			return false;  //something is wrong with your path!

		if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
			return true;   // this is a directory!

		return false;    // this is not a directory!
	}

	void initVariables() {
		fm = std::make_unique<FileManager>("\\\\192.168.178.45\\share\\ExpTrc\\OneTimeExpenses.exptrc", "\\\\192.168.178.45\\share\\ExpTrc\\MonthlyExpenses.exptrc", "\\\\192.168.178.45\\share\\ExpTrc\\OneTimeTakings.exptrc", "\\\\192.168.178.45\\share\\ExpTrc\\MonthlyTakings.exptrc", "\\\\192.168.178.45\\share\\ExpTrc\\General.exptrc");
	}
}


namespace window {

	void initMainWindow(MainWindow* win) {
		win->show();
	}
}