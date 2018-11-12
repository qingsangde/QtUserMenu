#ifndef LINEFORM_H
#define LINEFORM_H

#include <QWidget>

class LineForm : public QWidget
{
    Q_OBJECT
public:
    explicit LineForm(QWidget *parent = 0);

private:
    int left;
    int top;

protected:
    void paintEvent(QPaintEvent  *event);

signals:

};

#endif // LINEFORM_H
