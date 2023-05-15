#pragma once

#include <QtWidgets/QWidget>
#include "ui_AIS.h"
#include "DataStruct.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AISClass; };
QT_END_NAMESPACE

class AIS : public QMainWindow
{
    Q_OBJECT

public:
	AIS(QSqlQuery* menu);
    ~AIS();

private:
    Ui::AISClass *ui;
	our::ProgrammData Data;

public slots:
	void on_action_About_triggered();
	void on_action_UpdateAIS_triggered();

	void call_Form(const char* moduleName, const char* function);

};
