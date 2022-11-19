/********************************************************************************
** Form generated from reading UI file 'add_class.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_CLASS_H
#define UI_ADD_CLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_add_class
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QDoubleSpinBox *doubleSpinBox;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QComboBox *comboBox;

    void setupUi(QDialog *add_class)
    {
        if (add_class->objectName().isEmpty())
            add_class->setObjectName(QStringLiteral("add_class"));
        add_class->resize(400, 300);
        buttonBox = new QDialogButtonBox(add_class);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 81));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(add_class);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(60, 40, 111, 22));
        textEdit = new QTextEdit(add_class);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(260, 130, 121, 141));
        lineEdit = new QLineEdit(add_class);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(260, 100, 113, 20));
        doubleSpinBox = new QDoubleSpinBox(add_class);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(60, 80, 111, 22));
        dateEdit = new QDateEdit(add_class);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(60, 160, 110, 22));
        dateEdit->setCalendarPopup(true);
        timeEdit = new QTimeEdit(add_class);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(60, 210, 118, 22));
        timeEdit->setCalendarPopup(false);
        timeEdit->setTime(QTime(8, 8, 0));
        comboBox = new QComboBox(add_class);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(60, 120, 111, 22));

        retranslateUi(add_class);
        QObject::connect(buttonBox, SIGNAL(accepted()), add_class, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), add_class, SLOT(reject()));

        QMetaObject::connectSlotsByName(add_class);
    } // setupUi

    void retranslateUi(QDialog *add_class)
    {
        add_class->setWindowTitle(QApplication::translate("add_class", "Dialog", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("add_class", "choix1", Q_NULLPTR)
         << QApplication::translate("add_class", "choix2", Q_NULLPTR)
         << QApplication::translate("add_class", "choix3", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class add_class: public Ui_add_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CLASS_H
