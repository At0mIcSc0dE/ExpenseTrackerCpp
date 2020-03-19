/*main file*/

#include "Config.h"
#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "Declarations.h"
#include "JSON.h"

//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES
MainWindow* win;


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