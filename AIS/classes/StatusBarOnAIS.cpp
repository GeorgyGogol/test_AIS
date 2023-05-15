#include "stdafx.h"
#include "StatusBarOnAIS.h"
#include <QLabel>
#include <QSizePolicy>


StatusBarOnAIS::StatusBarOnAIS(QWidget *parent)
	: QStatusBar(parent)
{
	QLabel* someData = new QLabel(this);
	someData->setFixedSize(80, 20);
	addWidget(someData);

	QLabel* ConnectionLbel = new QLabel(this);
	ConnectionLbel->setFixedSize(180, 20);
	addWidget(ConnectionLbel);

	UpdateData(our::ProgrammData());
}

StatusBarOnAIS::~StatusBarOnAIS()
{}

void StatusBarOnAIS::UpdateData(const our::ProgrammData& data)
{
	QObjectList objects = children();
	QLabel* object;

	object = static_cast<QLabel*>(objects[1]);
	object->setText(QString::fromLocal8Bit("Что-то: ") + QString::number(data.SomeData));

	object = static_cast<QLabel*>(objects[2]);
	object->setText(QString::fromLocal8Bit("Сервер: Не определен") /* + QString::number(data.SomeData)*/ );
}
