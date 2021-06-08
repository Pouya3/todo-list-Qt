#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signuppage.h"
#include "login.h"

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
    signUpPage* sp=new signUpPage;
    sp->show();
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    login* lp=new login;
    lp->show();
    lp->password=password;
    lp->username=username;
    this->close();
}

