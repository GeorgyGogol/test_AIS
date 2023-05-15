#include "TestLib.h"

extern "C" {
	void __declspec(dllexport)ShowTestForm() {
		TestLib lib;
	}
}
