#pragma once

#include "testlib_global.h"
#include "DataStruct.h"

class TESTLIB_EXPORT TestLib
{
public:
    TestLib(const our::ProgrammData& data);

private:
	const our::ProgrammData CallerData;

public:
	void ShowTestForm();
};


