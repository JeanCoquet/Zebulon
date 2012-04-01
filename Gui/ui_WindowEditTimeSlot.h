/********************************************************************************
** Form generated from reading UI file 'WindowEditTimeSlot.ui'
**
** Created: Sun Apr 1 23:13:11 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWEDITTIMESLOT_H
#define UI_WINDOWEDITTIMESLOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowEditTimeSlot
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *deleteTimeSlotButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxModule;
    QLabel *label_2;
    QComboBox *comboBoxClassPeriod;
    QLabel *label_5;
    QComboBox *comboBoxClassroom;
    QLabel *label_3;
    QTimeEdit *timeEdit;
    QLabel *label_4;
    QLineEdit *durationVal;
    QLabel *label_6;
    QListWidget *listGroups;
    QPushButton *addClassPeriod;
    QCalendarWidget *calendarWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WindowEditTimeSlot)
    {
        if (WindowEditTimeSlot->objectName().isEmpty())
            WindowEditTimeSlot->setObjectName(QString::fromUtf8("WindowEditTimeSlot"));
        WindowEditTimeSlot->setWindowModality(Qt::NonModal);
        WindowEditTimeSlot->resize(431, 623);
        verticalLayout = new QVBoxLayout(WindowEditTimeSlot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        deleteTimeSlotButton = new QPushButton(WindowEditTimeSlot);
        deleteTimeSlotButton->setObjectName(QString::fromUtf8("deleteTimeSlotButton"));

        verticalLayout->addWidget(deleteTimeSlotButton);

        scrollArea = new QScrollArea(WindowEditTimeSlot);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 417, 354));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxModule = new QComboBox(scrollAreaWidgetContents);
        comboBoxModule->setObjectName(QString::fromUtf8("comboBoxModule"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxModule);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        comboBoxClassPeriod = new QComboBox(scrollAreaWidgetContents);
        comboBoxClassPeriod->setObjectName(QString::fromUtf8("comboBoxClassPeriod"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxClassPeriod->sizePolicy().hasHeightForWidth());
        comboBoxClassPeriod->setSizePolicy(sizePolicy);
        comboBoxClassPeriod->setMinimumSize(QSize(150, 0));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxClassPeriod);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_5);

        comboBoxClassroom = new QComboBox(scrollAreaWidgetContents);
        comboBoxClassroom->setObjectName(QString::fromUtf8("comboBoxClassroom"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBoxClassroom);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_3);

        timeEdit = new QTimeEdit(scrollAreaWidgetContents);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(10, QFormLayout::FieldRole, timeEdit);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_4);

        durationVal = new QLineEdit(scrollAreaWidgetContents);
        durationVal->setObjectName(QString::fromUtf8("durationVal"));
        durationVal->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(11, QFormLayout::FieldRole, durationVal);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        listGroups = new QListWidget(scrollAreaWidgetContents);
        listGroups->setObjectName(QString::fromUtf8("listGroups"));

        formLayout->setWidget(5, QFormLayout::FieldRole, listGroups);

        addClassPeriod = new QPushButton(scrollAreaWidgetContents);
        addClassPeriod->setObjectName(QString::fromUtf8("addClassPeriod"));
        addClassPeriod->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, addClassPeriod);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        calendarWidget = new QCalendarWidget(WindowEditTimeSlot);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(false);

        verticalLayout->addWidget(calendarWidget);

        buttonBox = new QDialogButtonBox(WindowEditTimeSlot);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(WindowEditTimeSlot);
        QObject::connect(buttonBox, SIGNAL(accepted()), WindowEditTimeSlot, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WindowEditTimeSlot, SLOT(reject()));

        QMetaObject::connectSlotsByName(WindowEditTimeSlot);
    } // setupUi

    void retranslateUi(QDialog *WindowEditTimeSlot)
    {
        WindowEditTimeSlot->setWindowTitle(QApplication::translate("WindowEditTimeSlot", "WindowEditTimeSlot", 0, QApplication::UnicodeUTF8));
        deleteTimeSlotButton->setText(QApplication::translate("WindowEditTimeSlot", "Delete", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WindowEditTimeSlot", "Module", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowEditTimeSlot", "ClassPeriod", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("WindowEditTimeSlot", "Classroom", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WindowEditTimeSlot", "Time", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WindowEditTimeSlot", "Duration (min)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("WindowEditTimeSlot", "Group", 0, QApplication::UnicodeUTF8));
        addClassPeriod->setText(QApplication::translate("WindowEditTimeSlot", "Add a new Class period", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowEditTimeSlot: public Ui_WindowEditTimeSlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWEDITTIMESLOT_H
