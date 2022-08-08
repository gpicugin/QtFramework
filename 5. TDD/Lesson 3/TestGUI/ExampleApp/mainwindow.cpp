#include "mainwindow.h"

#include "../WidgetLib/panelconcat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    PanelConcat * panel = new PanelConcat(this);

    setCentralWidget(panel);
}
