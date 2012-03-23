#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSchedule.h"
#include "WindowEditTimeSlot.h"
#include "Model/Controller.h"
#include <list>
using namespace std;

class WindowEditTimeSlot;

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
    
    Controller* getCtrl() const {
        return ctrl;
    }

    Ui::MainWindow* getUi() const {
        return ui;
    }
    
    
    void addTimeSlot(QTimeSlot *t);

    
public slots:
    void removeTimeSlot(QTimeSlot*);
    void changeDate(QDate date);
    void openEditTimeSlot();
    void openEditTimeSlot(QTimeSlot* timeSlot);
    void tabIndexChanged();
    void commit();

private:
    void reloadQTimeSlots();
    void genererQTimeSlot(TimeSlot* t);
    Ui::MainWindow *ui;
    WindowEditTimeSlot *windowEditTimeSlot;
    Controller *ctrl;
};

#endif // MAINWINDOW_H
