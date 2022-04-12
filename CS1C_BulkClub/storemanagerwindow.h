#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>

namespace Ui {
class StoreManagerWindow;
}

class StoreManagerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StoreManagerWindow(QWidget *parent = nullptr);
    ~StoreManagerWindow();

private slots:
    void on_logout_button_clicked();

private:
    Ui::StoreManagerWindow *ui;  // Pointer to the instance of the StoreManagerWindow class object. (SELF)
    QWidget *parent;             // Pointer to the instance of parent window, MainWindow class object.
};

#endif // STOREMANAGERWINDOW_H
