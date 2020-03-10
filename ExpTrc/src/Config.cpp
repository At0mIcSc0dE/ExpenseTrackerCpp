/*.cpp file for Declarations.h assigns global variables*/

#include "Config.h"
#include "Declarations.h"

namespace config {
	short unsigned int lstboxFocus = LSTBOX;
	char* currency = "€";
	User user;
	JSON json("D:/Programming/ProgramFiles/ExpenseTracker/files2.json", "{\"OneTimeExpense\": {},\"MonthlyExpense\": {},\"OneTimeTakings\": {},\"MonthlyTakings\": {},\"Group\": {\"1\": [\"admin\", \"admin\"]},\"User\": {\"2\": []},\"Category\": {\"All\": []}}");
	Expense exp;
}