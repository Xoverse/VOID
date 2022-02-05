#pragma once
#include "rainbow.h"

namespace xVOID
{
	using namespace System;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	public ref class mainForm : public Form
	{
	public:
		mainForm()
		{
			InitializeComponent();
		}
	protected:
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		Reflection::Assembly^ pxAssembly = Reflection::Assembly::GetExecutingAssembly();
		String^ pxResName = pxAssembly->GetName()->Name + ".Ressources";
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(pxResName, pxAssembly);

		String^ text = "";

		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ label1 = gcnew Label();

		void InitializeComponent()
		{
#pragma region mainForm
			this->components = gcnew System::ComponentModel::Container();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Size = System::Drawing::Size(
				Screen::PrimaryScreen->Bounds.Width,
				Screen::PrimaryScreen->Bounds.Height);
			this->BackColor = Color::Black;
			this->TopMost = true;
			this->Load += gcnew EventHandler(this, &mainForm::mainForm_Load);
			this->FormClosing += gcnew FormClosingEventHandler(this, &mainForm::mainForm_FormClosing);
			this->KeyDown += gcnew KeyEventHandler(this, &mainForm::mainForm_KeyDown);
#pragma endregion mainForm
#pragma region label1
			label1->Size = this->Size;
			label1->Location = Point(0, 0);
			label1->ForeColor = Color::White;
			label1->Font = gcnew System::Drawing::Font("Arial", 20);
			label1->TextAlign = ContentAlignment::MiddleCenter;
			label1->Text = "CHARA IS HERE\n\n" +
				"the Xoverse took over your PC,\n" +
				"you might not be able to recover it without an expert";
			label1->Visible = true;
#pragma endregion label1

			this->Controls->Add(label1);
		}

		void mainForm_Load(Object^ sender, EventArgs^ e)
		{
			Media::SoundPlayer^ music = gcnew Media::SoundPlayer(rm->GetStream("But_Nobody_Came"));
			music->PlayLooping();

			float best_size = 100;
			int wid = label1->DisplayRectangle.Width - 3;
			int hgt = label1->DisplayRectangle.Height - 3;
			Graphics^ gr = label1->CreateGraphics();

			for(float i = 1; i <= 100; i++)
			{
				System::Drawing::Font^ tf = gcnew System::Drawing::Font("Arial", i);
				SizeF^ text_size = gr->MeasureString(label1->Text, tf);
				if ((text_size->Width > wid) ||
					(text_size->Height > hgt))
				{
					best_size = i - 1;
					break;
				}
			}

			label1->Font = gcnew System::Drawing::Font("Arial", best_size);
		}

		void mainForm_FormClosing(Object^ sender, FormClosingEventArgs^ e)
		{
			e->Cancel = true;
		}

		void mainForm_KeyDown(Object^ sender, KeyEventArgs^ e)
		{
			if (e->KeyCode != Keys::F4 || e->KeyCode != Keys::Alt)
			{
				if (text == "" && e->KeyCode == Keys::A)
				{
					text = "a";
				}
				else if(text == "a" && e->KeyCode == Keys::W)
				{
					text = "aw";
				}
				else if (text == "aw" && e->KeyCode == Keys::E)
				{
					text = "awe";
				}
				else if (text == "awe" && e->KeyCode == Keys::S)
				{
					text = "awes";
				}
				else if (text == "awes" && e->KeyCode == Keys::O)
				{
					text = "aweso";
				}
				else if (text == "aweso" && e->KeyCode == Keys::M)
				{
					text = "awesom";
				}
				else if (text == "awesom" && e->KeyCode == Keys::E)
				{
					text = "";
					(gcnew xVOID::rainbow())->Show();
				}
				else
				{
					text = "";
				}
			}
		}
	};
}