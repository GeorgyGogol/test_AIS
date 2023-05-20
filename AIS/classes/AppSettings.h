#pragma once

QT_BEGIN_NAMESPACE
class QTemporaryDir;
template <class Key, class T> class QMap;
QT_END_NAMESPACE

class AppSettings
{
public:
	AppSettings();
	~AppSettings();

private:
	QTemporaryDir* tmpDir;
	QMap<QString, QString>* Settings = nullptr;

	QString copySettingsFile();

public:
	bool init();
	bool recieveSettings();

	QString getSetting(const QString& settingName);

	QSqlQuery* getMenuPlan();
};
