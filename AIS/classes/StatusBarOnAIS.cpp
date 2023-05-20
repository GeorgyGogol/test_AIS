#include "stdafx.h"
#include "StatusBarOnAIS.h"
#include <QStatusBar>
#include <QLabel>

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
	object->setText(QString("Что-то: ") + QString::number(data.SomeData));

	object = static_cast<QLabel*>(objects[2]);
	QString serverText = "Сервер: ";
	if (QSqlDatabase::contains("MainConn")) {
		serverText += QSqlDatabase::database("MainConn").databaseName();
	}
	else {
		serverText += "Не определен";
	}
	object->setText(serverText);
}
