#include "MainWindow.h"
#include "WindowDesign.h"
#include "Declarations.h"


//GLOBAL VARIABLE LINKING || GLOBAL VARIABLE LINKING || GLOBAL VARIABLE LINKING || GLOBAL VARIABLE LINKING

void writeExpenseToJson(const QString& expName, const QString& expPrice, const QString& expInfo, const unsigned short int expMulti, short unsigned int loggedInType, short unsigned int expType, QString& category);


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //DESIGN || DESIGN || DESIGN || DESIGN || DESIGN || DESIGN || DESIGN || DESIGN || DESIGN
    this->resize(1200, 680);
    ui.comboboxExpCat->addItem("All");
    ui.comboboxTakCat->addItem("All");
    this->setMaximumSize(1200, 680);
    this->setMinimumSize(1200, 680);

    //INITIALIZING || INITIALIZING || INITIALIZING || INITIALIZING || INITIALIZING || INITIALIZING
    ui.chbOneTime->setChecked(true);

    //CONNECTIONS || CONNECTIONS || CONNECTIONS || CONNECTIONS || CONNECTIONS || CONNECTIONS
    connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(MainListboxInsertion()));
    connect(ui.deleteBtn, SIGNAL(clicked()), this, SLOT(MainListboxDeletion()));


    //Checkbox
    connect(ui.chbOneTime, SIGNAL(clicked()), this, SLOT(chbOneStateHandler()));
    connect(ui.chbMonthly, SIGNAL(clicked()), this, SLOT(chbMonthStateHandler()));
    connect(ui.chbOneTimeTakings, SIGNAL(clicked()), this, SLOT(chbOneTakingsStateHandler()));
    connect(ui.chbMonthlyTakings, SIGNAL(clicked()), this, SLOT(chbMonthTakingsStateHandler()));


    //EVENT FILTERS || EVENT FILTERS || EVENT FILTERS || EVENT FILTERS || EVENT FILTERS
    {
        ui.expNameTxt->installEventFilter(this);
        ui.expPriceTxt->installEventFilter(this);
        ui.expInfoTxt->installEventFilter(this);
        ui.expMultiTxt->installEventFilter(this);
        ui.addBtn->installEventFilter(this);
        ui.deleteBtn->installEventFilter(this);
        ui.dupBtn->installEventFilter(this);
        ui.moreInfoBtn->installEventFilter(this);
        ui.clearBtn->installEventFilter(this);
        ui.monthGraphBtn->installEventFilter(this);
        ui.yearGraphBtn->installEventFilter(this);
        ui.lstbox->installEventFilter(this);
        ui.lstboxMonth->installEventFilter(this);
        ui.lstboxTakings->installEventFilter(this);
        ui.lstboxTakingsMonth->installEventFilter(this);
    }
}


MainWindow::~MainWindow() {
    delete animation;

    //DEBUG
    delete msg;
    //DEBUG END

    delete this;
}


void MainWindow::MainListboxInsertion() {
    QString& expName = ui.expNameTxt->text();
    QString& expPrice = ui.expPriceTxt->text();
    short unsigned int expMulti = ui.expMultiTxt->text().toInt();
    QString& expInfo = ui.expInfoTxt->toPlainText();

    if (expName == "" || expPrice == NULL) {
        msg = new QMessageBox(QMessageBox::Icon::Critical, "Failed to add object", "Please enter name and price for your expense!");
        msg->show();
        return;
    }
    
    if (ui.chbOneTime->isChecked()) {
        if (ui.lstbox->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, ONETIME, ui.comboboxExpCat->currentText()); 
            // ^ TODO --> doesn't check if a user or a group is logged in, nor does it know which category to add it to
            ui.expNameTxt->clear();
            ui.expPriceTxt->clear();
        }
            
    }
    else if (ui.chbMonthly->isChecked()) {
        if (ui.lstboxMonth->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, MONTHLY, ui.comboboxExpCat->currentText());
            ui.expNameTxt->clear();
            ui.expPriceTxt->clear();
        }
    }
    else if (ui.chbOneTimeTakings->isChecked()) {
        if (ui.lstboxTakings->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, ONETIME_T, ui.comboboxExpCat->currentText());
            ui.expNameTxt->clear();
            ui.expPriceTxt->clear();
        }
    }
    else {
        if (ui.lstboxTakingsMonth->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, MONTHLY_T, ui.comboboxExpCat->currentText());
            ui.expNameTxt->clear();
            ui.expPriceTxt->clear();
        }
    }
    
}


void MainWindow::MainListboxDeletion() {
    QListWidgetItem* item;
    switch (config::lstboxFocus) {
    case LSTBOX:
        item = ui.lstbox->takeItem(ui.lstbox->currentRow());
        delete item;
    case LSTBOXMONTH:
        item = ui.lstboxMonth->takeItem(ui.lstboxMonth->currentRow());
        delete item;
    case LSTBOXTAKINGS:
        item = ui.lstboxTakings->takeItem(ui.lstboxTakings->currentRow());
        delete item;
    case LSTBOXTAKINGSMONTH:
        item = ui.lstboxTakingsMonth->takeItem(ui.lstboxTakingsMonth->currentRow());
        delete item;
    }
}


void MainWindow::on_actionGerman_toggled(bool checked) {
    if (checked) {
        ui.actionEnglish->setChecked(false);
    }
    else {
        ui.actionEnglish->setChecked(true);
    }
}


void MainWindow::on_actionEnglish_toggled(bool checked) {
    if (checked) {
        ui.actionGerman->setChecked(false);
    }
    else {
        ui.actionGerman->setChecked(true);
    }
}


bool MainWindow::eventFilter(QObject* watched, QEvent* Event) {
    //Button/Textbox effects
    
    //hover over buttons to trigger animation

    if (Event->type() == QEvent::FocusIn) {

        //buttons
        if (watched == ui.expNameTxt) {
            QWidgetAnimation(ui.expNameTxt, QRect(320, 50, 270, 50), 200, Event);
            ui.expNameTxt->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.expPriceTxt) {
            QWidgetAnimation(ui.expPriceTxt, QRect(600, 50, 270, 50), 200, Event);
            ui.expPriceTxt->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.expInfoTxt) {
            QWidgetAnimation(ui.expInfoTxt, QRect(320, 240, 640, 120), 200, Event);
            ui.expInfoTxt->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.expMultiTxt) {
            QWidgetAnimation(ui.expMultiTxt, QRect(450, 150, 140, 50), 200, Event);
            ui.expMultiTxt->setStyleSheet("border-color:  #2ecc71");
        }

        //listbox focus obj
        else if (watched == ui.lstbox) {
            Listbox::clearLstFocus({ ui.lstboxMonth, ui.lstboxTakings, ui.lstboxTakingsMonth });
            config::lstboxFocus = LSTBOX;
            return true;
        }
        else if (watched == ui.lstboxMonth) {
            Listbox::clearLstFocus({ ui.lstbox, ui.lstboxTakings, ui.lstboxTakingsMonth });
            config::lstboxFocus = LSTBOXMONTH;
            return true;
        }
        else if (watched == ui.lstboxTakings) {
            Listbox::clearLstFocus({ ui.lstboxMonth, ui.lstbox, ui.lstboxTakingsMonth });
            config::lstboxFocus = LSTBOXTAKINGS;
            return true;
        }
        else if (watched == ui.lstboxTakingsMonth) {
            Listbox::clearLstFocus({ ui.lstboxMonth, ui.lstboxTakings, ui.lstbox });
            config::lstboxFocus = LSTBOXTAKINGSMONTH;
            return true;
        }

    }
    else if (Event->type() == QEvent::FocusOut) {
        if (watched == ui.expNameTxt) {
            QWidgetAnimation(ui.expNameTxt, QRect(340, 50, 230, 50), 150, Event);
            ui.expNameTxt->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.expPriceTxt) {
            QWidgetAnimation(ui.expPriceTxt, QRect(620, 50, 230, 50), 150, Event);
            ui.expPriceTxt->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.expInfoTxt) {
            QWidgetAnimation(ui.expInfoTxt, QRect(340, 240, 600, 120), 150, Event);
            ui.expInfoTxt->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.expMultiTxt) {
            QWidgetAnimation(ui.expMultiTxt, QRect(470, 150, 100, 50), 150, Event);
            ui.expMultiTxt->setStyleSheet("border: 2px solid #3498db");
        }
    }

    //buttons
    else if (Event->type() == QEvent::HoverEnter) {
        if (watched == ui.expNameTxt) {
            ui.expNameTxt->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.expPriceTxt) {
            ui.expPriceTxt->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.expInfoTxt) {
            ui.expInfoTxt->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.expMultiTxt) {
            ui.expMultiTxt->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.addBtn) {
            QWidgetAnimation(ui.addBtn, QRect(190, 50, 140, 50), 200, Event);
        }
        else if (watched == ui.deleteBtn) {
            QWidgetAnimation(ui.deleteBtn, QRect(190, 130, 140, 50), 200, Event);
        }
        else if (watched == ui.clearBtn) {
            QWidgetAnimation(ui.clearBtn, QRect(190, 290, 140, 50), 200, Event);
        }
        else if (watched == ui.moreInfoBtn) {
            QWidgetAnimation(ui.moreInfoBtn, QRect(190, 370, 140, 50), 200, Event);
        }
        else if (watched == ui.dupBtn) {
            QWidgetAnimation(ui.dupBtn, QRect(190, 210, 140, 50), 200, Event);
        }
        else if (watched == ui.monthGraphBtn) {
            QWidgetAnimation(ui.monthGraphBtn, QRect(190, 530, 140, 50), 200, Event);
        }
        else if (watched == ui.yearGraphBtn) {
            QWidgetAnimation(ui.yearGraphBtn, QRect(190, 450, 140, 50), 200, Event);
        }
        else if (watched == ui.lstbox) {
            ui.lstbox->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.lstboxMonth) {
            ui.lstboxMonth->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.lstboxTakings) {
            ui.lstboxTakings->setStyleSheet("border-color:  #2ecc71");
        }
        else if (watched == ui.lstboxTakingsMonth) {
            ui.lstboxTakingsMonth->setStyleSheet("border-color:  #2ecc71");
        }
        return true;
    }
    else if (Event->type() == QEvent::HoverLeave) {
        if (watched == ui.expNameTxt) {
            ui.expNameTxt->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.expPriceTxt) {
            ui.expPriceTxt->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.expInfoTxt) {
            ui.expInfoTxt->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.expMultiTxt) {
            ui.expMultiTxt->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.addBtn) {
            QWidgetAnimation(ui.addBtn, QRect(210, 50, 100, 50), 150, Event);
        }
        else if (watched == ui.deleteBtn) {
            QWidgetAnimation(ui.deleteBtn, QRect(210, 130, 100, 50), 150, Event);
        }
        else if (watched == ui.clearBtn) {
            QWidgetAnimation(ui.clearBtn, QRect(210, 290, 100, 50), 150, Event);
        }
        else if (watched == ui.moreInfoBtn) {
            QWidgetAnimation(ui.moreInfoBtn, QRect(210, 370, 100, 50), 150, Event);
        }
        else if (watched == ui.dupBtn) {
            QWidgetAnimation(ui.dupBtn, QRect(210, 210, 100, 50), 150, Event);
        }
        else if (watched == ui.monthGraphBtn) {
            QWidgetAnimation(ui.monthGraphBtn, QRect(210, 530, 100, 50), 150, Event);
        }
        else if (watched == ui.yearGraphBtn) {
            QWidgetAnimation(ui.yearGraphBtn, QRect(210, 450, 100, 50), 150, Event);
        }
        else if (watched == ui.lstbox) {
            ui.lstbox->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.lstboxMonth) {
            ui.lstboxMonth->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.lstboxTakings) {
            ui.lstboxTakings->setStyleSheet("border: 2px solid #3498db");
        }
        else if (watched == ui.lstboxTakingsMonth) {
            ui.lstboxTakingsMonth->setStyleSheet("border: 2px solid #3498db");
        }
        return true;
    }

    return false;
}


void MainWindow::chbOneStateHandler() {
    ui.chbOneTime->uncheckAny({ ui.chbMonthly, ui.chbOneTimeTakings, ui.chbMonthlyTakings });
    ui.chbOneTime->setChecked(true);
}


void MainWindow::chbMonthStateHandler() {
    ui.chbMonthly->uncheckAny({ ui.chbOneTime, ui.chbOneTimeTakings, ui.chbMonthlyTakings });
    ui.chbMonthly->setChecked(true);
}


void MainWindow::chbOneTakingsStateHandler() {
    ui.chbOneTimeTakings->uncheckAny({ ui.chbMonthly, ui.chbOneTime, ui.chbMonthlyTakings });
    ui.chbOneTimeTakings->setChecked(true);
}


void MainWindow::chbMonthTakingsStateHandler() {
    ui.chbMonthlyTakings->uncheckAny({ ui.chbMonthly, ui.chbOneTimeTakings, ui.chbOneTime });
    ui.chbMonthlyTakings->setChecked(true);
}