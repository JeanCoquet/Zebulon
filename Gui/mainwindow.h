#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSchedule.h"
<<<<<<< HEAD
#include "WindowEditTimeSlot.h"
#include "../Controller.h"
#include <list>
using namespace std;
=======
>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
<<<<<<< HEAD
    void addClassroomToComboBox();
    void addGroupToComboBox();
    void addModuleToComboBox();
    
=======

>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9
public slots:
    void addTimeSlot();
    void removeTimeSlot();
    void changeDate(QDate date);
    void openEditTimeSlot();

private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
    WindowEditTimeSlot *windowEditTimeSlot;
    Controller *ctrl;
=======
>>>>>>> 147c2b0285400e32547caa52d601089228d27cb9
    //QSchedule *edt;
};

#endif // MAINWINDOW_H
