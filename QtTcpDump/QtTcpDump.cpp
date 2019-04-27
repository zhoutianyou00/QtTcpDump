#include "QtTcpDump.h"
#include "WinPcap.h"
#include <qpushbutton.h>
#include <qlineedit.h>
QtTcpDump::QtTcpDump(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	pcap.Init();


	int cnt = pcap.GetMacsCnt();


	for (int i = 0; i < cnt; i++)
	{
		ui.m_combox_macs->addItem(pcap.GetMac(i).c_str());
	}

	ui.pushButton_stop->setEnabled(false);
}


void QtTcpDump::slot_start()
{
	int id = ui.m_combox_macs->currentIndex();
	QString str = ui.lineEdit_filter->text();
	pcap.StartCapture(id, "capture.bin", str.toStdString().c_str());
	ui.pushButton_start->setEnabled(false);
	ui.pushButton_stop->setEnabled(true);
}

void QtTcpDump::slot_stop()
{
	pcap.StopCapture();
	ui.pushButton_start->setEnabled(true);
	ui.pushButton_stop->setEnabled(false);
}