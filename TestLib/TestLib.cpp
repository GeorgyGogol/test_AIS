#include "stdafx.h"
#include "TestLib.h"

TestLib::TestLib(const our::ProgrammData& data) :
	CallerData(data)
{
}

void TestLib::ShowTestForm()
{
	QMessageBox::information(nullptr, "title", "call some form (dll)");
}
