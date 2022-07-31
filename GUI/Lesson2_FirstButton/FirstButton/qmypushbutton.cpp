#include "qmypushbutton.h"

bool QMyPushButton::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->button() == Qt::LeftButton)
        {
            emit lClicked();
        }
        if(mouseEvent->button() == Qt::RightButton)
        {
            emit rClicked();
        }
    }
    if(event->type() == QEvent::HoverEnter)
    {
        emit hoverEnter();
    }
    if(event->type() == QEvent::HoverLeave)
    {
        emit hoverLeave();
    }
    return QPushButton::event(event);
}

void QMyPushButton::lClicked()
{
    QIcon ButtonIcon("../lhandmouse.jpg");
    this->setIcon(ButtonIcon);
}

void QMyPushButton::rClicked()
{
    QIcon ButtonIcon("../rhandmouse.jpg");
    this->setIcon(ButtonIcon);
}

void QMyPushButton::hoverEnter()
{
    const int &x = this->geometry().x();
    const int &y = this->geometry().y();
    const int &aw = this->geometry().width();
    const int &ah = this->geometry().height();
    this->setGeometry(x + 100, y + 100, aw, ah);

    QIcon ButtonIcon("../mousesit.png");
    this->setIcon(ButtonIcon);
}

void QMyPushButton::hoverLeave()
{
     const int &x = this->geometry().x();
     const int &y = this->geometry().y();
     const int &aw = this->geometry().width();
     const int &ah = this->geometry().height();
     this->setGeometry(x - 100, y - 100, aw, ah);

     QIcon ButtonIcon("../mouserun.jpg");
     this->setIcon(ButtonIcon);
}
