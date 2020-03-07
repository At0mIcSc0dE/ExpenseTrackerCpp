/*.h file for Window Design functions*/

#ifndef MAINWINDOWDESIGN_H
#define MAINWINDOWDESIGN_H

#include <qobject.h>
#include "LoginWindow.h"
#include "MainWindow.h"

template<typename widget>
void QWidgetAnimation(widget* obj, const QRect& endValues, unsigned short int mSecTimer, QEvent* Event = nullptr) {
    
    QPropertyAnimation* animation = new QPropertyAnimation(obj, "geometry");

    animation->setStartValue(obj->geometry());
    animation->setEndValue(endValues);
    animation->setDuration(mSecTimer);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}


#endif //MAINWINDOWDESIGN_H

