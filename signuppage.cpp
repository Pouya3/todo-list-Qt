#include "signuppage.h"
#include "ui_signuppage.h"
#include "mainwindow.h"

signUpPage::signUpPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUpPage)
{
    ui->setupUi(this);
}

signUpPage::~signUpPage()
{
    delete ui;
}

void signUpPage::on_pushButton_clicked()
{
    MainWindow* w=new MainWindow;
    w->username=ui->lineEdit_2->text();
    w->password=ui->lineEdit_3->text();
    w->show();
    this->close();
}

