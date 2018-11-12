#include "mainwindow.h"
#include "lineform.h"
#include <QApplication>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QDesktopWidget>
#include "animationform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //效果1


    MainWindow w;
    LineForm l(qobject_cast<QWidget*>(&w));
    int left = (QApplication::desktop()->width() -w.width())/2;
    int top = (QApplication::desktop()->height()-w.height())/2;

    QPropertyAnimation *anim = new QPropertyAnimation(&w,"pos");
    anim->setDuration(2000);
    anim->setStartValue(QPoint(left,top-150));
    anim->setEndValue(QPoint(left,top));

    QPropertyAnimation *anim1 = new QPropertyAnimation(&l,"geometry");
    anim1->setDuration(2000);
//    anim1->setStartValue(QRect(left+60,top-150+70,l.width(),0));
//    anim1->setEndValue(QRect(left+60,top-l.height()+70,l.width(),l.height()));
    anim1->setStartValue(QRect(70,70,l.width(),0));
    anim1->setEndValue(QRect(70,70-121,l.width(),l.height()));

    QParallelAnimationGroup group;
    group.addAnimation(anim);
    group.addAnimation(anim1);
    group.start();
    l.show();
    w.show();

//    AnimationForm form;
//    form.showAniamtion();

    return a.exec();
}
