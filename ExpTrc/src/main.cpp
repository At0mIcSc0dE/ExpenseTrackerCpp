#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "Declarations.h"
#include "JSON.h"


//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES
const std::string folderPath = "D:/Programming/ProgramFiles/ExpenseTracker/";
//JSON json("D:/Programming/ProgramFiles/ExpenseTracker/files.json", "{\"OneTimeExpense\": {\"1\": [[]]},\"MonthlyExpense\": {\"1\": [[]]},\"OneTimeTakings\": {\"1\": [[]]},\"MonthlyTakings\": {\"1\": [[]]},\"Group\": {\"1\": [\"admin\", \"admin\"]},\"User\": {\"2\": [\"Simon\", \"123\"]},\"Category\": {\"All\": [\"\", \"\"]}}");
JSON json("D:/Programming/ProgramFiles/ExpenseTracker/files.json", "{\"OneTimeExpense\": {\"1\": []},\"MonthlyExpense\": {\"1\": []},\"OneTimeTakings\": {\"1\": []},\"MonthlyTakings\": {\"1\": []},\"Group\": {\"1\": [\"admin\", \"admin\"]},\"User\": {\"2\": []},\"Category\": {\"All\": []}}");

namespace combobox {
	const char* currency = "�";
}

namespace lstbox {
	short unsigned int lstboxFocus = LSTBOX;
}

int exists = 1;
//FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS
void writeExpenseToJson(const QString& expName, const QString& expPrice, const QString& expInfo, const unsigned short int expMulti, short unsigned int loggedInType, short unsigned int expType, QString& category = QString::fromLocal8Bit("All"));


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MainWindow win;
	LoginWindow loginWin;
														
	//Value& val = json.d["OneTimeExpense"]["User1"];
	//for (SizeType i = 0; i < val.Size(); ++i) {
	//	for (SizeType j = 0; j < val[i].Size(); ++j) {

	//		debug += val[i][j].GetString() + std::string("\n");
	//	}
	//}


	loginWin.show();
	win.show();
	return app.exec();
}



//FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS || FUNCTION DEFINITIONS
void writeExpenseToJson(const QString& expName, const QString& expPrice, const QString& expInfo, const unsigned short int expMulti, short unsigned int loggedInType, short unsigned int expType, QString& category) {
	//Takes data and writes it to json
	//ORDER ---> expName, expPrice, expInfo, Day, Month, Year, Username, Category
	//TODO -> Day, Month, Year and Username are not included yet

	for (int i = 0; i < expMulti; ++i) {
		Value inUserLstEntry(kArrayType);
		inUserLstEntry.PushBack(Value().SetString(expName.toStdString().c_str(), json.alloc), json.alloc);
		inUserLstEntry.PushBack(Value().SetDouble(expPrice.toDouble()), json.alloc);
		inUserLstEntry.PushBack(Value().SetString(expInfo.toStdString().c_str(), json.alloc), json.alloc);
		inUserLstEntry.PushBack(Value().SetString(category.toStdString().c_str(), json.alloc), json.alloc);


		switch (expType) {
		case ONETIME:
			json.addExpMember("OneTimeExpense", "1", inUserLstEntry); //TODO --> Correct User ID
			break;
		case MONTHLY:
			json.addExpMember("MonthlyExpense", "1", inUserLstEntry);
			break;
		case ONETIME_T:
			json.addExpMember("OneTimeTakings", "1", inUserLstEntry);
			break;
		case MONTHLY_T:
			json.addExpMember("MonthlyTakings", "1", inUserLstEntry);
			break;
		}

		json.write();
	}
}