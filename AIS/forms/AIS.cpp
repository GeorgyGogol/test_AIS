#include "stdafx.h"
#include "AIS.h"
#include "AisMenuAction.h"
#include "GeneralTypes.h"

AIS::AIS(QSqlQuery* menuQuery, const our::ProgrammData& inputData)
    : QMainWindow(nullptr)
    , ui(new Ui::AISClass())
	, Data(inputData)
{
    ui->setupUi(this);

	QMap<int, QMenu*> MenuStruct;
	int ID_Parent;
	while (menuQuery->next())
	{
		if (!menuQuery->value("isCallAction").toBool()) {
			QMenu* newMenu = new QMenu(menuQuery->value("DisplayName").toString(), ui->menuBar);
			MenuStruct[menuQuery->value("ID").toInt()] = newMenu;

			ID_Parent = menuQuery->value("ID_Parent").toInt();
			if (!ID_Parent) {
				ui->menuBar->addMenu(newMenu);
			}
			else {
				MenuStruct[ID_Parent]->addMenu(newMenu);
			}

		}
		else {
			ID_Parent = menuQuery->value("ID_Parent").toInt();
			AisMenuAction* action = new AisMenuAction(MenuStruct[ID_Parent], menuQuery->record());
			MenuStruct[ID_Parent]->addAction(action);
			connect(action, &AisMenuAction::call, this, &AIS::call_Form);
		}
	}
	ui->statusBar->UpdateData(Data);
}

AIS::~AIS()
{
    delete ui;
}

void AIS::on_action_UpdateAIS_triggered()
{
	QMessageBox::information(this, "Заглушка", "Тут обновляется приложуха");
}

void AIS::on_action_About_triggered()
{
	QFile resAbout(":/AIS/About");
	resAbout.open(QIODevice::ReadOnly);
	QTextStream load(&resAbout);
	load.setCodec(QTextCodec::codecForName("UTF-8"));

	QMessageBox::about(this, "Тестовая АИС", load.readAll());
}

void AIS::call_Form(const char* moduleName, const char* function)
{
	HINSTANCE hDll = nullptr;
	our::t_CallFunction func = nullptr;

	hDll = LoadLibraryA(moduleName);
	if (!hDll) {
		QMessageBox::critical(this, "Ошибка загрузки модуля!", "Модуль не загружен и скорее всего не найден!");
		return;
	}

	func = our::t_CallFunction(GetProcAddress(hDll, function));
	if (!func) {
		DBG_PRINT(GetLastError());
		QMessageBox::critical(this, "Ошибка загрузки модуля!", "Вызываемый метод не обнаружен!");
	}
	else {
		func(Data);
	}
	
	FreeLibrary(hDll);
}

