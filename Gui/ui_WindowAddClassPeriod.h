/********************************************************************************
** Form generated from reading UI file 'WindowAddClassPeriod.ui'
**
** Created: Sun Apr 1 23:13:11 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWADDCLASSPERIOD_H
#define UI_WINDOWADDCLASSPERIOD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WindowAddClassPeriod
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *lineEditModule;
    QLabel *label;
    QLineEdit *lineEditTeacher;
    QLabel *label_2;
    QLineEdit *lineEditDuration;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBoxGroup;
    QPushButton *buttonAddGroup;
    QPushButton *buttonDeleteGroup;
    QListWidget *listWidgetGroups;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBoxType;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WindowAddClassPeriod)
    {
        if (WindowAddClassPeriod->objectName().isEmpty())
            WindowAddClassPeriod->setObjectName(QString::fromUtf8("WindowAddClassPeriod"));
        WindowAddClassPeriod->resize(370, 266);
        WindowAddClassPeriod->setMaximumSize(QSize(370, 266));
        verticalLayout = new QVBoxLayout(WindowAddClassPeriod);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_3 = new QLabel(WindowAddClassPeriod);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditModule = new QLineEdit(WindowAddClassPeriod);
        lineEditModule->setObjectName(QString::fromUtf8("lineEditModule"));
        lineEditModule->setEnabled(true);
        lineEditModule->setMaximumSize(QSize(300, 16777215));
        lineEditModule->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditModule);

        label = new QLabel(WindowAddClassPeriod);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        lineEditTeacher = new QLineEdit(WindowAddClassPeriod);
        lineEditTeacher->setObjectName(QString::fromUtf8("lineEditTeacher"));
        lineEditTeacher->setMaximumSize(QSize(200, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditTeacher);

        label_2 = new QLabel(WindowAddClassPeriod);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        lineEditDuration = new QLineEdit(WindowAddClassPeriod);
        lineEditDuration->setObjectName(QString::fromUtf8("lineEditDuration"));
        lineEditDuration->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditDuration);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        comboBoxGroup = new QComboBox(WindowAddClassPeriod);
        comboBoxGroup->setObjectName(QString::fromUtf8("comboBoxGroup"));

        horizontalLayout_2->addWidget(comboBoxGroup);

        buttonAddGroup = new QPushButton(WindowAddClassPeriod);
        buttonAddGroup->setObjectName(QString::fromUtf8("buttonAddGroup"));

        horizontalLayout_2->addWidget(buttonAddGroup);

        buttonDeleteGroup = new QPushButton(WindowAddClassPeriod);
        buttonDeleteGroup->setObjectName(QString::fromUtf8("buttonDeleteGroup"));

        horizontalLayout_2->addWidget(buttonDeleteGroup);


        verticalLayout_3->addLayout(horizontalLayout_2);

        listWidgetGroups = new QListWidget(WindowAddClassPeriod);
        listWidgetGroups->setObjectName(QString::fromUtf8("listWidgetGroups"));

        verticalLayout_3->addWidget(listWidgetGroups);


        formLayout->setLayout(4, QFormLayout::FieldRole, verticalLayout_3);

        label_4 = new QLabel(WindowAddClassPeriod);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(WindowAddClassPeriod);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        comboBoxType = new QComboBox(WindowAddClassPeriod);
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxType);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(WindowAddClassPeriod);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(WindowAddClassPeriod);
        QObject::connect(buttonBox, SIGNAL(accepted()), WindowAddClassPeriod, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WindowAddClassPeriod, SLOT(reject()));

        comboBoxType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WindowAddClassPeriod);
    } // setupUi

    void retranslateUi(QDialog *WindowAddClassPeriod)
    {
        WindowAddClassPeriod->setWindowTitle(QApplication::translate("WindowAddClassPeriod", "WindowAddClassPeriod", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WindowAddClassPeriod", "Module", 0, QApplication::UnicodeUTF8));
        lineEditModule->setText(QString());
        label->setText(QApplication::translate("WindowAddClassPeriod", "Teacher", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowAddClassPeriod", "Duration", 0, QApplication::UnicodeUTF8));
        buttonAddGroup->setText(QApplication::translate("WindowAddClassPeriod", "Add Group", 0, QApplication::UnicodeUTF8));
        buttonDeleteGroup->setText(QApplication::translate("WindowAddClassPeriod", "Delete Group", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WindowAddClassPeriod", "Groups", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("WindowAddClassPeriod", "Type", 0, QApplication::UnicodeUTF8));
        comboBoxType->clear();
        comboBoxType->insertItems(0, QStringList()
         << QApplication::translate("WindowAddClassPeriod", "Magistral", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("WindowAddClassPeriod", "Tutorial", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("WindowAddClassPeriod", "Practical", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class WindowAddClassPeriod: public Ui_WindowAddClassPeriod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADDCLASSPERIOD_H
