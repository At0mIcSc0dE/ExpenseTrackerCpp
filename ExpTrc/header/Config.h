#ifndef CONFIG_H
#define CONFIG_H

#include "User.h"
#include "Expense.h"

namespace config {
	extern short unsigned int lstboxFocus;
	extern char* currency;
	extern User user;
	extern JSON json;
	extern Expense exp;
}
#endif //CONFIG_H
