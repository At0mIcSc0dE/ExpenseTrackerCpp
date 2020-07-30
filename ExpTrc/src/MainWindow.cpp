/*.cpp file for MainWindow class*/

#include "MainWindow.h"
#include "WindowDesign.h"
#include "Declarations.h"
#include "Config.h"
#include "Calculator.h"
#include <qshortcut.h>

#include <ctime>


//GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING || GLOBAL LINKING


MainWindow::MainWindow(const std::wstring& filePath, const std::wstring& exeFilePath, QWidget* parent)
    : QMainWindow(parent), filePath(filePath), exeFilePath(exeFilePath)
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
    this->setWindowIcon(QIcon("ExpenseTrackerIcon.ico"));

    ReturnKey = new QShortcut(this);
    ReturnKey->setKey(Qt::Key_Return);

    //Check if month is over
    MonthEndEvents();

    //INITIALIZING || INITIALIZING || INITIALIZING || INITIALIZING || INITIALIZING || INITIALIZING
    ui.chbOneTime->setChecked(true);

    ui.lstbox->insertAllItems(ONETIME);
    ui.lstboxMonth->insertAllItems(MONTHLY);
    ui.lstboxTakings->insertAllItems(ONETIME_T);
    ui.lstboxTakingsMonth->insertAllItems(MONTHLY_T);

    ui.lblRemainingBudget->setText(QString("Your remaining Budget: ") + QString::number(Calculator::CalculateIncome() - Calculator::CalculateExpenses()) + QString::fromLocal8Bit(config::currency));
    ui.lblTotalIncome->setText(QString("Your total Income: ") + QString::number(Calculator::CalculateIncome()) + QString::fromLocal8Bit(config::currency));
    ui.lblTotalExpense->setText(QString("Your total Expenses: ") + QString::number(Calculator::CalculateExpenses()) + QString::fromLocal8Bit(config::currency));
    ui.lblRemainingBank->setText(QString("Your bank balance: ") + QString::number(config::fm->GetGeneralData().balance) + QString::fromLocal8Bit(config::currency));

    //CONNECTIONS || CONNECTIONS || CONNECTIONS || CONNECTIONS || CONNECTIONS || CONNECTIONS
    connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(MainListboxInsertion()));
    connect(ui.deleteBtn, SIGNAL(clicked()), this, SLOT(MainListboxDeletion()));
    connect(ui.moreInfoBtn, SIGNAL(clicked()), this, SLOT(MoreInfoButtonPressed()));
    connect(ReturnKey, SIGNAL(activated()), this, SLOT(MainListboxInsertion()));


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


void MainWindow::closeEvent(QCloseEvent* evnt) {

}


void MainWindow::UpdateLabels() {
    //Inneficient I know, updates some labels unnecessarily

    ui.lblRemainingBudget->setText(QString("Your remaining Budget: ") + QString::number(Calculator::CalculateIncome() - Calculator::CalculateExpenses()) + QString::fromLocal8Bit(config::currency));
    ui.lblTotalIncome->setText(QString("Your total Income: ") + QString::number(Calculator::CalculateIncome()) + QString::fromLocal8Bit(config::currency));
    ui.lblTotalExpense->setText(QString("Your total Expenses: ") + QString::number(Calculator::CalculateExpenses()) + QString::fromLocal8Bit(config::currency));
    ui.lblRemainingBank->setText(QString("Your bank balance: ") + QString::number(config::fm->GetGeneralData().balance) + QString::fromLocal8Bit(config::currency));

}


void MainWindow::MonthEndEvents() {

    //@warning Doesn't delete everything and calculates wrong
    auto& _time = std::chrono::system_clock::now();
    std::time_t time__t = std::chrono::system_clock::to_time_t(_time);
    struct tm* tmp = gmtime(&time__t);

    const ExpenseData& expData = config::fm->ReadExpense(1, ONETIME);
    const ExpenseData& takData = config::fm->ReadExpense(1, ONETIME_T);
    //GeneralData gData = config::fm->GetGeneralData();

    short unsigned int lastExpMonth = expData.Month;
    short unsigned int lastTakMonth = takData.Month;

    if (lastExpMonth == 0 || lastTakMonth == 0)
        return;

    bool alreadyCalled = false;

    if (lastExpMonth != 0 && (lastExpMonth < (tmp->tm_mon + 1) || (lastExpMonth == 12 && lastExpMonth > (tmp->tm_mon + 1)))) 
    {
        config::fm->ClearExpenses(ONETIME);
        config::fm->ClearExpenses(ONETIME_T);
        alreadyCalled = true;
    }
    else if (lastTakMonth != 0 && (lastTakMonth < (tmp->tm_mon + 1) || (lastTakMonth == 12 && lastTakMonth > (tmp->tm_mon + 1)))) 
    {
        config::fm->ClearExpenses(ONETIME);
        config::fm->ClearExpenses(ONETIME_T);
    }
    
    GeneralData gd = config::fm->GetGeneralData();
    gd.balance += Calculator::CalculateIncome();
    gd.balance -= Calculator::CalculateExpenses();
    config::fm->WriteGeneral(gd);
}


void MainWindow::MoreInfoButtonPressed() {
    switch (config::lstboxFocus) {
    case LSTBOX:
    {
        unsigned short int lstboxIndex = ui.lstbox->currentRow() + 1;
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex, ONETIME);
        msgDEBUG(QString("Name: ") + QString(expData.Name.c_str()) + QString("\n") + QString("Price: ") + QString::number(expData.Price) + QString::fromLocal8Bit("€") + QString("\n") + QString("Info: ") + QString(expData.Info.c_str()));
        break;
    }
    case LSTBOXMONTH:
    {
        unsigned short int lstboxIndex = ui.lstboxMonth->currentRow() + 1;
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex, MONTHLY);
        msgDEBUG(QString("Name: ") + QString(expData.Name.c_str()) + QString("\n") + QString("Price: ") + QString::number(expData.Price) + QString::fromLocal8Bit("€") + QString("\n") + QString("Info: ") + QString(expData.Info.c_str()));
        break;

    }
    case LSTBOXTAKINGS:
    {
        unsigned short int lstboxIndex = ui.lstboxTakings->currentRow() + 1;
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex, ONETIME_T);
        msgDEBUG(QString("Name: ") + QString(expData.Name.c_str()) + QString("\n") + QString("Price: ") + QString::number(expData.Price) + QString::fromLocal8Bit("€") + QString("\n") + QString("Info: ") + QString(expData.Info.c_str()));
        break;

    }
    case LSTBOXTAKINGSMONTH:
    {
        unsigned short int lstboxIndex = ui.lstboxTakingsMonth->currentRow() + 1;
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex, MONTHLY_T);
        msgDEBUG(QString("Name: ") + QString(expData.Name.c_str()) + QString("\n") + QString("Price: ") + QString::number(expData.Price) + QString::fromLocal8Bit("€") + QString("\n") + QString("Info: ") + QString(expData.Info.c_str()));
        break;

    }
    }
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
            else {
                break;
            }
        }
    }
    else if (ui.chbMonthly->isChecked()) {
        for (unsigned short int i = 0; i < expMulti; ++i) {
            if (ui.lstboxMonth->ItemInsert(expName, QString::number(expPrice), expMulti)) {
                config::exp = Expense(expName, expPrice, expInfo, expMulti, expCategory, USER, MONTHLY);
                config::exp.writeExpenseToJson();
            }
            else {
                break;
            }
        }
    }
    else if (ui.chbOneTimeTakings->isChecked()) {
        for (unsigned short int i = 0; i < expMulti; ++i) {
            if (ui.lstboxTakings->ItemInsert(expName, QString::number(expPrice), expMulti)) {
                config::exp = Expense(expName, expPrice, expInfo, expMulti, expCategory, USER, ONETIME_T);
                config::exp.writeExpenseToJson();
            }
            else {
                break;
            }
        }
    }
    else {
        for (unsigned short int i = 0; i < expMulti; ++i) {
            if (ui.lstboxTakingsMonth->ItemInsert(expName, QString::number(expPrice), expMulti)) {
                config::exp = Expense(expName, expPrice, expInfo, expMulti, expCategory, USER, MONTHLY_T);
                config::exp.writeExpenseToJson();
            }
            else {
                break;
            }
        }
    }
    #pragma endregion

    UpdateLabels();

    ui.expNameTxt->clear();
    ui.expPriceTxt->clear();
    ui.expMultiTxt->setValue(1);
    ui.expInfoTxt->clear();
}


void MainWindow::MainListboxDeletion() {
    QListWidgetItem* item;
    short unsigned int expID;
    
    #pragma region CheckListboxFocusAndDeleteItems

    //Deletes item from listbox, .json and updates indices
    GeneralData gd = config::fm->GetGeneralData();
    
    switch (config::lstboxFocus) {
    case LSTBOX:
    {
        unsigned short int lstboxIndex = ui.lstbox->currentRow();
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex + 1, ONETIME);

        if (expData.Day == 0)
            return;

        gd.CurrOneTimeExpCount -= 1;
        gd.balance += expData.Price;
        config::fm->DeleteExpense(lstboxIndex + 1, ONETIME);
        ui.lstbox->takeItem(lstboxIndex);

        break;
    }
    case LSTBOXMONTH:
    {
        unsigned short int lstboxIndex = ui.lstboxMonth->currentRow();
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex + 1, MONTHLY);

        if (expData.Day == 0)
            return;

        gd.CurrMonthlyExpCount -= 1;
        gd.balance += expData.Price;
        config::fm->DeleteExpense(lstboxIndex + 1, MONTHLY);
        ui.lstboxMonth->takeItem(lstboxIndex);

        break;
    }
    case LSTBOXTAKINGS:
    {
        unsigned short int lstboxIndex = ui.lstboxTakings->currentRow();
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex + 1, ONETIME_T);

        if (expData.Day == 0)
            return;

        gd.CurrOneTimeTakCount -= 1;
        gd.balance -= expData.Price;
        config::fm->DeleteExpense(lstboxIndex + 1, ONETIME_T);
        ui.lstboxTakings->takeItem(lstboxIndex);

        break;
    }
    case LSTBOXTAKINGSMONTH:
    {
        unsigned short int lstboxIndex = ui.lstboxTakingsMonth->currentRow();
        const ExpenseData& expData = config::fm->ReadExpense(lstboxIndex + 1, MONTHLY_T);

        if (expData.Day == 0)
            return;

        gd.CurrMonthlyTakCount -= 1;
        gd.balance -= expData.Price;
        config::fm->DeleteExpense(lstboxIndex + 1, MONTHLY_T);
        ui.lstboxTakingsMonth->takeItem(lstboxIndex);

        break;
    }
    }

    #pragma endregion

    config::fm->WriteGeneral(gd);
    UpdateLabels();
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


