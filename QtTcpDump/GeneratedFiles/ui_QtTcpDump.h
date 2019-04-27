/********************************************************************************
** Form generated from reading UI file 'QtTcpDump.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTCPDUMP_H
#define UI_QTTCPDUMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTcpDumpClass
{
public:
    QWidget *centralWidget;
    QComboBox *m_combox_macs;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QLineEdit *lineEdit_filter;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtTcpDumpClass)
    {
        if (QtTcpDumpClass->objectName().isEmpty())
            QtTcpDumpClass->setObjectName(QStringLiteral("QtTcpDumpClass"));
        QtTcpDumpClass->resize(600, 400);
        centralWidget = new QWidget(QtTcpDumpClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        m_combox_macs = new QComboBox(centralWidget);
        m_combox_macs->setObjectName(QStringLiteral("m_combox_macs"));
        m_combox_macs->setGeometry(QRect(0, 0, 311, 31));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(360, 10, 75, 23));
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(450, 10, 75, 23));
        lineEdit_filter = new QLineEdit(centralWidget);
        lineEdit_filter->setObjectName(QStringLiteral("lineEdit_filter"));
        lineEdit_filter->setGeometry(QRect(80, 70, 471, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 54, 12));
        QtTcpDumpClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtTcpDumpClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        QtTcpDumpClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtTcpDumpClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtTcpDumpClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtTcpDumpClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtTcpDumpClass->setStatusBar(statusBar);

        retranslateUi(QtTcpDumpClass);
        QObject::connect(pushButton_start, SIGNAL(clicked()), QtTcpDumpClass, SLOT(slot_start()));
        QObject::connect(pushButton_stop, SIGNAL(clicked()), QtTcpDumpClass, SLOT(slot_stop()));

        QMetaObject::connectSlotsByName(QtTcpDumpClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtTcpDumpClass)
    {
        QtTcpDumpClass->setWindowTitle(QApplication::translate("QtTcpDumpClass", "QtTcpDump", Q_NULLPTR));
        pushButton_start->setText(QApplication::translate("QtTcpDumpClass", "Start", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("QtTcpDumpClass", "Stop", Q_NULLPTR));
        lineEdit_filter->setText(QApplication::translate("QtTcpDumpClass", "ip src 192.168.0.123 or ip dst 192.168.0.123", Q_NULLPTR));
        label->setText(QApplication::translate("QtTcpDumpClass", "filter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtTcpDumpClass: public Ui_QtTcpDumpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTCPDUMP_H
