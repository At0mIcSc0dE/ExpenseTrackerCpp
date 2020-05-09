/*main file*/

#include "Config.h"
#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "Declarations.h"
#include "JSON.h"

#include <Windows.h>



//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES

namespace config {
	JSON json;
	MainWindow* win;
}

//FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS || FUNCTIONS


//MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION
int main(int argc, char* argv[])
{

	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	bool ProcessRunning = false;
	
	if (CreateProcess(L"C:/Program Files (x86)/Dropbox/Client/Dropbox.exe", L"", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
		ProcessRunning = true;
		
	}

	//Initialisation of variaables
	config::initVariables();
	

	QApplication app(argc, argv);
	config::win = new MainWindow();
	LoginWindow loginWin;

	if (!ProcessRunning) {
		msgDEBUG("Cannot link to Dropbox");
		return 0;
	}

	loginWin.show();

	return app.exec();
}