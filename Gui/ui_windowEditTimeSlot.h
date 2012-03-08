/********************************************************************************
** Form generated from reading UI file 'windowEditTimeSlot.ui'
**
** Created: Tue Mar 6 17:10:35 2012
**      by: Qt User Interface Compiler version 4.7.2
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
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QTimeEdit *timeEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(450, 378);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(Form);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 430, 166));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(scrollAreaWidgetContents);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_2);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        timeEdit = new QTimeEdit(scrollAreaWidgetContents);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, timeEdit);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        calendarWidget = new QCalendarWidget(Form);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Edit Time Slot", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Module", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "ClassPeriod", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "Time", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "Duration (min)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWEDITTIMESLOT_H
