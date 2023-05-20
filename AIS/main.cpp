#include "stdafx.h"
#include <QtWidgets/QApplication>
#include "AIS.h"
#include "AppSettings.h"
#include "ProgrammData.h"
#include "Login.h"

bool RegisterDatabase(AppSettings* settings);
bool Auth(const QString& password);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	our::ProgrammData* pd = nullptr;

	/// Иницилизируем БД с настройками АИС из ресурсов во временную директорию
	std::unique_ptr<AppSettings> settings (new AppSettings);
	settings->init();
	if (!settings->recieveSettings()) {
		QMessageBox::critical(nullptr, "Ошибка настроек!", "Файл конфигурации не загружен!");
		return 101;
	}

	/// Получим инфу об основной БД
	if (!RegisterDatabase(settings.get())) {
		QMessageBox::critical(nullptr, "Ошибка настроек!", "Сервер не настроен!");
		return 102;
	}

	/// Запросим пароль для входа
	QString password;
	if (argc < 2) {
		std::unique_ptr<forms::Login> login (forms::Login::createPasswordOnly());
		if (login->exec() == forms::Login::Rejected) return 0;
		password = login->getPassword();
	}
	else {
		password = QString(argv[1]);
	}

	/// TODO: Аутентификация
	if (!Auth(password)) {
		QMessageBox::critical(nullptr, "Ошибка входа!", "Введен неверный пароль!");
		return 103;
	}

	/// Получим план построения меню АИС
	std::unique_ptr<QSqlQuery> menu (settings->getMenuPlan());
	if (!menu.get() || menu->lastError().isValid()) {
		if (menu.get() && menu->lastError().isValid()) DBG_PRINT(menu->lastError().text());
		QMessageBox::critical(nullptr, "Ошибка ресурсов!", "Не получен ответ конфигурации АИС!");
		return 104;
	}

	/// TODO: Обновление

	/// Создадим форму
    AIS ais(menu.get(), pd ? *pd : our::ProgrammData());

	// Тут чистим память
	settings.reset(nullptr);
	menu.reset(nullptr);

	/// Запуск проложения
    ais.show();
    return app.exec();
}

bool RegisterDatabase(AppSettings* settings)
{
	QSqlDatabase db = QSqlDatabase::addDatabase(settings->getSetting("ServerDriver"), "MainConn");
	db.setDatabaseName(settings->getSetting("ServerName"));
	return db.open();
}

bool Auth(const QString& password)
{
	/// TODO: Аутентификация
	return true;
}