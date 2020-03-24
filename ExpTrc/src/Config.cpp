/*.cpp file for Declarations.h assigns global variables*/

#include "Config.h"
#include "Declarations.h"


namespace config {
	short unsigned int lstboxFocus = LSTBOX;
	char* currency = "�";
	User user;
	Expense exp;

	void initVariables() {
		json.setPath("D:/Programming/ProgramFiles/ExpenseTracker/Data.json");
		json.setStartDocument("{\"OneTimeExpense\": {},\"MonthlyExpense\": {},\"OneTimeTakings\": {},\"MonthlyTakings\": {},\"Group\": {\"0\": [\"admin\", \"admin\"]},\"User\": {\"0\": []},\"Category\": {\"All\": []}, \"General\": {\"expID\": {}, \"userID\": 0, \"groupID\": 0}}");
	}
}


namespace window {

	void initMainWindow(MainWindow* win) {
		win->show();
	}
}