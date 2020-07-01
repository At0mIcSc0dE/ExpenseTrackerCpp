/*.cpp file for Declarations.h assigns global variables*/

#include "Config.h"
#include "Declarations.h"


namespace config {
	short unsigned int lstboxFocus = LSTBOX;
	char* currency = "€";
	User user;
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
		if (dirExists("D:/dev/ProgramFiles/ExpTrc/"))
			json.setPath("D:/dev/ProgramFiles/ExpTrc/Data.json");
		else if (dirExists("C:/dev/ProgramFiles/ExpTrc/"))
			json.setPath("C:/dev/ProgramFiles/ExpTrc/Data.json");
		
		//json.setPath("D:/dev/ProgramFiles/ExpenseTracker/Data.json");
		json.setStartDocument("{\"OneTimeExpense\": {},\"MonthlyExpense\": {},\"OneTimeTakings\": {},\"MonthlyTakings\": {},\"Group\": {\"0\": [\"admin\", \"admin\"]},\"User\": {\"0\": []},\"Category\": {\"All\": []}, \"General\": {\"expID\": {}, \"userID\": 0, \"groupID\": 0, \"0\": {\"BankBalance\": 0}}}");
	}
}


namespace window {

	void initMainWindow(MainWindow* win) {
		win->show();
	}
}