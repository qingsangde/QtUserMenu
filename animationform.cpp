#include "animationform.h"
#include <QDebug>

AnimationForm::AnimationForm(QObject *parent) :
    QObject(parent)
{
    left = (QApplication::desktop()->width() -w.width())/2;
    top = (QApplication::desktop()->height()-w.height())/2;
}

void AnimationForm::showAniamtion()
{
    QPropertyAnimation *anim1 = new QPropertyAnimation(&l,"geometry");
    anim1->setDuration(2000);
    anim1->setStartValue(QRect(left+180,top-150+58,l.width(),0));
    anim1->setEndValue(QRect(left+180,top-l.height()+58,l.width(),l.height()));
    connect(anim1,SIGNAL(finished()),this,SLOT(showMain()));

    QPropertyAnimation *anim = new QPropertyAnimation(&w,"geometry");
    anim->setDuration(3000);
    anim->setStartValue(QRect(left,top,w.width(),0));
    anim->setEndValue(QRect(left,top,w.width(),w.height()));

    QSequentialAnimationGroup group;
    group.addAnimation(anim1);
    group.addAnimation(anim);
    group.start();
    l.show();
}

void AnimationForm::showMain()
{
    w.show();
}

void AnimationForm::showLine()
{
    l.show();
}
