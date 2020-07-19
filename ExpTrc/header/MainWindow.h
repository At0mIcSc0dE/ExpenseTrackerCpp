/*.h file for MainWindow class, inherits from QMainWindow*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <qmainwindow.h>
#include "ui_MainWindow.h"
#include <qmessagebox.h>

#include <Windows.h>
#include <TlHelp32.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(const std::wstring& filePath = L"", const std::wstring& exeFilePath = L"", QWidget* parent = Q_NULLPTR);

	~MainWindow();

protected slots:

	bool eventFilter(QObject* watched, QEvent* Event) override;
	void closeEvent(QCloseEvent* evnt) override;

	void MainListboxInsertion();
	void MainListboxDeletion();
	void UpdateLabels();
	void MonthEndEvents();

	//Checkbox input handler
	void chbOneStateHandler();
	void chbMonthStateHandler();
	void chbOneTakingsStateHandler();
	void chbMonthTakingsStateHandler();
	void MoreInfoButtonPressed();


	void on_actionEnglish_toggled(bool);
	void on_actionGerman_toggled(bool);
signals:
	

private:
	Ui::MainWindow ui;
	QMessageBox* msg;
	QShortcut* ReturnKey;
	const std::wstring& filePath;
	const std::wstring& exeFilePath;
};


#endif