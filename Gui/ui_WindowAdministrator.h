/********************************************************************************
** Form generated from reading UI file 'WindowAdministrator.ui'
**
** Created: Sun Apr 1 00:14:27 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWADMINISTRATOR_H
#define UI_WINDOWADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowAdministrator
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabGroups;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *listWidgetGroups;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonAddGroup;
    QPushButton *buttonEditGroup;
    QPushButton *buttonDeleteGroup;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelStudent;
    QTableWidget *tableWidgetStudents;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonAddStudent;
    QPushButton *buttonEditStudent;
    QPushButton *buttonDeleteStudent;
    QWidget *tabClassrooms;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QTableWidget *tableWidgetClassrooms;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonAddClassroom;
    QPushButton *buttonEditClassroom;
    QPushButton *buttonDeleteClassroom;
    QWidget *tabModules;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QTableWidget *tableWidgetModules;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonAddModule;
    QPushButton *buttonEditModule;
    QPushButton *buttonDeleteModule;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *buttonAddClassPeriod;
    QPushButton *buttonEditClassPeriod;
    QPushButton *buttonDeleteClassPeriod;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WindowAdministrator)
    {
        if (WindowAdministrator->objectName().isEmpty())
            WindowAdministrator->setObjectName(QString::fromUtf8("WindowAdministrator"));
        WindowAdministrator->resize(824, 524);
        verticalLayout = new QVBoxLayout(WindowAdministrator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(WindowAdministrator);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabGroups = new QWidget();
        tabGroups->setObjectName(QString::fromUtf8("tabGroups"));
        horizontalLayout = new QHBoxLayout(tabGroups);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(tabGroups);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        listWidgetGroups = new QListWidget(tabGroups);
        listWidgetGroups->setObjectName(QString::fromUtf8("listWidgetGroups"));

        verticalLayout_2->addWidget(listWidgetGroups);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonAddGroup = new QPushButton(tabGroups);
        buttonAddGroup->setObjectName(QString::fromUtf8("buttonAddGroup"));

        horizontalLayout_2->addWidget(buttonAddGroup);

        buttonEditGroup = new QPushButton(tabGroups);
        buttonEditGroup->setObjectName(QString::fromUtf8("buttonEditGroup"));

        horizontalLayout_2->addWidget(buttonEditGroup);

        buttonDeleteGroup = new QPushButton(tabGroups);
        buttonDeleteGroup->setObjectName(QString::fromUtf8("buttonDeleteGroup"));

        horizontalLayout_2->addWidget(buttonDeleteGroup);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelStudent = new QLabel(tabGroups);
        labelStudent->setObjectName(QString::fromUtf8("labelStudent"));
        labelStudent->setFont(font);

        verticalLayout_3->addWidget(labelStudent);

        tableWidgetStudents = new QTableWidget(tabGroups);
        if (tableWidgetStudents->columnCount() < 5)
            tableWidgetStudents->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetStudents->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetStudents->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetStudents->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetStudents->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetStudents->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetStudents->setObjectName(QString::fromUtf8("tableWidgetStudents"));

        verticalLayout_3->addWidget(tableWidgetStudents);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        buttonAddStudent = new QPushButton(tabGroups);
        buttonAddStudent->setObjectName(QString::fromUtf8("buttonAddStudent"));

        horizontalLayout_3->addWidget(buttonAddStudent);

        buttonEditStudent = new QPushButton(tabGroups);
        buttonEditStudent->setObjectName(QString::fromUtf8("buttonEditStudent"));

        horizontalLayout_3->addWidget(buttonEditStudent);

        buttonDeleteStudent = new QPushButton(tabGroups);
        buttonDeleteStudent->setObjectName(QString::fromUtf8("buttonDeleteStudent"));

        horizontalLayout_3->addWidget(buttonDeleteStudent);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_3);

        tabWidget->addTab(tabGroups, QString());
        tabClassrooms = new QWidget();
        tabClassrooms->setObjectName(QString::fromUtf8("tabClassrooms"));
        horizontalLayout_4 = new QHBoxLayout(tabClassrooms);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(tabClassrooms);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        tableWidgetClassrooms = new QTableWidget(tabClassrooms);
        if (tableWidgetClassrooms->columnCount() < 3)
            tableWidgetClassrooms->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetClassrooms->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetClassrooms->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetClassrooms->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        tableWidgetClassrooms->setObjectName(QString::fromUtf8("tableWidgetClassrooms"));

        verticalLayout_4->addWidget(tableWidgetClassrooms);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        buttonAddClassroom = new QPushButton(tabClassrooms);
        buttonAddClassroom->setObjectName(QString::fromUtf8("buttonAddClassroom"));

        horizontalLayout_5->addWidget(buttonAddClassroom);

        buttonEditClassroom = new QPushButton(tabClassrooms);
        buttonEditClassroom->setObjectName(QString::fromUtf8("buttonEditClassroom"));

        horizontalLayout_5->addWidget(buttonEditClassroom);

        buttonDeleteClassroom = new QPushButton(tabClassrooms);
        buttonDeleteClassroom->setObjectName(QString::fromUtf8("buttonDeleteClassroom"));

        horizontalLayout_5->addWidget(buttonDeleteClassroom);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_4->addLayout(verticalLayout_4);

        tabWidget->addTab(tabClassrooms, QString());
        tabModules = new QWidget();
        tabModules->setObjectName(QString::fromUtf8("tabModules"));
        horizontalLayout_6 = new QHBoxLayout(tabModules);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(tabModules);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_5->addWidget(label_2);

        tableWidgetModules = new QTableWidget(tabModules);
        if (tableWidgetModules->columnCount() < 3)
            tableWidgetModules->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetModules->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetModules->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetModules->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        tableWidgetModules->setObjectName(QString::fromUtf8("tableWidgetModules"));

        verticalLayout_5->addWidget(tableWidgetModules);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        buttonAddModule = new QPushButton(tabModules);
        buttonAddModule->setObjectName(QString::fromUtf8("buttonAddModule"));

        horizontalLayout_7->addWidget(buttonAddModule);

        buttonEditModule = new QPushButton(tabModules);
        buttonEditModule->setObjectName(QString::fromUtf8("buttonEditModule"));

        horizontalLayout_7->addWidget(buttonEditModule);

        buttonDeleteModule = new QPushButton(tabModules);
        buttonDeleteModule->setObjectName(QString::fromUtf8("buttonDeleteModule"));

        horizontalLayout_7->addWidget(buttonDeleteModule);


        verticalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_4 = new QLabel(tabModules);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_7->addWidget(label_4);

        tableWidget_2 = new QTableWidget(tabModules);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_7->addWidget(tableWidget_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        buttonAddClassPeriod = new QPushButton(tabModules);
        buttonAddClassPeriod->setObjectName(QString::fromUtf8("buttonAddClassPeriod"));

        horizontalLayout_8->addWidget(buttonAddClassPeriod);

        buttonEditClassPeriod = new QPushButton(tabModules);
        buttonEditClassPeriod->setObjectName(QString::fromUtf8("buttonEditClassPeriod"));

        horizontalLayout_8->addWidget(buttonEditClassPeriod);

        buttonDeleteClassPeriod = new QPushButton(tabModules);
        buttonDeleteClassPeriod->setObjectName(QString::fromUtf8("buttonDeleteClassPeriod"));

        horizontalLayout_8->addWidget(buttonDeleteClassPeriod);


        verticalLayout_7->addLayout(horizontalLayout_8);


        horizontalLayout_6->addLayout(verticalLayout_7);

        tabWidget->addTab(tabModules, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(WindowAdministrator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(WindowAdministrator);
        QObject::connect(buttonBox, SIGNAL(accepted()), WindowAdministrator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WindowAdministrator, SLOT(reject()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WindowAdministrator);
    } // setupUi

    void retranslateUi(QDialog *WindowAdministrator)
    {
        WindowAdministrator->setWindowTitle(QApplication::translate("WindowAdministrator", "WindowAdministrator", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WindowAdministrator", "Groups", 0, QApplication::UnicodeUTF8));
        buttonAddGroup->setText(QApplication::translate("WindowAdministrator", "Add group", 0, QApplication::UnicodeUTF8));
        buttonEditGroup->setText(QApplication::translate("WindowAdministrator", "Edit group", 0, QApplication::UnicodeUTF8));
        buttonDeleteGroup->setText(QApplication::translate("WindowAdministrator", "Delete Group", 0, QApplication::UnicodeUTF8));
        labelStudent->setText(QApplication::translate("WindowAdministrator", "Students", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetStudents->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("WindowAdministrator", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetStudents->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("WindowAdministrator", "Last name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetStudents->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("WindowAdministrator", "First name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetStudents->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("WindowAdministrator", "Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetStudents->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("WindowAdministrator", "Email", 0, QApplication::UnicodeUTF8));
        buttonAddStudent->setText(QApplication::translate("WindowAdministrator", "Add student", 0, QApplication::UnicodeUTF8));
        buttonEditStudent->setText(QApplication::translate("WindowAdministrator", "Edit student", 0, QApplication::UnicodeUTF8));
        buttonDeleteStudent->setText(QApplication::translate("WindowAdministrator", "Delete student", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGroups), QApplication::translate("WindowAdministrator", "Groups", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WindowAdministrator", "Classrooms", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetClassrooms->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("WindowAdministrator", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetClassrooms->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("WindowAdministrator", "Capacity", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetClassrooms->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("WindowAdministrator", "Specificity", 0, QApplication::UnicodeUTF8));
        buttonAddClassroom->setText(QApplication::translate("WindowAdministrator", "Add classroom", 0, QApplication::UnicodeUTF8));
        buttonEditClassroom->setText(QApplication::translate("WindowAdministrator", "Edit classroom", 0, QApplication::UnicodeUTF8));
        buttonDeleteClassroom->setText(QApplication::translate("WindowAdministrator", "Delete classroom", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabClassrooms), QApplication::translate("WindowAdministrator", "Classrooms", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowAdministrator", "Modules", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetModules->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("WindowAdministrator", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetModules->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("WindowAdministrator", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetModules->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("WindowAdministrator", "The Head", 0, QApplication::UnicodeUTF8));
        buttonAddModule->setText(QApplication::translate("WindowAdministrator", "Add Module", 0, QApplication::UnicodeUTF8));
        buttonEditModule->setText(QApplication::translate("WindowAdministrator", "Edit Module", 0, QApplication::UnicodeUTF8));
        buttonDeleteModule->setText(QApplication::translate("WindowAdministrator", "Delete Module", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WindowAdministrator", "Class Period", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("WindowAdministrator", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("WindowAdministrator", "Teacher", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("WindowAdministrator", "Duration", 0, QApplication::UnicodeUTF8));
        buttonAddClassPeriod->setText(QApplication::translate("WindowAdministrator", "Add Class Period", 0, QApplication::UnicodeUTF8));
        buttonEditClassPeriod->setText(QApplication::translate("WindowAdministrator", "Edit Class Period", 0, QApplication::UnicodeUTF8));
        buttonDeleteClassPeriod->setText(QApplication::translate("WindowAdministrator", "Delete Class Period", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabModules), QApplication::translate("WindowAdministrator", "Modules", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowAdministrator: public Ui_WindowAdministrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADMINISTRATOR_H
