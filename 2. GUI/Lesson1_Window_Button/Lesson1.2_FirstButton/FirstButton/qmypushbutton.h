#ifndef QMYPUSHBUTTON_H
#define QMYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
//#include <QHoverEvent>
class QMyPushButton : public QPushButton
{
public:
    QMyPushButton(QWidget *parent = 0) : QPushButton(parent)
    {
        setMouseTracking(true);
        setAttribute(Qt::WA_Hover);
    };
signals:
    void rClicked();
    void lClicked();
    void hoverEnter();
    void hoverLeave();
protected:
    bool event(QEvent *e);
};

#endif // QMYPUSHBUTTON_H
