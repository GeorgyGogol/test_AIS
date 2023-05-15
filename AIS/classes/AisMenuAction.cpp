#include "stdafx.h"
#include "AisMenuAction.h"

AisMenuAction::AisMenuAction(QWidget *parent, const QSqlRecord& actionInfo)
	: QAction(parent)
{
	setText(actionInfo.value("DisplayName").toString());
	ModuleName = actionInfo.value("ModuleName").toString();
	Function = actionInfo.value("ModuleFunction").toString();

	if (actionInfo.value("isCallAction").toBool())
		connect(this, &AisMenuAction::triggered, this, &AisMenuAction::emitCall);
}

AisMenuAction::~AisMenuAction()
{}

void AisMenuAction::emitCall()
{
	emit call(ModuleName.toStdString().c_str(), Function.toStdString().c_str());
}

