#include "stdafx.h"
#include "AIS.h"
#include <QtWidgets/QApplication>
#include <qdir.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QFile dataBaseFile(":/AIS/MenuMap");
	dataBaseFile.copy("MenuMap");

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "MainConn");
	db.setDatabaseName("MenuMap");
	if (!db.open()) {
		DBG_PRINT(db.lastError().text());
		QMessageBox::critical(nullptr, QString::fromLocal8Bit("Ошибка ресурсов!"), QString::fromLocal8Bit("Файл конфигурации не загружен!"));
		return 100;
	}

	DBG_PRINT(db.databaseName());

	std::unique_ptr<QSqlQuery> menu(new QSqlQuery(db));
	if (!menu->exec("SELECT * FROM AIS_Menu")) {
		DBG_PRINT(menu->lastError().text());
		QMessageBox::critical(nullptr, QString::fromLocal8Bit("Ошибка ресурсов!"), QString::fromLocal8Bit("Не получен ответ конфигурации АИС!"));
		return 101;
	}

    AIS w(menu.get());

	menu.reset(nullptr);

    w.show();
    return a.exec();
}
