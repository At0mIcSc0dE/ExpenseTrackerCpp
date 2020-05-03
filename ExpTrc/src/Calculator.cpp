#include "Calculator.h"



double Calculator::CalculateExpenses() {
	double CurrentlySpentMoney = 0;

	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["OneTimeExpense"].GetInt(); ++i) {

		CurrentlySpentMoney += config::json.d["OneTimeExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expPrice"].GetDouble();

	}

	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["MonthlyExpense"].GetInt(); ++i) {

		CurrentlySpentMoney += config::json.d["MonthlyExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expPrice"].GetDouble();

	}

	return CurrentlySpentMoney;
}


double Calculator::CalculateIncome() {
	double MoneyGained = 0;

	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["OneTimeTakings"].GetInt(); ++i) {

		MoneyGained += config::json.d["OneTimeTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expPrice"].GetDouble();

	}
	
	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["MonthlyTakings"].GetInt(); ++i) {

		MoneyGained += config::json.d["MonthlyTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(i)]["expPrice"].GetDouble();

	}

	return MoneyGained;
}