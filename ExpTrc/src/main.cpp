#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "Declarations.h"
#include "JSON.h"


//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES
const std::string folderPath = "D:/Programming/ProgramFiles/ExpenseTracker/";


//FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS


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

	JSON json("D:/Programming/ProgramFiles/ExpenseTracker/jsontest.json");
	
	std::string debug = "";

	Value& val = json.d["OneTimeExpense"]["User1"];
	for (SizeType i = 0; i < val.Size(); ++i) {
		for (SizeType j = 0; j < val[i].Size(); ++j) {

			debug += val[i][j].GetString();
		}
	}

	mmsgDebug(debug.c_str());

	loginWin.show();
	win.show();
	return app.exec();
}



//FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS
