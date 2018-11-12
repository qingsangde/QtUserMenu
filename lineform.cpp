#include "lineform.h"
#include <QPainter>
#include <QBitmap>
#include <QPropertyAnimation>
#include <QApplication>

LineForm::LineForm(QWidget *parent) :
    QWidget(parent)
{
//    ui->setupUi(this);
    QPixmap pix;
    pix.load(":/line.png");
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint|Qt::SubWindow);//设置无边框、无最小化按钮、不再系统任务栏显示
//    this->setAttribute(Qt::WA_TranslucentBackground);
    resize(pix.size());
//    setMask(pix.mask());
}

void LineForm::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/line.png"));//
//    painter.drawLine(QPointF(0,0),QPointF(0,100));
}

