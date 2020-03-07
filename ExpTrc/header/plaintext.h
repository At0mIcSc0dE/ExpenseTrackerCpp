/*.h file for PlainText class, inherits from QPlainTextEdit*/

#ifndef PLAINTEXT_H
#define PLAINTEXT_H


#include <qplaintextedit.h>

class PlainText : public QPlainTextEdit
{
	Q_OBJECT

public:
	PlainText(QWidget* parent = Q_NULLPTR);
};


#endif