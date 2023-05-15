#include "stdafx.h"
#include "TestLib.h"

TestLib::TestLib()
{
}

void TestLib::ShowTestForm()
{
	QMessageBox::information(this, "title", "call some form (dll)");
}
