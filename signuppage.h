#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>

namespace Ui {
class signUpPage;
}

class signUpPage : public QWidget
{
    Q_OBJECT

public:
    explicit signUpPage(QWidget *parent = nullptr);
    ~signUpPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signUpPage *ui;
};

#endif // SIGNUPPAGE_H
