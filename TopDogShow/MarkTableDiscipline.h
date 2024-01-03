#pragma once

#include "IDiscipline.h"

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MarkTableDiscipline : public Form, public IDiscipline
	{
	public:
		MarkTableDiscipline(void)
		{
			InitializeComponent();
		}

		virtual void saveMarks() {}

	protected:
		System::Windows::Forms::Label^ headerLabel;

		~MarkTableDiscipline()
		{
			if (components)
			{
				delete components;
			}
		}

	private:		
		System::Windows::Forms::Panel^ marksPanel;
		System::Windows::Forms::PictureBox^ dogPicture;
		System::Windows::Forms::Button^ cancelButton;
		System::Windows::Forms::Button^ finishButton;
		System::Windows::Forms::TextBox^ mark10Box;
		System::Windows::Forms::TextBox^ mark9Box;
		System::Windows::Forms::TextBox^ mark8Box;
		System::Windows::Forms::TextBox^ mark7Box;
		System::Windows::Forms::TextBox^ mark6Box;
		System::Windows::Forms::TextBox^ mark5Box;
		System::Windows::Forms::TextBox^ mark4Box;
		System::Windows::Forms::TextBox^ mark3Box;
		System::Windows::Forms::TextBox^ mark2Box;
		System::Windows::Forms::TextBox^ mark1Box;
		System::Windows::Forms::Label^ marksLabel;
		System::Windows::Forms::Panel^ attemptsPanel;
		System::Windows::Forms::Label^ attemptsLabel;
		System::Windows::Forms::Label^ attempt1Label;
		System::Windows::Forms::Label^ attempt3Label;
		System::Windows::Forms::Label^ attempt2Label;
		System::Windows::Forms::ComboBox^ mark1Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark1Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark1Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark5Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark5Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark4Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark4Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark4Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark3Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark3Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark3Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark2Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark2Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark2Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark10Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark10Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark10Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark9Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark9Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark9Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark8Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark8Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark8Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark7Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark7Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark7Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark6Attempt3Combo;
		System::Windows::Forms::ComboBox^ mark6Attempt2Combo;
		System::Windows::Forms::ComboBox^ mark6Attempt1Combo;
		System::Windows::Forms::ComboBox^ mark5Attempt3Combo;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MarkTableDiscipline::typeid));
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->marksPanel = (gcnew System::Windows::Forms::Panel());
			this->mark10Box = (gcnew System::Windows::Forms::TextBox());
			this->mark9Box = (gcnew System::Windows::Forms::TextBox());
			this->mark8Box = (gcnew System::Windows::Forms::TextBox());
			this->mark7Box = (gcnew System::Windows::Forms::TextBox());
			this->mark6Box = (gcnew System::Windows::Forms::TextBox());
			this->mark5Box = (gcnew System::Windows::Forms::TextBox());
			this->mark4Box = (gcnew System::Windows::Forms::TextBox());
			this->mark3Box = (gcnew System::Windows::Forms::TextBox());
			this->mark2Box = (gcnew System::Windows::Forms::TextBox());
			this->mark1Box = (gcnew System::Windows::Forms::TextBox());
			this->marksLabel = (gcnew System::Windows::Forms::Label());
			this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->finishButton = (gcnew System::Windows::Forms::Button());
			this->attemptsPanel = (gcnew System::Windows::Forms::Panel());
			this->attemptsLabel = (gcnew System::Windows::Forms::Label());
			this->attempt1Label = (gcnew System::Windows::Forms::Label());
			this->attempt2Label = (gcnew System::Windows::Forms::Label());
			this->attempt3Label = (gcnew System::Windows::Forms::Label());
			this->mark1Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark1Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark1Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark2Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark2Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark2Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark3Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark3Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark3Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark4Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark4Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark4Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark5Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark5Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark5Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark6Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark6Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark6Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark7Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark7Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark7Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark8Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark8Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark8Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark9Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark9Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark9Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark10Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark10Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->mark10Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->marksPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->BeginInit();
			this->attemptsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->AutoSize = true;
			this->headerLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->headerLabel->Location = System::Drawing::Point(353, 26);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(220, 29);
			this->headerLabel->TabIndex = 0;
			this->headerLabel->Text = L"DisciplineName";
			// 
			// marksPanel
			// 
			this->marksPanel->Controls->Add(this->mark10Box);
			this->marksPanel->Controls->Add(this->mark9Box);
			this->marksPanel->Controls->Add(this->mark8Box);
			this->marksPanel->Controls->Add(this->mark7Box);
			this->marksPanel->Controls->Add(this->mark6Box);
			this->marksPanel->Controls->Add(this->mark5Box);
			this->marksPanel->Controls->Add(this->mark4Box);
			this->marksPanel->Controls->Add(this->mark3Box);
			this->marksPanel->Controls->Add(this->mark2Box);
			this->marksPanel->Controls->Add(this->mark1Box);
			this->marksPanel->Controls->Add(this->marksLabel);
			this->marksPanel->Location = System::Drawing::Point(19, 126);
			this->marksPanel->Name = L"marksPanel";
			this->marksPanel->Size = System::Drawing::Size(66, 450);
			this->marksPanel->TabIndex = 2;
			// 
			// mark10Box
			// 
			this->mark10Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark10Box->Location = System::Drawing::Point(3, 418);
			this->mark10Box->Name = L"mark10Box";
			this->mark10Box->Size = System::Drawing::Size(50, 26);
			this->mark10Box->TabIndex = 10;
			// 
			// mark9Box
			// 
			this->mark9Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Box->Location = System::Drawing::Point(3, 375);
			this->mark9Box->Name = L"mark9Box";
			this->mark9Box->Size = System::Drawing::Size(50, 26);
			this->mark9Box->TabIndex = 9;
			// 
			// mark8Box
			// 
			this->mark8Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Box->Location = System::Drawing::Point(3, 332);
			this->mark8Box->Name = L"mark8Box";
			this->mark8Box->Size = System::Drawing::Size(50, 26);
			this->mark8Box->TabIndex = 8;
			// 
			// mark7Box
			// 
			this->mark7Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Box->Location = System::Drawing::Point(3, 289);
			this->mark7Box->Name = L"mark7Box";
			this->mark7Box->Size = System::Drawing::Size(50, 26);
			this->mark7Box->TabIndex = 7;
			// 
			// mark6Box
			// 
			this->mark6Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Box->Location = System::Drawing::Point(3, 246);
			this->mark6Box->Name = L"mark6Box";
			this->mark6Box->Size = System::Drawing::Size(50, 26);
			this->mark6Box->TabIndex = 6;
			// 
			// mark5Box
			// 
			this->mark5Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Box->Location = System::Drawing::Point(3, 203);
			this->mark5Box->Name = L"mark5Box";
			this->mark5Box->Size = System::Drawing::Size(50, 26);
			this->mark5Box->TabIndex = 5;
			// 
			// mark4Box
			// 
			this->mark4Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Box->Location = System::Drawing::Point(3, 160);
			this->mark4Box->Name = L"mark4Box";
			this->mark4Box->Size = System::Drawing::Size(50, 26);
			this->mark4Box->TabIndex = 4;
			// 
			// mark3Box
			// 
			this->mark3Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Box->Location = System::Drawing::Point(3, 117);
			this->mark3Box->Name = L"mark3Box";
			this->mark3Box->Size = System::Drawing::Size(50, 26);
			this->mark3Box->TabIndex = 3;
			// 
			// mark2Box
			// 
			this->mark2Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Box->Location = System::Drawing::Point(3, 74);
			this->mark2Box->Name = L"mark2Box";
			this->mark2Box->Size = System::Drawing::Size(50, 26);
			this->mark2Box->TabIndex = 2;
			// 
			// mark1Box
			// 
			this->mark1Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Box->Location = System::Drawing::Point(3, 31);
			this->mark1Box->Name = L"mark1Box";
			this->mark1Box->Size = System::Drawing::Size(50, 26);
			this->mark1Box->TabIndex = 1;
			// 
			// marksLabel
			// 
			this->marksLabel->AutoSize = true;
			this->marksLabel->Location = System::Drawing::Point(3, 10);
			this->marksLabel->Name = L"marksLabel";
			this->marksLabel->Size = System::Drawing::Size(61, 18);
			this->marksLabel->TabIndex = 0;
			this->marksLabel->Text = L"Marks";
			// 
			// dogPicture
			// 
			this->dogPicture->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->dogPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dogPicture.Image")));
			this->dogPicture->Location = System::Drawing::Point(452, 79);
			this->dogPicture->Name = L"dogPicture";
			this->dogPicture->Size = System::Drawing::Size(357, 428);
			this->dogPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->dogPicture->TabIndex = 3;
			this->dogPicture->TabStop = false;
			// 
			// cancelButton
			// 
			this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cancelButton->BackColor = System::Drawing::Color::White;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->cancelButton->Location = System::Drawing::Point(452, 546);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(150, 30);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			// 
			// finishButton
			// 
			this->finishButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->finishButton->BackColor = System::Drawing::Color::White;
			this->finishButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->finishButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->finishButton->Location = System::Drawing::Point(659, 546);
			this->finishButton->Name = L"finishButton";
			this->finishButton->Size = System::Drawing::Size(150, 30);
			this->finishButton->TabIndex = 5;
			this->finishButton->Text = L"Finish";
			this->finishButton->UseVisualStyleBackColor = false;
			// 
			// attemptsPanel
			// 
			this->attemptsPanel->Controls->Add(this->mark10Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark10Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark10Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark9Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark9Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark9Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark8Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark8Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark8Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark7Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark7Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark7Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark6Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark6Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark6Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark5Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark5Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark5Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark4Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark4Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark4Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark3Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark3Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark3Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->mark2Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark2Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->mark2Attempt1Combo);
			this->attemptsPanel->Controls->Add(this->attemptsLabel);
			this->attemptsPanel->Controls->Add(this->mark1Attempt3Combo);
			this->attemptsPanel->Controls->Add(this->mark1Attempt2Combo);
			this->attemptsPanel->Controls->Add(this->attempt1Label);
			this->attemptsPanel->Controls->Add(this->attempt2Label);
			this->attemptsPanel->Controls->Add(this->attempt3Label);
			this->attemptsPanel->Controls->Add(this->mark1Attempt1Combo);
			this->attemptsPanel->Location = System::Drawing::Point(91, 79);
			this->attemptsPanel->Name = L"attemptsPanel";
			this->attemptsPanel->Size = System::Drawing::Size(324, 497);
			this->attemptsPanel->TabIndex = 6;
			// 
			// attemptsLabel
			// 
			this->attemptsLabel->AutoSize = true;
			this->attemptsLabel->Location = System::Drawing::Point(113, 6);
			this->attemptsLabel->Name = L"attemptsLabel";
			this->attemptsLabel->Size = System::Drawing::Size(88, 18);
			this->attemptsLabel->TabIndex = 0;
			this->attemptsLabel->Text = L"Attempts";
			// 
			// attempt1Label
			// 
			this->attempt1Label->BackColor = System::Drawing::Color::White;
			this->attempt1Label->ForeColor = System::Drawing::Color::Black;
			this->attempt1Label->Location = System::Drawing::Point(0, 37);
			this->attempt1Label->Name = L"attempt1Label";
			this->attempt1Label->Size = System::Drawing::Size(88, 39);
			this->attempt1Label->TabIndex = 0;
			this->attempt1Label->Text = L"1";
			this->attempt1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// attempt2Label
			// 
			this->attempt2Label->BackColor = System::Drawing::Color::White;
			this->attempt2Label->ForeColor = System::Drawing::Color::Black;
			this->attempt2Label->Location = System::Drawing::Point(113, 37);
			this->attempt2Label->Name = L"attempt2Label";
			this->attempt2Label->Size = System::Drawing::Size(88, 39);
			this->attempt2Label->TabIndex = 1;
			this->attempt2Label->Text = L"2";
			this->attempt2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// attempt3Label
			// 
			this->attempt3Label->BackColor = System::Drawing::Color::White;
			this->attempt3Label->ForeColor = System::Drawing::Color::Black;
			this->attempt3Label->Location = System::Drawing::Point(229, 37);
			this->attempt3Label->Name = L"attempt3Label";
			this->attempt3Label->Size = System::Drawing::Size(88, 39);
			this->attempt3Label->TabIndex = 2;
			this->attempt3Label->Text = L"3";
			this->attempt3Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// mark1Attempt1Combo
			// 
			this->mark1Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Attempt1Combo->FormattingEnabled = true;
			this->mark1Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark1Attempt1Combo->Location = System::Drawing::Point(0, 79);
			this->mark1Attempt1Combo->Name = L"mark1Attempt1Combo";
			this->mark1Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark1Attempt1Combo->TabIndex = 3;
			// 
			// mark1Attempt2Combo
			// 
			this->mark1Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Attempt2Combo->FormattingEnabled = true;
			this->mark1Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark1Attempt2Combo->Location = System::Drawing::Point(113, 80);
			this->mark1Attempt2Combo->Name = L"mark1Attempt2Combo";
			this->mark1Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark1Attempt2Combo->TabIndex = 4;
			// 
			// mark1Attempt3Combo
			// 
			this->mark1Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Attempt3Combo->FormattingEnabled = true;
			this->mark1Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark1Attempt3Combo->Location = System::Drawing::Point(229, 80);
			this->mark1Attempt3Combo->Name = L"mark1Attempt3Combo";
			this->mark1Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark1Attempt3Combo->TabIndex = 5;
			// 
			// mark2Attempt1Combo
			// 
			this->mark2Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Attempt1Combo->FormattingEnabled = true;
			this->mark2Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark2Attempt1Combo->Location = System::Drawing::Point(0, 122);
			this->mark2Attempt1Combo->Name = L"mark2Attempt1Combo";
			this->mark2Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark2Attempt1Combo->TabIndex = 6;
			// 
			// mark2Attempt2Combo
			// 
			this->mark2Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Attempt2Combo->FormattingEnabled = true;
			this->mark2Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark2Attempt2Combo->Location = System::Drawing::Point(113, 122);
			this->mark2Attempt2Combo->Name = L"mark2Attempt2Combo";
			this->mark2Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark2Attempt2Combo->TabIndex = 7;
			// 
			// mark2Attempt3Combo
			// 
			this->mark2Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Attempt3Combo->FormattingEnabled = true;
			this->mark2Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark2Attempt3Combo->Location = System::Drawing::Point(229, 121);
			this->mark2Attempt3Combo->Name = L"mark2Attempt3Combo";
			this->mark2Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark2Attempt3Combo->TabIndex = 8;
			// 
			// mark3Attempt1Combo
			// 
			this->mark3Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Attempt1Combo->FormattingEnabled = true;
			this->mark3Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark3Attempt1Combo->Location = System::Drawing::Point(0, 165);
			this->mark3Attempt1Combo->Name = L"mark3Attempt1Combo";
			this->mark3Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark3Attempt1Combo->TabIndex = 9;
			// 
			// mark3Attempt2Combo
			// 
			this->mark3Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Attempt2Combo->FormattingEnabled = true;
			this->mark3Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark3Attempt2Combo->Location = System::Drawing::Point(113, 165);
			this->mark3Attempt2Combo->Name = L"mark3Attempt2Combo";
			this->mark3Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark3Attempt2Combo->TabIndex = 10;
			// 
			// mark3Attempt3Combo
			// 
			this->mark3Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Attempt3Combo->FormattingEnabled = true;
			this->mark3Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark3Attempt3Combo->Location = System::Drawing::Point(229, 165);
			this->mark3Attempt3Combo->Name = L"mark3Attempt3Combo";
			this->mark3Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark3Attempt3Combo->TabIndex = 11;
			// 
			// mark4Attempt1Combo
			// 
			this->mark4Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Attempt1Combo->FormattingEnabled = true;
			this->mark4Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark4Attempt1Combo->Location = System::Drawing::Point(0, 208);
			this->mark4Attempt1Combo->Name = L"mark4Attempt1Combo";
			this->mark4Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark4Attempt1Combo->TabIndex = 12;
			// 
			// mark4Attempt2Combo
			// 
			this->mark4Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Attempt2Combo->FormattingEnabled = true;
			this->mark4Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark4Attempt2Combo->Location = System::Drawing::Point(113, 208);
			this->mark4Attempt2Combo->Name = L"mark4Attempt2Combo";
			this->mark4Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark4Attempt2Combo->TabIndex = 13;
			// 
			// mark4Attempt3Combo
			// 
			this->mark4Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Attempt3Combo->FormattingEnabled = true;
			this->mark4Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark4Attempt3Combo->Location = System::Drawing::Point(229, 208);
			this->mark4Attempt3Combo->Name = L"mark4Attempt3Combo";
			this->mark4Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark4Attempt3Combo->TabIndex = 14;
			// 
			// mark5Attempt1Combo
			// 
			this->mark5Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Attempt1Combo->FormattingEnabled = true;
			this->mark5Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark5Attempt1Combo->Location = System::Drawing::Point(0, 251);
			this->mark5Attempt1Combo->Name = L"mark5Attempt1Combo";
			this->mark5Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark5Attempt1Combo->TabIndex = 15;
			// 
			// mark5Attempt2Combo
			// 
			this->mark5Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Attempt2Combo->FormattingEnabled = true;
			this->mark5Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark5Attempt2Combo->Location = System::Drawing::Point(113, 251);
			this->mark5Attempt2Combo->Name = L"mark5Attempt2Combo";
			this->mark5Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark5Attempt2Combo->TabIndex = 16;
			// 
			// mark5Attempt3Combo
			// 
			this->mark5Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Attempt3Combo->FormattingEnabled = true;
			this->mark5Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark5Attempt3Combo->Location = System::Drawing::Point(229, 251);
			this->mark5Attempt3Combo->Name = L"mark5Attempt3Combo";
			this->mark5Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark5Attempt3Combo->TabIndex = 17;
			// 
			// mark6Attempt1Combo
			// 
			this->mark6Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Attempt1Combo->FormattingEnabled = true;
			this->mark6Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark6Attempt1Combo->Location = System::Drawing::Point(0, 294);
			this->mark6Attempt1Combo->Name = L"mark6Attempt1Combo";
			this->mark6Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark6Attempt1Combo->TabIndex = 18;
			// 
			// mark6Attempt2Combo
			// 
			this->mark6Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Attempt2Combo->FormattingEnabled = true;
			this->mark6Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark6Attempt2Combo->Location = System::Drawing::Point(113, 294);
			this->mark6Attempt2Combo->Name = L"mark6Attempt2Combo";
			this->mark6Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark6Attempt2Combo->TabIndex = 19;
			// 
			// mark6Attempt3Combo
			// 
			this->mark6Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Attempt3Combo->FormattingEnabled = true;
			this->mark6Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark6Attempt3Combo->Location = System::Drawing::Point(229, 294);
			this->mark6Attempt3Combo->Name = L"mark6Attempt3Combo";
			this->mark6Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark6Attempt3Combo->TabIndex = 20;
			// 
			// mark7Attempt1Combo
			// 
			this->mark7Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Attempt1Combo->FormattingEnabled = true;
			this->mark7Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark7Attempt1Combo->Location = System::Drawing::Point(0, 337);
			this->mark7Attempt1Combo->Name = L"mark7Attempt1Combo";
			this->mark7Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark7Attempt1Combo->TabIndex = 21;
			// 
			// mark7Attempt2Combo
			// 
			this->mark7Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Attempt2Combo->FormattingEnabled = true;
			this->mark7Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark7Attempt2Combo->Location = System::Drawing::Point(113, 336);
			this->mark7Attempt2Combo->Name = L"mark7Attempt2Combo";
			this->mark7Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark7Attempt2Combo->TabIndex = 22;
			// 
			// mark7Attempt3Combo
			// 
			this->mark7Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Attempt3Combo->FormattingEnabled = true;
			this->mark7Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark7Attempt3Combo->Location = System::Drawing::Point(229, 337);
			this->mark7Attempt3Combo->Name = L"mark7Attempt3Combo";
			this->mark7Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark7Attempt3Combo->TabIndex = 23;
			// 
			// mark8Attempt1Combo
			// 
			this->mark8Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Attempt1Combo->FormattingEnabled = true;
			this->mark8Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark8Attempt1Combo->Location = System::Drawing::Point(0, 380);
			this->mark8Attempt1Combo->Name = L"mark8Attempt1Combo";
			this->mark8Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark8Attempt1Combo->TabIndex = 24;
			// 
			// mark8Attempt2Combo
			// 
			this->mark8Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Attempt2Combo->FormattingEnabled = true;
			this->mark8Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark8Attempt2Combo->Location = System::Drawing::Point(113, 379);
			this->mark8Attempt2Combo->Name = L"mark8Attempt2Combo";
			this->mark8Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark8Attempt2Combo->TabIndex = 25;
			// 
			// mark8Attempt3Combo
			// 
			this->mark8Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Attempt3Combo->FormattingEnabled = true;
			this->mark8Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark8Attempt3Combo->Location = System::Drawing::Point(229, 380);
			this->mark8Attempt3Combo->Name = L"mark8Attempt3Combo";
			this->mark8Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark8Attempt3Combo->TabIndex = 26;
			// 
			// mark9Attempt1Combo
			// 
			this->mark9Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Attempt1Combo->FormattingEnabled = true;
			this->mark9Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark9Attempt1Combo->Location = System::Drawing::Point(0, 423);
			this->mark9Attempt1Combo->Name = L"mark9Attempt1Combo";
			this->mark9Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark9Attempt1Combo->TabIndex = 27;
			// 
			// mark9Attempt2Combo
			// 
			this->mark9Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Attempt2Combo->FormattingEnabled = true;
			this->mark9Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark9Attempt2Combo->Location = System::Drawing::Point(113, 423);
			this->mark9Attempt2Combo->Name = L"mark9Attempt2Combo";
			this->mark9Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark9Attempt2Combo->TabIndex = 28;
			// 
			// mark9Attempt3Combo
			// 
			this->mark9Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Attempt3Combo->FormattingEnabled = true;
			this->mark9Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark9Attempt3Combo->Location = System::Drawing::Point(229, 423);
			this->mark9Attempt3Combo->Name = L"mark9Attempt3Combo";
			this->mark9Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark9Attempt3Combo->TabIndex = 29;
			// 
			// mark10Attempt1Combo
			// 
			this->mark10Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->mark10Attempt1Combo->FormattingEnabled = true;
			this->mark10Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark10Attempt1Combo->Location = System::Drawing::Point(3, 465);
			this->mark10Attempt1Combo->Name = L"mark10Attempt1Combo";
			this->mark10Attempt1Combo->Size = System::Drawing::Size(88, 28);
			this->mark10Attempt1Combo->TabIndex = 30;
			// 
			// mark10Attempt2Combo
			// 
			this->mark10Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->mark10Attempt2Combo->FormattingEnabled = true;
			this->mark10Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark10Attempt2Combo->Location = System::Drawing::Point(113, 465);
			this->mark10Attempt2Combo->Name = L"mark10Attempt2Combo";
			this->mark10Attempt2Combo->Size = System::Drawing::Size(88, 28);
			this->mark10Attempt2Combo->TabIndex = 31;
			// 
			// mark10Attempt3Combo
			// 
			this->mark10Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->mark10Attempt3Combo->FormattingEnabled = true;
			this->mark10Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark10Attempt3Combo->Location = System::Drawing::Point(229, 465);
			this->mark10Attempt3Combo->Name = L"mark10Attempt3Combo";
			this->mark10Attempt3Combo->Size = System::Drawing::Size(88, 28);
			this->mark10Attempt3Combo->TabIndex = 32;
			// 
			// MarkTableDiscipline
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(821, 595);
			this->Controls->Add(this->attemptsPanel);
			this->Controls->Add(this->finishButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->dogPicture);
			this->Controls->Add(this->marksPanel);
			this->Controls->Add(this->headerLabel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->MinimumSize = System::Drawing::Size(830, 630);
			this->Name = L"MarkTableDiscipline";
			this->Text = L"Top Dog Show";
			this->marksPanel->ResumeLayout(false);
			this->marksPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->EndInit();
			this->attemptsPanel->ResumeLayout(false);
			this->attemptsPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
};
}
