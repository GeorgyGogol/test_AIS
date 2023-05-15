#include "stdafx.h"
#include "AIS.h"
#include "AisMenuAction.h"

AIS::AIS(QSqlQuery* menuQuery)
    : QMainWindow(nullptr)
    , ui(new Ui::AISClass())
{
    ui->setupUi(this);

	QMap<int, QMenu*> MenuStruct;
	while (menuQuery->next())
	{
		if (!menuQuery->value("isCallAction").toBool()) {
			QMenu* newMenu = new QMenu(menuQuery->value("DisplayName").toString(), ui->menuBar);
			MenuStruct[menuQuery->value("ID").toInt()] = newMenu;
			ui->menuBar->addMenu(newMenu);
		}
		else {
			int parent = menuQuery->value("ID_Parent").toInt();
			AisMenuAction* action = new AisMenuAction(MenuStruct[parent], menuQuery->record());
			MenuStruct[parent]->addAction(action);
			connect(action, &AisMenuAction::call, this, &AIS::call_Form);
			/*
			connect(
				action, SIGNAL(call_form(const QString &, const QString &)), //&AisMenuAction::call_form,
				this, SLOT(call_Form(const QString &, const QString &)) //&AIS::call_Form
			);
			*/
		}
	}

}

AIS::~AIS()
{
    delete ui;
}

void AIS::on_action_UpdateAIS_triggered()
{
	QMessageBox::information(this, QString::fromLocal8Bit("Заглушка"), QString::fromLocal8Bit("Тут обновляется приложуха"));
}

void AIS::on_action_About_triggered()
{
	QFile resAbout(":/AIS/About");
	resAbout.open(QIODevice::ReadOnly);
	QTextStream load(&resAbout);
	load.setCodec(QTextCodec::codecForName("UTF-8"));

	QMessageBox::about(this, QString::fromLocal8Bit("Тестовая АИС"), load.readAll());
}

void AIS::call_Form(const QString& moduleName, const QString& function)
{
	QMessageBox::information(this, "title", "call some form (AIS)");
}

