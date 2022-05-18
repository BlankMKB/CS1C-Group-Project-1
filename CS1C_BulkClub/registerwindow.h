#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QDialog>
#include <qmessagebox.h>


#define USE_PATHS
#include "defines.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_registerButton_clicked();

private:
    bool ValidInput();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
