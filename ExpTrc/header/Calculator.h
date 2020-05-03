#pragma once

#include "Config.h"
#include <functional>

struct Calculator {

	static double CurrentlySpentMoney;
	static double MoneyGained;

	static void CalculateRemainingBudget(std::function<void(double&&)> func);
	static void CalculateExpenses(std::function<void(double&&)> func);
	static void CalculateIncome(std::function<void(double&&)> func);

};
