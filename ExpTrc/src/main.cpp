#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "Declarations.h"
#include "JSON.h"


//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES
const std::string folderPath = "D:/Programming/ProgramFiles/ExpenseTracker/";
JSON json("D:/Programming/ProgramFiles/ExpenseTracker/files.json", "{\"OneTimeExpense\": {\"1\": [[]]},\"MonthlyExpense\": {\"1\": [[]]},\"OneTimeTakings\": {\"1\": [[]]},\"MonthlyTakings\": {\"1\": [[]]},\"Group\": {\"1\": [\"admin\", \"admin\"]},\"User\": {\"2\": [\"Simon\", \"123\"]},\"Category\": {\"All\": [\"\", \"\"]}}");
Document::AllocatorType& alloc = json.d.GetAllocator();

namespace combobox {
	const char* currency = "€";
}

namespace lstbox {
	short unsigned int lstboxFocus = LSTBOX;
}

int exists = 1;
//FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS
void writeExpenseToJson(const QString& expName, const QString& expPrice, const unsigned short int expMulti, short unsigned int loggedInType, short unsigned int expType, QString& category = QString::fromLocal8Bit("All"));


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
void writeExpenseToJson(const QString& expName, const QString& expPrice, const unsigned short int expMulti, short unsigned int loggedInType, short unsigned int expType, QString& category) {
	//Takes data and writes it to json

	Value value(kArrayType);
	Value values(kArrayType);
	Value objType(kObjectType);

	for (unsigned short int i = 0; i < expMulti; ++i) {
		//values.PushBack(Value().SetString(expName.toStdString().c_str(), expName.size(), alloc), alloc);
		
	}
	
	//switch(expType) {
	//case ONETIME:



	//	json.d.AddMember("OneTimeExpense", objType, alloc);
	//case MONTHLY:
	//	
	//case ONETIME_T:
	//	
	//case MONTHLY_T:
	//	
	//}

	Value::ConstMemberIterator itr = json.d.FindMember("OneTimeExpense");

	Value OneTimeExp(kObjectType);
	Value UserID(kArrayType);
	Value exp(kArrayType);
	exp.PushBack(Value().SetString(expName.toStdString().c_str(), expName.size(), alloc), alloc);
	exp.PushBack(Value().SetDouble(expPrice.toDouble()), alloc);
	UserID.PushBack(exp, alloc);
	OneTimeExp.AddMember("1", UserID, alloc);
	json.d.AddMember("OneTimeExpense", OneTimeExp, alloc);


	json.write();

}