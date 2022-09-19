#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/image.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    pix = pix.scaled(w * 2.5, h * 12);
    ui->image->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   QString login = ui->login->text();
   QString password = ui->password->text();

   if(login == "Grag" && password == "123")
   {
       //QMessageBox::information(this, "Ура", "Авторизация успешна!");
       ui->statusbar->showMessage("Авторизация успешна!");
   }
   else
   {
       //QMessageBox::warning(this, "Авторизация", "Неверный логин или пароль!");
       ui->statusbar->showMessage("Неверный логин или пароль!");
   }
}

