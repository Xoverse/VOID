#pragma once
#include "interface.h"

namespace xVOID
{
	using namespace System;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	public ref class rainbow : public Form
	{
	public:
		rainbow()
		{
			InitializeComponent();
		}
	protected:
		~rainbow()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		int H = 0;

		System::ComponentModel::Container^ components;
		System::Windows::Forms::Timer^ timer1 = gcnew System::Windows::Forms::Timer();

		void InitializeComponent()
		{
#pragma region rainbow
			this->components = gcnew System::ComponentModel::Container();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Size = System::Drawing::Size(
				Screen::PrimaryScreen->Bounds.Width,
				Screen::PrimaryScreen->Bounds.Height);
			this->BackColor = Color::White;
			this->Opacity = 0.25;
			this->TopMost = true;
#pragma endregion rainbow
#pragma region timer1
			timer1->Enabled = true;
			timer1->Interval = 1;
			timer1->Tick += gcnew EventHandler(this, &rainbow::timer1_Tick);
#pragma endregion timer1
		}

		void timer1_Tick(Object^ sender, EventArgs^ e)
		{
			H += 1;

			if (H > 360)
			{
				H = 0;
			}

			this->BackColor = ColorFromHSV(H, 1, 1);
		}
	};
}