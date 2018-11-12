#ifndef ANIMATIONFORM_H
#define ANIMATIONFORM_H

#include <QObject>
#include "mainwindow.h"
#include "lineform.h"
#include <QApplication>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QDesktopWidget>

class AnimationForm : public QObject
{
    Q_OBJECT
public:
    explicit AnimationForm(QObject *parent = 0);
    void showAniamtion() ;

private:
    int left;
    int top;
    MainWindow w;
    LineForm l;

signals:

public slots:
    void showMain();
    void showLine();
};

#endif // ANIMATIONFORM_H
