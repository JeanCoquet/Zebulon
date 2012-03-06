#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSchedule.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addTimeSlot();
    void removeTimeSlot();
    void changeDate(QDate date);
    void openEditTimeSlot();

private:
    Ui::MainWindow *ui;
    //QSchedule *edt;
};

#endif // MAINWINDOW_H
