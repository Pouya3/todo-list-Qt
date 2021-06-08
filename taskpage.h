#ifndef TASKPAGE_H
#define TASKPAGE_H

#include <QWidget>
namespace Ui {
class taskPage;
}

class taskPage : public QWidget
{
    Q_OBJECT

public:
    QString mySt;
    int num;
    int now;
    int num2;
    explicit taskPage(QWidget *parent = nullptr);
    ~taskPage();

private slots:
    void complete(int);
    void edit();
    void removeRow();
    void forEdit(QString);
    void showTask(QString);
    void on_pushButton_clicked();

private:
    Ui::taskPage *ui;
};

#endif // TASKPAGE_H
