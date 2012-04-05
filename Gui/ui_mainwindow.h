/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 5 16:38:51 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QSchedule.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionAdministrator;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QSchedule *edt;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBoxGroup;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBoxClassroom;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_7;
    QComboBox *comboBoxStudent;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *checkBoxMagistral;
    QCheckBox *checkBoxTutorial;
    QCheckBox *checkBoxPractical;
    QCalendarWidget *calendarWidget;
    QCommandLinkButton *addTimeSlotButton;
    QSpacerItem *verticalSpacer;
    QPushButton *commitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(739, 679);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../zebulon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAdministrator = new QAction(MainWindow);
        actionAdministrator->setObjectName(QString::fromUtf8("actionAdministrator"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 443, 610));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        edt = new QSchedule(scrollAreaWidgetContents_2);
        edt->setObjectName(QString::fromUtf8("edt"));
        edt->setEnabled(true);

        verticalLayout_3->addWidget(edt);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 739, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(270, 630));
        dockWidget->setMaximumSize(QSize(524287, 524287));
        dockWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(250, 75));
        tabWidget->setMaximumSize(QSize(200, 75));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        comboBoxGroup = new QComboBox(tab_3);
        comboBoxGroup->setObjectName(QString::fromUtf8("comboBoxGroup"));
        comboBoxGroup->setMinimumSize(QSize(125, 30));

        verticalLayout_6->addWidget(comboBoxGroup);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        comboBoxClassroom = new QComboBox(tab);
        comboBoxClassroom->setObjectName(QString::fromUtf8("comboBoxClassroom"));
        comboBoxClassroom->setMinimumSize(QSize(125, 30));

        verticalLayout_4->addWidget(comboBoxClassroom);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_7 = new QVBoxLayout(tab_4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        comboBoxStudent = new QComboBox(tab_4);
        comboBoxStudent->setObjectName(QString::fromUtf8("comboBoxStudent"));
        comboBoxStudent->setMinimumSize(QSize(125, 30));
        comboBoxStudent->setEditable(true);

        verticalLayout_7->addWidget(comboBoxStudent);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        frame = new QFrame(dockWidgetContents);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        checkBoxMagistral = new QCheckBox(frame);
        checkBoxMagistral->setObjectName(QString::fromUtf8("checkBoxMagistral"));
        checkBoxMagistral->setChecked(true);
        checkBoxMagistral->setTristate(false);

        verticalLayout_8->addWidget(checkBoxMagistral);

        checkBoxTutorial = new QCheckBox(frame);
        checkBoxTutorial->setObjectName(QString::fromUtf8("checkBoxTutorial"));
        checkBoxTutorial->setChecked(true);

        verticalLayout_8->addWidget(checkBoxTutorial);

        checkBoxPractical = new QCheckBox(frame);
        checkBoxPractical->setObjectName(QString::fromUtf8("checkBoxPractical"));
        checkBoxPractical->setChecked(true);

        verticalLayout_8->addWidget(checkBoxPractical);


        verticalLayout->addWidget(frame);

        calendarWidget = new QCalendarWidget(dockWidgetContents);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setMinimumSize(QSize(250, 200));
        calendarWidget->setMaximumSize(QSize(250, 200));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::NoHorizontalHeader);

        verticalLayout->addWidget(calendarWidget);

        addTimeSlotButton = new QCommandLinkButton(dockWidgetContents);
        addTimeSlotButton->setObjectName(QString::fromUtf8("addTimeSlotButton"));

        verticalLayout->addWidget(addTimeSlotButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        commitButton = new QPushButton(dockWidgetContents);
        commitButton->setObjectName(QString::fromUtf8("commitButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Check-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        commitButton->setIcon(icon1);

        verticalLayout->addWidget(commitButton);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionAdministrator);
        menuFile->addAction(actionClose);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Zebulon", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionAdministrator->setText(QApplication::translate("MainWindow", "Administrator", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Group", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Classroom", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Student", 0, QApplication::UnicodeUTF8));
        checkBoxMagistral->setText(QApplication::translate("MainWindow", "Magistral Class", 0, QApplication::UnicodeUTF8));
        checkBoxTutorial->setText(QApplication::translate("MainWindow", "Tutorial Class", 0, QApplication::UnicodeUTF8));
        checkBoxPractical->setText(QApplication::translate("MainWindow", "Practical Class", 0, QApplication::UnicodeUTF8));
        addTimeSlotButton->setText(QApplication::translate("MainWindow", "Add Time Slot", 0, QApplication::UnicodeUTF8));
        commitButton->setText(QApplication::translate("MainWindow", "Commit changes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
