/*.h file for all declarations
 *Defines LstboxIndexes
 *Defines USER/GROUP
 *Defines ExpenseTime
 *Defines Debug options
 *Defines global variables*/

#ifndef DECLARATIONS_H
#define DECLARATIONS_H


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

#define ADDEXP 0
#define DELEXP 1

#define msgDEBUG(a) QMessageBox* msg = new QMessageBox();\
                    msg->setAttribute(Qt::WA_DeleteOnClose, true); \
					msg->setText(a);\
					msg->show()


#define TOCHARPTR(a) std::to_string(a).c_str()


#endif //DECLARATIONS_H