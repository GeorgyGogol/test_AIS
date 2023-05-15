#include "stdafx.h"
#include "AIS.h"
#include <QtWidgets/QApplication>
#include <qdir.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QTemporaryDir tmpDir;
	tmpDir.setAutoRemove(true);
	QString dbPath = tmpDir.path() + "/MenuMap";
	QFile dataBaseResource(":/AIS/MenuMap");
	dataBaseResource.copy(dbPath);

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "MainConn");
	db.setDatabaseName(dbPath);
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
