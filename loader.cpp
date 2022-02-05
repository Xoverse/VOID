#include "loader.h"

using namespace System;

extern "C"
__declspec(dllexport)
int
__cdecl

run(array<String^>^ args)
{
	xVOID::load(args);
}