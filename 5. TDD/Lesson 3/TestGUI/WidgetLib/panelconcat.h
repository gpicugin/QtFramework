#ifndef PANELCONCAT_H
#define PANELCONCAT_H

#include "WidgetLib_global.h"

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;

class WIDGETLIB_EXPORT PanelConcat : public QWidget
{
    Q_OBJECT

    friend class TestPanelConcat;

public:
    explicit PanelConcat(QWidget * parent = nullptr);

public slots:
    void ConcatData();
    void CancelData();

private:
    static const int MIN_W = 480;
    static const int MIN_H = 240;

private:
    QLineEdit * mInputA;
    QLineEdit * mInputB;

    QPushButton * mButtonConcat;
    QPushButton * mButtonCancel;

    QLabel * mLabelRes;
};

#endif // PANELCONCAT_H
