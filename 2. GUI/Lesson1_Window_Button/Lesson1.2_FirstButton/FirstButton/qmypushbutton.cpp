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
    QPixmap pixmap("://lhandmouse.jpg");
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
}

void QMyPushButton::rClicked()
{
    QPixmap pixmap("://rhandmouse.jpg");
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
}

void QMyPushButton::hoverEnter()
{
    const int &x = this->geometry().x();
    const int &y = this->geometry().y();
    const int &aw = this->geometry().width();
    const int &ah = this->geometry().height();
    this->setGeometry(x + 100, y + 100, aw, ah);


    QPixmap pixmap("://mousesit.jpg");
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
}

void QMyPushButton::hoverLeave()
{
     const int &x = this->geometry().x();
     const int &y = this->geometry().y();
     const int &aw = this->geometry().width();
     const int &ah = this->geometry().height();
     this->setGeometry(x - 100, y - 100, aw, ah);

     QPixmap pixmap("://mouserun.jpg");
     QIcon ButtonIcon(pixmap);
     this->setIcon(ButtonIcon);
}
