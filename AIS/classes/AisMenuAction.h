#pragma once

#include <QAction>

class AisMenuAction  : public QAction
{
	Q_OBJECT

public:
	AisMenuAction(QWidget *parent, const QSqlRecord& actionInfo);
	~AisMenuAction();

private:
	QString ModuleName;
	QString Function;

public:
signals:
	void call(const char* moduleName, const char* function);

public slots:
	void emitCall();

};
