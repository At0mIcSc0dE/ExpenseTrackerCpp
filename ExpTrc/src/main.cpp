/*main file*/

#include "Config.h"
#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "JSON.h"


#include <iostream>

//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES

namespace config {
	JSON json;
	MainWindow* win;
}


//Copied from stackoverflow and slightly modified
bool FindRunningProcess(const wchar_t* process) {
    /*
    Function takes in a string value for the process it is looking for like ST3Monitor.exe
    then loops through all of the processes that are currently running on windows.
    If the process is found it is running, therefore the function returns true.
    */
    bool procRunning = false;

    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        procRunning = false;
    }
    else {
        pe32.dwSize = sizeof(PROCESSENTRY32);
        if (Process32First(hProcessSnap, &pe32)) { // Gets first running process
            if (*pe32.szExeFile == *process) {
                procRunning = true;
            }
            else {
                // loop through all running processes looking for process
                while (Process32Next(hProcessSnap, &pe32)) {
                    if (!wcscmp(pe32.szExeFile, process)) {
                        procRunning = true;
                        break;
                    }
                }
            }
            // clean the snapshot object
            CloseHandle(hProcessSnap);
        }
    }

    return procRunning;
}



//MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION
int main(int argc, char* argv[])
{

    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    bool ProcessRunning = false;

    //WCHAR* process = L"Dropbox.exe";
    const wchar_t process[12] = L"Dropbox.exe";

    if (!FindRunningProcess(process)) {
        if (CreateProcess(L"C:/Program Files (x86)/Dropbox/Client/Dropbox.exe", L"", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
            std::cout << "Stating process...\n";
            WaitForSingleObject(processInfo.hProcess, 10000);
            ProcessRunning = true;
        }
    }
    else {
        std::cout << "Process already Running!\n";
        ProcessRunning = true;
    }

	//Initialisation of variables
	config::initVariables();
	

	QApplication app(argc, argv);
	config::win = new MainWindow(processInfo);
	LoginWindow loginWin;

	if (!ProcessRunning) {
		QMessageBox msgBox;
		msgBox.setText("Failed to connect to Dropbox.");
		msgBox.setWindowTitle("Dropbox failed");
		msgBox.exec();

		return 0;
	}

	loginWin.show();

	return app.exec();
}