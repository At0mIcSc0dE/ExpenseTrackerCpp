/*.h file for Window Design functions*/

#ifndef MAINWINDOWDESIGN_H
#define MAINWINDOWDESIGN_H

/*This file contains function responsible for the animation of widgets.
It has two functions which do exactly the same.
However, the first on is intended for RVALUES the second for LVALUES*/

#include <qobject.h>
#include "LoginWindow.h"
#include "MainWindow.h"


template<typename widget>
void QWidgetAnimation(widget* obj, QRect& endValues, unsigned short int mSecTimer, QEvent* Event = nullptr) {
    
    QPropertyAnimation* animation = new QPropertyAnimation(obj, "geometry");

    animation->setStartValue(obj->geometry());
    animation->setEndValue(endValues);
    animation->setDuration(mSecTimer);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}


template<typename widget>
void QWidgetAnimation(widget* obj, QRect&& endValues, unsigned short int&& mSecTimer, QEvent* Event = nullptr) {

    QPropertyAnimation* animation = new QPropertyAnimation(obj, "geometry");

    animation->setStartValue(obj->geometry());
    animation->setEndValue(endValues);
    animation->setDuration(mSecTimer);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}


#endif //MAINWINDOWDESIGN_H

