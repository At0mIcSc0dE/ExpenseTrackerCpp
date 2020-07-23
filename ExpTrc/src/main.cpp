/*main file*/

#include "Config.h"
#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>


#include <thread>
#include <locale>
#include <iostream>
#include <filesystem>
#include <tchar.h>

//VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES || VARIABLES

namespace config {
    std::unique_ptr<FileManager> fm;
	MainWindow* win;
}


////Copied from stackoverflow and slightly modified
//bool FindRunningProcess(const wchar_t* process) {
//    /*
//    Function takes in a string value for the process it is looking for like ST3Monitor.exe
//    then loops through all of the processes that are currently running on windows.
//    If the process is found it is running, therefore the function returns true.
//    */
//    bool procRunning = false;
//
//    HANDLE hProcessSnap;
//    PROCESSENTRY32 pe32;
//    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//
//    if (hProcessSnap == INVALID_HANDLE_VALUE) {
//        procRunning = false;
//    }
//    else {
//        pe32.dwSize = sizeof(PROCESSENTRY32);
//        if (Process32First(hProcessSnap, &pe32)) { // Gets first running process
//            if (*pe32.szExeFile == *process) {
//                procRunning = true;
//            }
//            else {
//                // loop through all running processes looking for process
//                while (Process32Next(hProcessSnap, &pe32)) {
//                    if (!wcscmp(pe32.szExeFile, process)) {
//                        procRunning = true;
//                        break;
//                    }
//                }
//            }
//            // clean the snapshot object
//            CloseHandle(hProcessSnap);
//        }
//    }
//
//    return procRunning;
//}



int main(int argc, char* argv[])
{

    //Initialisation of variables
    config::initVariables();


    QApplication app(argc, argv);
    //config::win = new MainWindow(filePath, exeFilePath);
    config::win = new MainWindow;
    LoginWindow loginWin;

    loginWin.show();


    return app.exec();
}