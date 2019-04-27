#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtTcpDump.h"
#include "WinPcap.h"
#include "qcombobox.h"
class QtTcpDump : public QMainWindow
{
    Q_OBJECT

public:
    QtTcpDump(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtTcpDumpClass ui;

	CWinPcap pcap;

private slots:
	void slot_start();
	void slot_stop();
};
