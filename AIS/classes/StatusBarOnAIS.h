#pragma once

#include "ProgrammData.h"

QT_BEGIN_NAMESPACE
class QWidget;
class QStatusBar;
QT_END_NAMESPACE

class StatusBarOnAIS  : public QStatusBar
{
	Q_OBJECT

public:
	StatusBarOnAIS(QWidget *parent);
	~StatusBarOnAIS();

public slots:
	void UpdateData(const our::ProgrammData& data);

};
