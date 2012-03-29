/********************************************************************************
** Form generated from reading UI file 'WindowAdministrator.ui'
**
** Created: Thu Mar 29 12:56:35 2012
**      by: Qt User Interface Compiler version 4.7.2
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
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTableWidget *tableWidgetStudents;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonAddStudent;
    QWidget *tabClassrooms;
    QWidget *tabModules;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WindowAdministrator)
    {
        if (WindowAdministrator->objectName().isEmpty())
            WindowAdministrator->setObjectName(QString::fromUtf8("WindowAdministrator"));
        WindowAdministrator->resize(696, 524);
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


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(tabGroups);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

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


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_3);

        tabWidget->addTab(tabGroups, QString());
        tabClassrooms = new QWidget();
        tabClassrooms->setObjectName(QString::fromUtf8("tabClassrooms"));
        tabWidget->addTab(tabClassrooms, QString());
        tabModules = new QWidget();
        tabModules->setObjectName(QString::fromUtf8("tabModules"));
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WindowAdministrator);
    } // setupUi

    void retranslateUi(QDialog *WindowAdministrator)
    {
        WindowAdministrator->setWindowTitle(QApplication::translate("WindowAdministrator", "WindowAdministrator", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WindowAdministrator", "Groups", 0, QApplication::UnicodeUTF8));
        buttonAddGroup->setText(QApplication::translate("WindowAdministrator", "Add group", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowAdministrator", "Students of", 0, QApplication::UnicodeUTF8));
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
        tabWidget->setTabText(tabWidget->indexOf(tabGroups), QApplication::translate("WindowAdministrator", "Groups", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabClassrooms), QApplication::translate("WindowAdministrator", "Classerooms", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabModules), QApplication::translate("WindowAdministrator", "Modules", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowAdministrator: public Ui_WindowAdministrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADMINISTRATOR_H
