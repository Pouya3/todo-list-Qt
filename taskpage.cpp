#include "taskpage.h"
#include "ui_taskpage.h"
#include <QTableWidgetItem>
#include <QCheckBox>
#include "dialog.h"

taskPage::taskPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskPage)
{
    ui->setupUi(this);
    num=0;num2=0;now=0;
}

taskPage::~taskPage()
{
    delete ui;
}

void taskPage::complete(int a)
{
    if(a)
    {
        num2++;
        ui->label_4->setText(QString::number(num2));
        int y=ui->tableWidget->currentRow();
        ui->tableWidget->cellWidget(y,0)->setStyleSheet("text-decoration:line-through;}");
    }
    else
    {
        num2--;
        ui->label_4->setText(QString::number(num2));
        int y=ui->tableWidget->currentRow();
        ui->tableWidget->cellWidget(y,0)->setStyleSheet("text-decoration:normal;}");
    }
}

void taskPage::on_pushButton_clicked()
{
    Dialog* d=new Dialog;
    connect(d,SIGNAL(sendName(QString)),this,SLOT(showTask(QString)));
    d->show();
}
void taskPage::edit()
{
    Dialog* d=new Dialog;
    connect(d,SIGNAL(sendName(QString)),this,SLOT(forEdit(QString)));
    d->show();
}

void taskPage::removeRow()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    num--;
    ui->label_2->setText(QString::number(num));
}

void taskPage::forEdit(QString str)
{
   ui->tableWidget->removeCellWidget(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn()-1);
   QCheckBox* ch=new QCheckBox(str);
   ui->tableWidget->setCellWidget(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn()-1,ch);
}
void taskPage::showTask(QString str)
{
        QPushButton* pb1=new QPushButton("Edit");
        QPushButton* pb2=new QPushButton("Remove");
        QCheckBox* ch=new QCheckBox(str);
        ui->tableWidget->insertRow(num);
        ui->tableWidget->setCellWidget(num,0,ch);
        ui->tableWidget->setCellWidget(num,1,pb1);
        ui->tableWidget->setCellWidget(num,2,pb2);
        num++;
        ui->label_2->setText(QString::number(num));
        connect(ch,SIGNAL(stateChanged(int)),this,SLOT(complete(int)));
        connect(pb1,SIGNAL(clicked()),this,SLOT(edit()));
        connect(pb2,SIGNAL(clicked()),this,SLOT(removeRow()));
}
