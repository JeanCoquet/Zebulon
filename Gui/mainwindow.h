#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSchedule.h"
#include "WindowEditTimeSlot.h"
#include "../Controller.h"
#include <list>
using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addClassroomToComboBox();
    void addGroupToComboBox();
    void addModuleToComboBox();
    
public slots:
    void addTimeSlot();
    void removeTimeSlot();
    void changeDate(QDate date);
    void openEditTimeSlot();

private:
    Ui::MainWindow *ui;
    WindowEditTimeSlot *windowEditTimeSlot;
    Controller *ctrl;
    //QSchedule *edt;
};

#endif // MAINWINDOW_H
