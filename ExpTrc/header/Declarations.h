/*.h file for all declarations
 *Defines LstboxIndexes
 *Defines USER/GROUP
 *Defines ExpenseTime
 *Defines Debug options
 *Defines global variables*/

#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <qstring.h>

#define LSTBOX 1
#define LSTBOXMONTH 2
#define LSTBOXTAKINGS 3
#define LSTBOXTAKINGSMONTH 4

#define USER 1
#define GROUP 2

#define ONETIME 1
#define MONTHLY 2
#define ONETIME_T 3
#define MONTHLY_T 4

#define msgDEBUG(a) msg = new QMessageBox; \
					msg->setText(a); \
					msg->show()

#define mmsgDebug(a) QMessageBox* msg = new QMessageBox;\
					 msg->setText(a);\
					 msg->show()



#endif //DECLARATIONS_H