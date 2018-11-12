#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#define MENU_COUNT 5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),dis(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenu();
    QPixmap pix;
    pix.load(":/hudie.png");
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->widget_2->setStyleSheet("QWidget#widget_2{border-image:url(:/hudie.png);}");
    resize(pix.size());
    //    setMask(pix.mask());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    menus << "文件" << "编辑" << "构建" << "调试" << "分析" << "工具" << "控件" << "帮助"
          << "欢迎" << "项目" << "设计" ;
    buttons.push_back(ui->pushButton);
    buttons.push_back(ui->pushButton_2);
    buttons.push_back(ui->pushButton_3);
    buttons.push_back(ui->pushButton_4);
    buttons.push_back(ui->pushButton_5);

    for(int i = 0; i <MENU_COUNT; i++){
        buttons[i]->setVisible(false);
        buttons[i]->setFlat(true);//设置按钮透明，不好点击
        pos.push_back(buttons[i]->pos());
        connect(buttons[i],SIGNAL(clicked()),this,SLOT(drawLine1()));
    }

    QVector<int> indexs;

    //根据一级菜单个数设置菜单
    switch(menus.size())
    {
    case 0:
        break;
    case 1:
        buttons[2]->setVisible(true);
        indexs.push_back(2);
        break;
    case 2:
        buttons[1]->setVisible(true);
        buttons[3]->setVisible(true);
        indexs.push_back(1);
        indexs.push_back(3);
        break;
    case 3:
        buttons[1]->setVisible(true);
        buttons[2]->setVisible(true);
        buttons[3]->setVisible(true);
        indexs.push_back(1);
        indexs.push_back(2);
        indexs.push_back(3);
        break;
    case 4:
        buttons[0]->setVisible(true);
        buttons[1]->setVisible(true);
        buttons[2]->setVisible(true);
        buttons[3]->setVisible(true);
        indexs.push_back(0);
        indexs.push_back(1);
        indexs.push_back(2);
        indexs.push_back(3);
        break;
    default:
        buttons[0]->setVisible(true);
        buttons[1]->setVisible(true);
        buttons[2]->setVisible(true);
        buttons[3]->setVisible(true);
        buttons[4]->setVisible(true);
        indexs.push_back(0);
        indexs.push_back(1);
        indexs.push_back(2);
        indexs.push_back(3);
        indexs.push_back(4);
        break;
    }
    setMenuProp(indexs);
    ui->widget->setVisible(false);
}

void MainWindow::setMenuProp(const QVector<int> &indexs)
{
    for(int i = 0 ;i < indexs.size(); i ++)
    {
        buttons.at(indexs[i])->setText(menus.at(i));
        buttons.at(indexs[i])->setProperty("index",indexs[i]);
    }
}

void MainWindow::showWin(){
    this->show();
}

void MainWindow::drawLine1()
{
    points.clear();
    QPushButton* temp = qobject_cast<QPushButton*>(sender());
    //查看该按钮是否含有子菜单，如果没有直接加载窗体
    if(temp->property("index").toInt() == 0)
    {
        points.push_back(QPointF(180,60));
        points.push_back(QPointF(210,40));
        points.push_back(QPointF(320,40));
        ui->widget->move(QPoint(320,10));
    }else if(temp->property("index").toInt() == 1)
    {
        points.push_back(QPointF(190,80));
        points.push_back(QPointF(220,50));
        points.push_back(QPointF(330,50));
        ui->widget->move(QPoint(330,20));
    }
    update();
    ui->widget->setVisible(true);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//去锯齿
    //     painter.setBrush(Qt::blue);
    painter.setPen(QPen(QColor(0x06,0x96,0xb6),2));
    //    painter.drawPixmap(0,0,QPixmap(":/hudie.png"));//
    //    painter.drawLine(QPointF(150,30),QPointF(250,30));
    painter.drawPolyline(points);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //    if(event->button()== Qt::LeftButton)
    //    {
    //        // QPoint temp;
    //        offset=event->globalPos()-pos();
    //        //move(temp);
    //    }
    //    //关闭窗口
    //    else if(event->button()==Qt::RightButton)
    //    {
    //        close();
    //    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //    if(event->buttons()&Qt::LeftButton)
    //    {
    //        QPoint temp;//移动距离
    //        //光标形状
    //        QCursor cursor;
    //        cursor.setShape(Qt::OpenHandCursor);
    //        setCursor(cursor);

    //        temp=event->globalPos()-offset;
    //        move(temp);//指针位置和窗口位置的差值
    //    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //    if(!event->buttons())
    //    {
    //        QCursor cursor;
    //        cursor.setShape(Qt::ArrowCursor);
    //        setCursor(cursor);
    //    }
    //QApplication::restoreOverrideCursor();//恢复鼠标指针
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    int menuNum = menus.size();//一级菜单个数
    if(menuNum >MENU_COUNT)
    {
        //在边界之内(0~muneNum-5)
        if(event->delta()>0){//如果滚轮往上滚
            if(dis >0){
                dis--;
                setMenuAnimation(1);
                changeProp();
            }
        }else{
            if(dis < menuNum-MENU_COUNT)  {
                dis++;
                setMenuAnimation(0);
                changeProp();
            }
        }

    }
}

//0:滚轮向下滚，按钮向上移动 1：滚轮向上滚，按钮向下移动
void MainWindow::setMenuAnimation(int flag)
{
    QVector<QPropertyAnimation*> animations;
    QVector<QPoint> tempPos;
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);

    for(int i = 0 ; i < MENU_COUNT; i++)
    {
        animations.push_back(new QPropertyAnimation(buttons[i],"pos"));
        tempPos.push_back(pos[i]);
    }

    //滚轮向下，按钮向上移动
    if(flag == 0)
    {
        tempPos.push_back(pos[4]+QPoint(-10,20));
        for(int i = 0 ; i < MENU_COUNT; i++)
        {
            int j = i == 0 ? 5 : i;
            animations[i]->setDuration(200+i*10);
            animations[i]->setStartValue(tempPos[j]);
            animations[i]->setEndValue(tempPos[j-1]);
            animations[i]->setEasingCurve(QEasingCurve::Linear);
            group->addAnimation(animations[i]);
        }

        //弹出第一个，然后放在末尾      //根据滚轮滚动方向，重新排列按钮数组
        buttons.push_back(buttons[0]);
        buttons.pop_front();
    }else{
        tempPos.push_front(pos[0]+QPoint(-10,-20));
        for(int i = 0 ; i < MENU_COUNT; i++)
        {
            int j = i==4?0:i+1;
            animations[i]->setDuration(200);
            animations[i]->setStartValue(tempPos[j]);
            animations[i]->setEndValue(tempPos[j+1]);
            animations[i]->setEasingCurve(QEasingCurve::Linear);
            group->addAnimation(animations[i]);
        }

        //弹出末尾，然后放在开头
        buttons.push_front(buttons.at(MENU_COUNT-1));
        buttons.pop_back();
    }
    group->start();
}

void MainWindow::changeProp()
{
    //重新设置QpushButton的属性
    int *index = new int[MENU_COUNT]{0,1,2,3,4};//菜单在菜单数组中的索引
    for(int i = 0; i < 5;i++)
    {
        index[i] += dis;
    }

    for(int i =0;i < MENU_COUNT; i++)
    {
        buttons[i]->setText(menus.at(index[i]));
        buttons[i]->setProperty("index",i);//i为按钮在菜单中的索引
        //设置菜单属性
    }
}
