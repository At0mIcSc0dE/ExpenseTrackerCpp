/*main file*/

#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "Declarations.h"
#include "JSON.h"
#include "Config.h"

//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES
const std::string folderPath = "C:/Programming/ProgramFiles/ExpenseTracker/";
MainWindow* win;
//JSON json("D:/Programming/ProgramFiles/ExpenseTracker/files.json", "{\"OneTimeExpense\": {\"1\": []},\"MonthlyExpense\": {\"1\": []},\"OneTimeTakings\": {\"1\": []},\"MonthlyTakings\": {\"1\": []},\"Group\": {\"1\": [\"admin\", \"admin\"]},\"User\": {\"2\": []},\"Category\": {\"All\": []}}");


//FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS


//MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	win = new MainWindow();
	LoginWindow loginWin;
														
	loginWin.show();

	return app.exec();
}