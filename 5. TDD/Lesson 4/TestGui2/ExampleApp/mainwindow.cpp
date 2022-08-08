#include "mainwindow.h"

#include "../WidgetsLib/panelconcat.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    PanelConcat * panel = new PanelConcat(this);
    setCentralWidget(panel);
}

MainWindow::~MainWindow()
{
}

