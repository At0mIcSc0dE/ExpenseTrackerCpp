#include "Calculator.h"



double Calculator::CalculateExpenses() {
	double CurrentlySpentMoney = 0;
	const GeneralData& gd = config::fm->GetGeneralData();

	for (unsigned int i = 1; i <= gd.CurrOneTimeExpCount; ++i) {

		const ExpenseData expData = config::fm->ReadExpense(i, ONETIME);
		CurrentlySpentMoney += expData.Price;

	}

	for (unsigned int i = 1; i <= gd.CurrMonthlyExpCount; ++i) {

		const ExpenseData expData = config::fm->ReadExpense(i, MONTHLY);
		CurrentlySpentMoney += expData.Price;
	}

	return CurrentlySpentMoney;
}


double Calculator::CalculateIncome() {
	double MoneyGained = 0;
	const GeneralData& gd = config::fm->GetGeneralData();

	for (unsigned int i = 1; i <= gd.CurrOneTimeTakCount; ++i) {
		const ExpenseData expData = config::fm->ReadExpense(i, ONETIME_T);
		MoneyGained += expData.Price;
	}
	
	for (unsigned int i = 1; i <= gd.CurrMonthlyTakCount; ++i) {
		const ExpenseData expData = config::fm->ReadExpense(i, MONTHLY_T);
		MoneyGained += expData.Price;
	}

	return MoneyGained;
}
