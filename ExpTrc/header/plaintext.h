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