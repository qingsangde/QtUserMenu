#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPushButton>
#define POINT_COUNT 3;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public  slots:
    void showWin();

protected:
    void paintEvent(QPaintEvent  *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    Ui::MainWindow *ui;
    QPoint offset;
    QPolygonF points;
    int dis;//鼠标滚轮滚动距离标识(0为初始值，向下+1，向上-1)
    QStringList menus;
    QVector<QPushButton*> buttons;
    QVector<QPoint> pos;
    void changeProp();//滚动滚轮后，改变菜单属性
    void setMenuAnimation(int flag);//设置菜单滚动动画
    void initMenu();//根据一级菜单集合 初始化菜单
    void setMenuProp(const QVector<int> &indexs);//设置菜单属性(文本、图标、dllName等属性)


private  slots:
    void drawLine1();

};

#endif // MAINWINDOW_H
