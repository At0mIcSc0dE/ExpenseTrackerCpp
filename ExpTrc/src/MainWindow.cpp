/*.cpp file for MainWindow class*/

#include "MainWindow.h"
#include "WindowDesign.h"
#include "Declarations.h"
#include "Config.h"


//GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING
void writeExpenseToJson(const QString& expName, const QString& expPrice, const QString& expInfo, const unsigned short int expMulti, short unsigned int loggedInType, short unsigned int expType, QString& category);


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    /*Constructor for MainWindow class
     *Calls setupUi function
     *Sets window size
     *Connects Signals and Slots
     *Sets up eventFilters*/

    ui.setupUi(this);

    //Required to set geometry for every button for animation
    #pragma region SetAnimationGeometry
    ui.addBtn->btnRect = ui.addBtn->geometry();
    ui.deleteBtn->btnRect = ui.deleteBtn->geometry();
    ui.dupBtn->btnRect = ui.dupBtn->geometry();
    ui.clearBtn->btnRect = ui.clearBtn->geometry();
    ui.moreInfoBtn->btnRect = ui.moreInfoBtn->geometry();
    ui.yearGraphBtn->btnRect = ui.yearGraphBtn->geometry();
    ui.monthGraphBtn->btnRect = ui.monthGraphBtn->geometry();

    ui.expNameTxt->txtboxSize = ui.expNameTxt->geometry();
    ui.expPriceTxt->txtboxSize = ui.expPriceTxt->geometry();

    ui.expInfoTxt->plainTxtSize = ui.expInfoTxt->geometry();
    ui.expMultiTxt->spinboxSize = ui.expMultiTxt->geometry();
    #pragma endregion

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
    #pragma region installEventFilter
    ui.lstbox->installEventFilter(this);
    ui.lstboxMonth->installEventFilter(this);
    ui.lstboxTakings->installEventFilter(this);
    ui.lstboxTakingsMonth->installEventFilter(this);
    #pragma endregion

}


MainWindow::~MainWindow() {
    /*Destructor for MainWindow class*/

    if (msg != nullptr) {
        delete msg;
    }
}


void MainWindow::MainListboxInsertion() {
    /*Calls all neccessary functions to add the current element to the listbox
     *Function first gets all info, then checks which checkbox is checked and inserts the info
      into the corresponding listbox.*/

    QString& expName = ui.expNameTxt->text();
    QString& expPrice = ui.expPriceTxt->text();
    short unsigned int expMulti = ui.expMultiTxt->text().toInt();
    QString& expInfo = ui.expInfoTxt->toPlainText();

    if (expName == "" || expPrice == NULL) {
        msg = new QMessageBox(QMessageBox::Icon::Critical, "Failed to add object", "Please enter name and price for your expense!");
        msg->show();
        return;
    }

    #pragma region CheckWhichListboxIsChecked

    if (ui.chbOneTime->isChecked()) {
        if (ui.lstbox->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, ONETIME, ui.comboboxExpCat->currentText()); 
            // ^ TODO --> doesn't check if a user or a group is logged in, nor does it know which category to add it to
        }
    }
    else if (ui.chbMonthly->isChecked()) {
        if (ui.lstboxMonth->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, MONTHLY, ui.comboboxExpCat->currentText());
        }
    }
    else if (ui.chbOneTimeTakings->isChecked()) {
        if (ui.lstboxTakings->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, ONETIME_T, ui.comboboxExpCat->currentText());
        }
    }
    else {
        if (ui.lstboxTakingsMonth->ItemInsert(expName, expPrice, expMulti)) {
            writeExpenseToJson(expName, expPrice, expInfo, expMulti, USER, MONTHLY_T, ui.comboboxExpCat->currentText());
        }
    }
    #pragma endregion

    ui.expNameTxt->clear();
    ui.expPriceTxt->clear();
}


void MainWindow::MainListboxDeletion() {
    QListWidgetItem* item;
    switch (config::lstboxFocus) {
    case LSTBOX:
        item = ui.lstbox->takeItem(ui.lstbox->currentRow());
        delete item;
        break;
    case LSTBOXMONTH:
        item = ui.lstboxMonth->takeItem(ui.lstboxMonth->currentRow());
        delete item;
        break;
    case LSTBOXTAKINGS:
        item = ui.lstboxTakings->takeItem(ui.lstboxTakings->currentRow());
        delete item;
        break;
    case LSTBOXTAKINGSMONTH:
        item = ui.lstboxTakingsMonth->takeItem(ui.lstboxTakingsMonth->currentRow());
        delete item;
        break;
    }
}


bool MainWindow::eventFilter(QObject* watched, QEvent* Event) {
    /*Function determines the listbox focus object, which is neccessary to delete correctly and only allow one selection*/
    
    #pragma region LstboxFocus
    
    if (Event->type() == QEvent::FocusIn) {
        //listbox focus obj
        if (watched == ui.lstbox) {
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
    #pragma endregion

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