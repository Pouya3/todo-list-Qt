#include "login.h"
#include "ui_login.h"
#include "taskpage.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    if(password==ui->lineEdit_2->text() && username==ui->lineEdit->text())
    {
        taskPage* tp=new taskPage;
        tp->show();
        this->close();
    }
    else
    {
        QMessageBox::information(this,"error","password or username is invalid!");
    }
}

