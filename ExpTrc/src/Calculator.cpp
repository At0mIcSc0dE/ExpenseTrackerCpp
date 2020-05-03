#include "Calculator.h"


double Calculator::CurrentlySpentMoney = 0;
double Calculator::MoneyGained = 0;

void Calculator::CalculateRemainingBudget(std::function<void(double&&)> func) {
	
	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["OneTimeExpense"].GetInt(); ++i) {
	
		CurrentlySpentMoney += config::json.d["OneTimeExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

		MoneyGained += config::json.d["OneTimeTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();
		MoneyGained += config::json.d["MonthlyTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

	}

	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["MonthlyExpense"].GetInt(); ++i) {

		CurrentlySpentMoney += config::json.d["MonthlyExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();
	}

	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["MonthlyExpense"].GetInt(); ++i) {
		
		MoneyGained += config::json.d["OneTimeTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

	}

	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["MonthlyExpense"].GetInt(); ++i) {

		MoneyGained += config::json.d["MonthlyTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

	}


	func(MoneyGained - CurrentlySpentMoney);
}


void Calculator::CalculateExpenses(std::function<void(double&&)> func) {
	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["OneTimeExpense"].GetInt(); ++i) {

		CurrentlySpentMoney += config::json.d["OneTimeExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();
		CurrentlySpentMoney += config::json.d["MonthlyExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

		MoneyGained += config::json.d["OneTimeTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();
		MoneyGained += config::json.d["MonthlyTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

	}

	func(MoneyGained - CurrentlySpentMoney);
}


void Calculator::CalculateIncome(std::function<void(double&&)> func) {
	for (unsigned int i = 1; i <= config::json.d["General"]["expID"][TOCHARPTR(config::user.userID)]["OneTimeExpense"].GetInt(); ++i) {

		CurrentlySpentMoney += config::json.d["OneTimeExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();
		CurrentlySpentMoney += config::json.d["MonthlyExpense"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

		MoneyGained += config::json.d["OneTimeTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();
		MoneyGained += config::json.d["MonthlyTakings"][TOCHARPTR(config::user.userID)][TOCHARPTR(config::exp.expID)]["expPrice"].GetDouble();

	}

	func(MoneyGained - CurrentlySpentMoney);
}