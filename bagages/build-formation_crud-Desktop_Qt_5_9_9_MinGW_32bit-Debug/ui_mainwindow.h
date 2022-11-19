/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "webaxwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionadd;
    QAction *actiondelete;
    QAction *actionplay_video;
    QAction *actionstop_video;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *recherche;
    QTableView *tableau;
    QPushButton *export_excel;
    QPushButton *stat;
    QPushButton *pdf;
    QPushButton *camera;
    QWidget *tab_2;
    QPushButton *sendBtn;
    QLineEdit *subject;
    QPushButton *browseBtn;
    QLineEdit *file;
    QTextEdit *msg;
    QLineEdit *rcpt;
    QLineEdit *mail_pass;
    QWidget *tab_3;
    WebAxWidget *WebBrowser;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionadd = new QAction(MainWindow);
        actionadd->setObjectName(QStringLiteral("actionadd"));
        actiondelete = new QAction(MainWindow);
        actiondelete->setObjectName(QStringLiteral("actiondelete"));
        actionplay_video = new QAction(MainWindow);
        actionplay_video->setObjectName(QStringLiteral("actionplay_video"));
        actionstop_video = new QAction(MainWindow);
        actionstop_video->setObjectName(QStringLiteral("actionstop_video"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 711, 461));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        recherche = new QLineEdit(tab);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(480, 30, 191, 24));
        recherche->setClearButtonEnabled(true);
        tableau = new QTableView(tab);
        tableau->setObjectName(QStringLiteral("tableau"));
        tableau->setGeometry(QRect(20, 71, 651, 331));
        tableau->setSortingEnabled(true);
        tableau->horizontalHeader()->setCascadingSectionResizes(true);
        tableau->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableau->horizontalHeader()->setStretchLastSection(false);
        export_excel = new QPushButton(tab);
        export_excel->setObjectName(QStringLiteral("export_excel"));
        export_excel->setGeometry(QRect(374, 30, 91, 23));
        stat = new QPushButton(tab);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(200, 30, 101, 23));
        pdf = new QPushButton(tab);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(310, 30, 51, 23));
        camera = new QPushButton(tab);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(120, 30, 71, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sendBtn = new QPushButton(tab_2);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(10, 410, 651, 23));
        subject = new QLineEdit(tab_2);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(10, 44, 651, 16));
        browseBtn = new QPushButton(tab_2);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(587, 79, 75, 24));
        file = new QLineEdit(tab_2);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(10, 80, 571, 23));
        msg = new QTextEdit(tab_2);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(10, 116, 651, 291));
        rcpt = new QLineEdit(tab_2);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(10, 10, 491, 21));
        mail_pass = new QLineEdit(tab_2);
        mail_pass->setObjectName(QStringLiteral("mail_pass"));
        mail_pass->setGeometry(QRect(522, 10, 141, 20));
        mail_pass->setEchoMode(QLineEdit::Password);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        WebBrowser = new WebAxWidget(tab_3);
        WebBrowser->setControl(QStringLiteral("{8856F961-340A-11D0-A96B-00C04FD705A2}"));
        WebBrowser->setObjectName(QStringLiteral("WebBrowser"));
        WebBrowser->setProperty("focusPolicy", QVariant::fromValue(Qt::StrongFocus));
        WebBrowser->setProperty("geometry", QVariant(QRect(-1, -1, 691, 461)));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionadd);
        toolBar->addAction(actiondelete);
        toolBar->addSeparator();
        toolBar->addAction(actionplay_video);
        toolBar->addAction(actionstop_video);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionadd->setText(QApplication::translate("MainWindow", "add", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionadd->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actiondelete->setText(QApplication::translate("MainWindow", "delete", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actiondelete->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionplay_video->setText(QApplication::translate("MainWindow", "play video", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionplay_video->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionstop_video->setText(QApplication::translate("MainWindow", "stop video", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionstop_video->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        recherche->setPlaceholderText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        export_excel->setText(QApplication::translate("MainWindow", "export excel", Q_NULLPTR));
        stat->setText(QApplication::translate("MainWindow", "stat combo", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow", "Pdf", Q_NULLPTR));
        camera->setText(QApplication::translate("MainWindow", "camera", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "crud", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        subject->setPlaceholderText(QApplication::translate("MainWindow", "subject", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("MainWindow", "Browse ...", Q_NULLPTR));
        file->setPlaceholderText(QApplication::translate("MainWindow", "attachement here", Q_NULLPTR));
        msg->setPlaceholderText(QApplication::translate("MainWindow", "type your message here ...", Q_NULLPTR));
        rcpt->setPlaceholderText(QApplication::translate("MainWindow", "recipient", Q_NULLPTR));
        mail_pass->setPlaceholderText(QApplication::translate("MainWindow", "your mail password", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "map", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
