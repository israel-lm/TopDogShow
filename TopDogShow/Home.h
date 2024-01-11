#pragma once

#include "PreDiscipline.h"
#include "Results.h"
#include "Registration.h"
#include "Treadmil.h"

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
		{
			InitializeComponent();
			preDisciplineScreen = gcnew PreDiscipline();
			resultsScreen = gcnew Results();
			disciplineFactory = DisciplineFactory::getInstance();
		}

	protected:
		~Home()
		{
			if (components)
				delete components;

			if (disciplineFactory)
				delete disciplineFactory;
		}

	private: 
		System::Windows::Forms::Label^ headerLabel;
		System::Windows::Forms::Button^ wallClimbButton;
		System::Windows::Forms::Button^ highJumpButton;
		System::Windows::Forms::Button^ longJumpButton;
		System::Windows::Forms::Button^ treadmilButton;
		System::Windows::Forms::Button^ registrationButton;
		System::Windows::Forms::Button^ configButton;
		System::Windows::Forms::Button^ leaveButton;
		System::Windows::Forms::ComboBox^ comboBox1;
		System::Windows::Forms::Label^ resultsLabel;
		System::ComponentModel::Container ^components;

		PreDiscipline^ preDisciplineScreen;
		Form^ treadmilScreen;
		Results^ resultsScreen;
		Registration^ registrationScreen;

		DisciplineFactory* disciplineFactory;

		System::Void wallClimbButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			preDisciplineScreen->setDisciplineType(DisciplineType::WallClimb);
			preDisciplineScreen->ShowDialog();
		}
		System::Void highJumpButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			preDisciplineScreen->setDisciplineType(DisciplineType::HighJump);
			preDisciplineScreen->ShowDialog();
		}
		System::Void longJumpButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			preDisciplineScreen->setDisciplineType(DisciplineType::LongJump);
			preDisciplineScreen->ShowDialog();
		}
		System::Void treadmilButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			treadmilScreen = disciplineFactory->createDiscipline(DisciplineType::Treadmil);
			treadmilScreen->Show();
		}
		System::Void leaveButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
		System::Void registrationButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			registrationScreen = gcnew Registration();
			registrationScreen->Show();
		}
		void InitializeComponent(void)
		{
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->wallClimbButton = (gcnew System::Windows::Forms::Button());
			this->highJumpButton = (gcnew System::Windows::Forms::Button());
			this->longJumpButton = (gcnew System::Windows::Forms::Button());
			this->treadmilButton = (gcnew System::Windows::Forms::Button());
			this->registrationButton = (gcnew System::Windows::Forms::Button());
			this->configButton = (gcnew System::Windows::Forms::Button());
			this->leaveButton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->resultsLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->headerLabel->ForeColor = System::Drawing::Color::White;
			this->headerLabel->Location = System::Drawing::Point(12, 9);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(554, 68);
			this->headerLabel->TabIndex = 1;
			this->headerLabel->Text = L"Top Dog Show";
			this->headerLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wallClimbButton
			// 
			this->wallClimbButton->BackColor = System::Drawing::Color::White;
			this->wallClimbButton->Location = System::Drawing::Point(19, 155);
			this->wallClimbButton->Name = L"wallClimbButton";
			this->wallClimbButton->Size = System::Drawing::Size(138, 79);
			this->wallClimbButton->TabIndex = 2;
			this->wallClimbButton->Text = L"Wall Climb";
			this->wallClimbButton->UseVisualStyleBackColor = false;
			this->wallClimbButton->Click += gcnew System::EventHandler(this, &Home::wallClimbButton_Click);
			// 
			// highJumpButton
			// 
			this->highJumpButton->BackColor = System::Drawing::Color::White;
			this->highJumpButton->Location = System::Drawing::Point(183, 155);
			this->highJumpButton->Name = L"highJumpButton";
			this->highJumpButton->Size = System::Drawing::Size(138, 79);
			this->highJumpButton->TabIndex = 3;
			this->highJumpButton->Text = L"High Jump";
			this->highJumpButton->UseVisualStyleBackColor = false;
			this->highJumpButton->Click += gcnew System::EventHandler(this, &Home::highJumpButton_Click);
			// 
			// longJumpButton
			// 
			this->longJumpButton->BackColor = System::Drawing::Color::White;
			this->longJumpButton->Location = System::Drawing::Point(19, 261);
			this->longJumpButton->Name = L"longJumpButton";
			this->longJumpButton->Size = System::Drawing::Size(138, 79);
			this->longJumpButton->TabIndex = 4;
			this->longJumpButton->Text = L"Long Jump";
			this->longJumpButton->UseVisualStyleBackColor = false;
			this->longJumpButton->Click += gcnew System::EventHandler(this, &Home::longJumpButton_Click);
			// 
			// treadmilButton
			// 
			this->treadmilButton->BackColor = System::Drawing::Color::White;
			this->treadmilButton->Location = System::Drawing::Point(183, 261);
			this->treadmilButton->Name = L"treadmilButton";
			this->treadmilButton->Size = System::Drawing::Size(138, 79);
			this->treadmilButton->TabIndex = 5;
			this->treadmilButton->Text = L"Treadmil";
			this->treadmilButton->UseVisualStyleBackColor = false;
			this->treadmilButton->Click += gcnew System::EventHandler(this, &Home::treadmilButton_Click);
			// 
			// registrationButton
			// 
			this->registrationButton->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->registrationButton->BackColor = System::Drawing::Color::White;
			this->registrationButton->Location = System::Drawing::Point(419, 225);
			this->registrationButton->Name = L"registrationButton";
			this->registrationButton->Size = System::Drawing::Size(138, 50);
			this->registrationButton->TabIndex = 7;
			this->registrationButton->Text = L"Registration";
			this->registrationButton->UseVisualStyleBackColor = false;
			this->registrationButton->Click += gcnew System::EventHandler(this, &Home::registrationButton_Click);
			// 
			// configButton
			// 
			this->configButton->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->configButton->BackColor = System::Drawing::Color::White;
			this->configButton->Location = System::Drawing::Point(419, 152);
			this->configButton->Name = L"configButton";
			this->configButton->Size = System::Drawing::Size(138, 50);
			this->configButton->TabIndex = 8;
			this->configButton->Text = L"Configuration";
			this->configButton->UseVisualStyleBackColor = false;
			// 
			// leaveButton
			// 
			this->leaveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->leaveButton->BackColor = System::Drawing::Color::White;
			this->leaveButton->Location = System::Drawing::Point(419, 467);
			this->leaveButton->Name = L"leaveButton";
			this->leaveButton->Size = System::Drawing::Size(138, 50);
			this->leaveButton->TabIndex = 9;
			this->leaveButton->Text = L"Leave";
			this->leaveButton->UseVisualStyleBackColor = false;
			this->leaveButton->Click += gcnew System::EventHandler(this, &Home::leaveButton_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(20, 414);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(273, 28);
			this->comboBox1->TabIndex = 10;
			// 
			// resultsLabel
			// 
			this->resultsLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->resultsLabel->AutoSize = true;
			this->resultsLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->resultsLabel->ForeColor = System::Drawing::Color::White;
			this->resultsLabel->Location = System::Drawing::Point(15, 370);
			this->resultsLabel->Name = L"resultsLabel";
			this->resultsLabel->Size = System::Drawing::Size(112, 29);
			this->resultsLabel->TabIndex = 12;
			this->resultsLabel->Text = L"Results";
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(578, 544);
			this->Controls->Add(this->resultsLabel);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->leaveButton);
			this->Controls->Add(this->configButton);
			this->Controls->Add(this->registrationButton);
			this->Controls->Add(this->treadmilButton);
			this->Controls->Add(this->longJumpButton);
			this->Controls->Add(this->highJumpButton);
			this->Controls->Add(this->wallClimbButton);
			this->Controls->Add(this->headerLabel);
			this->MaximumSize = System::Drawing::Size(600, 600);
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"Home";
			this->Text = L"Top Dog Show";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
};
}
