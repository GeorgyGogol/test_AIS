#pragma once

#include <QStatusBar>
#include "DataStruct.h"

class StatusBarOnAIS  : public QStatusBar
{
	Q_OBJECT

public:
	StatusBarOnAIS(QWidget *parent);
	~StatusBarOnAIS();

private:
	//void FillWidgets(cosnt String)

public slots:
	void UpdateData(const our::ProgrammData& data);

};
