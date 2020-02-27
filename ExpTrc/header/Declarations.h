#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <qstring.h>

#define LSTBOX 1
#define LSTBOXMONTH 2
#define LSTBOXTAKINGS 3
#define LSTBOXTAKINGSMONTH 4
#define msgDEBUG(a) msg = new QMessageBox; \
					msg->setText(a); \
					msg->show()



#endif