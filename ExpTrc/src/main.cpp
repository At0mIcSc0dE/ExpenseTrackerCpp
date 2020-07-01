/*main file*/

#include "Config.h"
#include "MainWindow.h"
#include "LoginWindow.h"
#include <qapplication.h>
#include "JSON.h"

#include <thread>
#include <locale>
#include <iostream>
#include <filesystem>
#include <tchar.h>

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
//int main(int argc, char* argv[])
//{
//
//    STARTUPINFO info = { sizeof(info) };
//    PROCESS_INFORMATION processInfo;
//    bool ProcessRunning = false;
//
//    WCHAR* process = L"Dropbox.exe";
//    const wchar_t process[12] = L"Dropbox.exe";
//
//    if (!FindRunningProcess(process)) {
//        if (CreateProcess(L"C:/Program Files (x86)/Dropbox/Client/Dropbox.exe", L"", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo)) {
//            std::cout << "Stating process...\n";
//            WaitForSingleObject(processInfo.hProcess, 10000);
//            ProcessRunning = true;
//        }
//    }
//    else {
//        std::cout << "Process already Running!\n";
//        ProcessRunning = true;
//    }
//
//	//Initialisation of variables
//	config::initVariables();
//	
//
//	QApplication app(argc, argv);
//	config::win = new MainWindow(processInfo);
//	LoginWindow loginWin;
//
//	if (!ProcessRunning) {
//		QMessageBox msgBox;
//		msgBox.setText("Failed to connect to Dropbox.");
//		msgBox.setWindowTitle("Dropbox failed");
//		msgBox.exec();
//
//		return 0;
//	}
//
//	loginWin.show();
//
//	return app.exec();
//}


int main(int argc, char* argv[])
{

    enum class InstallLocation
    {
        CDrive = 0, DDrive
    };

    InstallLocation installLocation = InstallLocation::DDrive;

    setlocale(LC_CTYPE, "");
    std::wstring filePath = L"D:/dev/ProgramFiles/ExpTrc/";

    if (!config::dirExists(std::string(filePath.begin(), filePath.end())))
    {
        filePath = L"C:/dev/ProgramFiles/ExpTrc/";
        installLocation = InstallLocation::CDrive;
    }


    std::wstring exeFilePath;
#ifdef RELEASE
    if (installLocation == InstallLocation::DDrive)
        exeFilePath = L"D:\\Applications\\ExpenseTracker";
    else
        exeFilePath = L"C:\\ProgramFiles (x86)\\ExpenseTracker";
#elif defined(DEBUG)
    if (installLocation == InstallLocation::DDrive)
        exeFilePath = L"D:\\Applications\\ExpenseTracker";
    else
        exeFilePath = L"C:\\ProgramFiles (x86)\\ExpenseTracker";
#else
    #error "Could not find .exe file for credentials.json"
#endif

    SHELLEXECUTEINFO ShExecInfo;
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    
    auto wstr = exeFilePath + std::wstring(L"\\GoogleDriveFileManager\\DownloadFiles\\DownloadDriveFiles.exe");
    ShExecInfo.lpFile = wstr.c_str();

    ShExecInfo.lpParameters = (filePath + L"Data.json").c_str();
    ShExecInfo.lpDirectory = exeFilePath.c_str();
    ShExecInfo.nShow = 0;   //SW_SHOW to show, 0 to hide
    ShExecInfo.hInstApp = NULL;

    ShellExecuteEx(&ShExecInfo);
    WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
    CloseHandle(ShExecInfo.hProcess);

    //Initialisation of variables
    config::initVariables();


    QApplication app(argc, argv);
    config::win = new MainWindow(filePath, exeFilePath);
    LoginWindow loginWin;

    loginWin.show();


    return app.exec();
}