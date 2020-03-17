/*.cpp file for MainWindow class*/

#include "MainWindow.h"
#include "WindowDesign.h"
#include "Declarations.h"
#include "Config.h"


//GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING


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

    //TODO: Add .json elements into the listobxes on startup!

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
    
    if (msg != nullptr)
        delete msg;
}


void MainWindow::MainListboxInsertion() {
    /*Calls all neccessary functions to add the current element to the listbox
     *Function first gets all info, then checks which checkbox is checked and inserts the info
      into the corresponding listbox.*/

    QString& expName = ui.expNameTxt->text();
    QString& expCategory = ui.comboboxCatInpt->currentText();
    double expPrice = ui.expPriceTxt->text().toDouble();
    short unsigned int expMulti = ui.expMultiTxt->text().toInt();
    QString& expInfo = ui.expInfoTxt->toPlainText();

    if (expName == "" || expPrice == NULL) {
        msg = new QMessageBox(QMessageBox::Icon::Critical, "Failed to add object", "Please enter name and price for your expense!");
        msg->setAttribute(Qt::WA_DeleteOnClose, true);
        msg->show();
        return;
    }

    #pragma region CheckWhichListboxIsChecked

    if (ui.chbOneTime->isChecked()) {
        for (unsigned short int i = 0; i < expMulti; ++i) {
            if (ui.lstbox->ItemInsert(expName, QString::number(expPrice), expMulti)) {
                // ^ TODO --> doesn't check if a user or a group is logged in
                config::exp = Expense(expName, expPrice, expInfo, expMulti, expCategory, USER, ONETIME);
                config::exp.writeExpenseToJson();
            }
        }
    }
    else if (ui.chbMonthly->isChecked()) {
        for (unsigned short int i = 0; i < expMulti; ++i) {
            if (ui.lstboxMonth->ItemInsert(expName, QString::number(expPrice), expMulti)) {
                config::exp = Expense(expName, expPrice, expInfo, expMulti, expCategory, USER, MONTHLY);
                config::exp.writeExpenseToJson();
            }
        }
    }
    else if (ui.chbOneTimeTakings->isChecked()) {
        for (unsigned short int i = 0; i < expMulti; ++i) {
            if (ui.lstboxTakings->ItemInsert(expName, QString::number(expPrice), expMulti)) {
                config::exp = Expense(expName, expPrice, expInfo, expMulti, expCategory, USER, ONETIME_T);
                config::exp.writeExpenseToJson();
            }
        }
    }
    else {
        for (unsigned short int i = 0; i < expMulti; ++i) {
            if (ui.lstboxTakingsMonth->ItemInsert(expName, QString::number(expPrice), expMulti)) {
                config::exp = Expense(expName, expPrice, expInfo, expMulti, expCategory, USER, MONTHLY_T);
                config::exp.writeExpenseToJson();
            }
        }
    }
    #pragma endregion

    ui.expNameTxt->clear();
    ui.expPriceTxt->clear();
    ui.expMultiTxt->setValue(1);
}


void MainWindow::MainListboxDeletion() {
    QListWidgetItem* item;
    short unsigned int expID;
    
    #pragma region CheckListboxFocusAndDeleteItems

    //Deletes item from listbox, .json and updates indices
    switch (config::lstboxFocus) {
    case LSTBOX:
    {
        unsigned short int lstboxIndex = ui.lstbox->currentRow();
        config::json.d["OneTimeExpense"][TOCHARPTR(config::user.userID)].RemoveMember(Value().SetString(TOCHARPTR(lstboxIndex + 1), config::json.alloc));
        ui.lstbox->takeItem(lstboxIndex);
        config::json.updateIndex(TOCHARPTR(config::user.userID), lstboxIndex + 1, "OneTimeExpense", DELEXP);

        break;
    }
    case LSTBOXMONTH:
    {
        unsigned short int lstboxIndex = ui.lstboxMonth->currentRow();
        config::json.d["MonthlyExpense"][TOCHARPTR(config::user.userID)].RemoveMember(Value().SetString(TOCHARPTR(lstboxIndex + 1), config::json.alloc));
        ui.lstboxMonth->takeItem(lstboxIndex);
        config::json.updateIndex(TOCHARPTR(config::user.userID), lstboxIndex + 1, "MonthlyExpense", DELEXP);

        break;
    }
    case LSTBOXTAKINGS:
    {
        unsigned short int lstboxIndex = ui.lstboxTakings->currentRow();
        config::json.d["OneTimeTakings"][TOCHARPTR(config::user.userID)].RemoveMember(Value().SetString(TOCHARPTR(lstboxIndex + 1), config::json.alloc));
        ui.lstboxTakings->takeItem(lstboxIndex);
        config::json.updateIndex(TOCHARPTR(config::user.userID), lstboxIndex + 1, "OneTimeTakings", DELEXP);

        break;
    }
    case LSTBOXTAKINGSMONTH:
    {
        unsigned short int lstboxIndex = ui.lstboxTakingsMonth->currentRow();
        config::json.d["MonthlyTakings"][TOCHARPTR(config::user.userID)].RemoveMember(Value().SetString(TOCHARPTR(lstboxIndex + 1), config::json.alloc));
        ui.lstboxTakingsMonth->takeItem(lstboxIndex);
        config::json.updateIndex(TOCHARPTR(config::user.userID), lstboxIndex + 1, "MonthlyTakings", DELEXP);

        break;
    }
    }

    #pragma endregion

    config::json.write();
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


#pragma region chbHandlers

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

#pragma endregion


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


