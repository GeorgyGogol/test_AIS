#include "stdafx.h"
#include "TestLib.h"

extern "C" {
	void __declspec(dllexport)ShowTestForm(const our::ProgrammData& data) {
		TestLib lib(data);
		lib.ShowTestForm();
	}
}
