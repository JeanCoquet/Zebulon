/********************************************************************************
** Form generated from reading UI file 'WindowAddClassroom.ui'
**
** Created: Sun Apr 1 23:13:11 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWADDCLASSROOM_H
#define UI_WINDOWADDCLASSROOM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_WindowAddClassroom
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WindowAddClassroom)
    {
        if (WindowAddClassroom->objectName().isEmpty())
            WindowAddClassroom->setObjectName(QString::fromUtf8("WindowAddClassroom"));
        WindowAddClassroom->resize(400, 225);
        formLayout = new QFormLayout(WindowAddClassroom);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(WindowAddClassroom);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(WindowAddClassroom);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(WindowAddClassroom);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(WindowAddClassroom);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        radioButton_2 = new QRadioButton(WindowAddClassroom);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, radioButton_2);

        radioButton_3 = new QRadioButton(WindowAddClassroom);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        formLayout->setWidget(4, QFormLayout::FieldRole, radioButton_3);

        radioButton = new QRadioButton(WindowAddClassroom);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, radioButton);

        checkBox = new QCheckBox(WindowAddClassroom);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        formLayout->setWidget(6, QFormLayout::FieldRole, checkBox);

        buttonBox = new QDialogButtonBox(WindowAddClassroom);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(7, QFormLayout::FieldRole, buttonBox);


        retranslateUi(WindowAddClassroom);
        QObject::connect(buttonBox, SIGNAL(accepted()), WindowAddClassroom, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WindowAddClassroom, SLOT(reject()));

        QMetaObject::connectSlotsByName(WindowAddClassroom);
    } // setupUi

    void retranslateUi(QDialog *WindowAddClassroom)
    {
        WindowAddClassroom->setWindowTitle(QApplication::translate("WindowAddClassroom", "Add a classroom", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WindowAddClassroom", "Name (Id)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowAddClassroom", "Capacity", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("WindowAddClassroom", "Tutorial classroom", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("WindowAddClassroom", "Pratical classroom", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("WindowAddClassroom", "Lecture hall", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("WindowAddClassroom", "no name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowAddClassroom: public Ui_WindowAddClassroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADDCLASSROOM_H
