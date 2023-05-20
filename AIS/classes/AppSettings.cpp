#include "stdafx.h"
#include "AppSettings.h"

#include <QMap>

AppSettings::AppSettings()
{
	QSqlDatabase::addDatabase("QSQLITE", "SettingsConnection");

#ifndef PLACE_TMP_FILES_IN_CURRENT_DIR
	tmpDir = new QTemporaryDir;
	tmpDir->setAutoRemove(true);
#endif
}

AppSettings::~AppSettings()
{
	QSqlDatabase::database("SettingsConnection").close();
#ifndef PLACE_TMP_FILES_IN_CURRENT_DIR
	delete tmpDir;
#endif
}

QString AppSettings::copySettingsFile()
{
	QString DBPath;
#ifdef PLACE_TMP_FILES_IN_CURRENT_DIR
	DBPath = QDir::currentPath() + "/tmp/MenuMap";
#else
	DBPath = tmpDir->path() + "/MenuMap";
#endif
	QFile dataBaseResource(":/AIS/MenuMap");
	dataBaseResource.copy(DBPath);
	return DBPath;
}

bool AppSettings::recieveSettings()
{
	if (Settings) return true;

	std::unique_ptr<QSqlQuery> qr(new QSqlQuery("SELECT * FROM AIS_Settings", QSqlDatabase::database("SettingsConnection")));

	if (qr->exec()) {
		Settings = new QMap<QString, QString>;
		while (qr->next())
		{
			Settings->insert(qr->value("Setting").toString(), qr->value("Value").toString());
		}
	}
	return Settings;
}

bool AppSettings::init()
{
	QString path = copySettingsFile();

	QSqlDatabase db = QSqlDatabase::database("SettingsConnection");
	db.setDatabaseName(path);

	DBG_PRINT(db.databaseName());

	return db.open();
}

QString AppSettings::getSetting(const QString& settingName)
{
	if (!recieveSettings()) return QString();

	return Settings->value(settingName);
}

QSqlQuery* AppSettings::getMenuPlan()
{
	QSqlQuery* qr = new QSqlQuery("SELECT * FROM AIS_Menu", QSqlDatabase::database("SettingsConnection"));
	qr->exec();
	return qr;
}
