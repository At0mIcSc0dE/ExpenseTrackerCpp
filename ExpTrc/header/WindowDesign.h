#ifndef MAINWINDOWDESIGN_H
#define MAINWINDOWDESIGN_H

#include <qobject.h>
#include "LoginWindow.h"
#include "MainWindow.h"

template<typename widget>
void MainWindow::QWidgetAnimation(widget* obj, QRect endValues, unsigned short int mSecTimer, QEvent* Event) {

    if (Event->type() == QEvent::HoverEnter)
        obj->setStyleSheet("border-color:  #2ecc71");
    else
        obj->setStyleSheet("border: 2px solid #3498db");

    animation = new QPropertyAnimation(obj, "geometry");
    animation->setStartValue(obj->geometry());
    animation->setEndValue(endValues);
    animation->setDuration(mSecTimer);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

template<typename widget>
void LoginWindow::QWidgetAnimation(widget* obj, QRect endValues, unsigned short int mSecTimer, QEvent* Event) {
    if (Event->type() == QEvent::HoverEnter)
        obj->setStyleSheet("border-color:  #2ecc71");
    else
        obj->setStyleSheet("border: 2px solid #3498db");

    animation = new QPropertyAnimation(obj, "geometry");
    animation->setStartValue(obj->geometry());
    animation->setEndValue(endValues);
    animation->setDuration(mSecTimer);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}


#endif //MAINWINDOWDESIGN_H

