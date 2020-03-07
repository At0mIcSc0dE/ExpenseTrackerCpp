/*.h file for MainWindow class, inherits from QMainWindow*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <qmainwindow.h>
#include "ui_MainWindow.h"
#include <qmessagebox.h>
#include <qpropertyanimation.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = Q_NULLPTR);

	~MainWindow();

	//DEBUG
	QMessageBox* msg;
	//DEBUG END

	template<typename widget>
	void QWidgetAnimation(widget* obj, QRect endValues, unsigned short int mSecTimer, QEvent* Event);

protected slots:

	bool eventFilter(QObject* watched, QEvent* Event);

	void MainListboxInsertion();

	void MainListboxDeletion();


	//Checkbox input handler
	void chbOneStateHandler();

	void chbMonthStateHandler();

	void chbOneTakingsStateHandler();

	void chbMonthTakingsStateHandler();



	void on_actionEnglish_toggled(bool);

	void on_actionGerman_toggled(bool);
signals:
	

private:
	Ui::MainWindow ui;
	QPropertyAnimation* animation;
};


#endif