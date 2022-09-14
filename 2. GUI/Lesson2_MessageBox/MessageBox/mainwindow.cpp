#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::about(this, "Заголовок", "Текст внутри");
    //QMessageBox::critical(this, "Заголовок", "Сообщение об ошибке");
    //QMessageBox::information(this, "Заголовок", "Информация");
    //QMessageBox::warning(this, "Заголовок", "Предупреждение");
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Заголовок", "Да или Нет?",
                                                              QMessageBox::Yes | QMessageBox::No); // кнопки Yes No
    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        qDebug() << "Push No button";
    }
}

