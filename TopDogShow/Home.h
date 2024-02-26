#pragma once

#include "PreDiscipline.h"
#include "Results.h"
#include "Registration.h"
#include "Treadmill.h"
#include "Competitors.h"

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
			disciplineFactory = DisciplineFactory::getInstance();
			dbHandler = DBHandler::Instance;
			competitors = Competitors::Instance;
			setResultOptions();
		}

	protected:
		~Home()
		{
			if (components)
			if (components)
				delete components;

			if (disciplineFactory)
				delete disciplineFactory;

			if (dbHandler)
				delete dbHandler;

			if (competitors)
				delete competitors;
		}

	private: 
		System::Windows::Forms::Label^ headerLabel;
		System::Windows::Forms::Button^ wallClimbButton;
		System::Windows::Forms::Button^ highJumpButton;
		System::Windows::Forms::Button^ longJumpButton;
		System::Windows::Forms::Button^ TreadmillButton;
		System::Windows::Forms::Button^ registrationButton;
		System::Windows::Forms::Button^ configButton;
		System::Windows::Forms::Button^ leaveButton;
		System::Windows::Forms::ComboBox^ resultsBox;
		System::Windows::Forms::Label^ resultsLabel;
		System::ComponentModel::Container ^components;

		PreDiscipline^ preDisciplineScreen;
		Form^ TreadmillScreen;
		Registration^ registrationScreen;

		DisciplineFactory* disciplineFactory;

		DBHandler^ dbHandler;
		Competitors^ competitors;

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
		System::Void TreadmillButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			TreadmillScreen = disciplineFactory->createDiscipline(DisciplineType::Treadmill, nullptr);
			TreadmillScreen->Show();
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

		void setResultOptions()
		{
			array<Object^>^ options = gcnew array<Object^>(4);
			options[0] = "General";
			options[1] = "Category Lightweight";
			options[2] = "Category Mediumweight";
			options[3] = "Category Heavyweight";

			resultsBox->Items->AddRange(options);
		}

		System::Void resultsBox_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e)
		{
			ComboBox^ box = (ComboBox^)sender;
			if (box && box->SelectedIndex >= 0)
			{
				String^ option = (String^)box->SelectedItem;
				ResultType resultType;
				String^ category = nullptr;
				switch (box->SelectedIndex)
				{
				case 0:
					resultType = ResultType::GENERAL;
					break;
				case 1:
					resultType = ResultType::CATEGORY;
					category = Categories::LIGHT_WEIGHT;
					break;
				case 2:
					resultType = ResultType::CATEGORY;
					category = Categories::MIDDLE_WEIGHT;
					break;
				case 3:
					resultType = ResultType::CATEGORY;
					category = Categories::HEAVY_WEIGHT;
					break;
				}
				Results^ resultsScreen = gcnew Results(resultType, category);
				resultsScreen->ShowDialog();
			}
		}

		void InitializeComponent(void)
		{
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->wallClimbButton = (gcnew System::Windows::Forms::Button());
			this->highJumpButton = (gcnew System::Windows::Forms::Button());
			this->longJumpButton = (gcnew System::Windows::Forms::Button());
			this->TreadmillButton = (gcnew System::Windows::Forms::Button());
			this->registrationButton = (gcnew System::Windows::Forms::Button());
			this->configButton = (gcnew System::Windows::Forms::Button());
			this->leaveButton = (gcnew System::Windows::Forms::Button());
			this->resultsBox = (gcnew System::Windows::Forms::ComboBox());
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
			// TreadmillButton
			// 
			this->TreadmillButton->BackColor = System::Drawing::Color::White;
			this->TreadmillButton->Location = System::Drawing::Point(183, 261);
			this->TreadmillButton->Name = L"TreadmillButton";
			this->TreadmillButton->Size = System::Drawing::Size(138, 79);
			this->TreadmillButton->TabIndex = 5;
			this->TreadmillButton->Text = L"Treadmill";
			this->TreadmillButton->UseVisualStyleBackColor = false;
			this->TreadmillButton->Click += gcnew System::EventHandler(this, &Home::TreadmillButton_Click);
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
			// resultsBox
			// 
			this->resultsBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->resultsBox->FormattingEnabled = true;
			this->resultsBox->Location = System::Drawing::Point(20, 414);
			this->resultsBox->Name = L"resultsBox";
			this->resultsBox->Size = System::Drawing::Size(273, 28);
			this->resultsBox->TabIndex = 10;
			this->resultsBox->SelectedValueChanged += gcnew System::EventHandler(this, &Home::resultsBox_SelectedValueChanged);
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
			this->Controls->Add(this->resultsBox);
			this->Controls->Add(this->leaveButton);
			this->Controls->Add(this->configButton);
			this->Controls->Add(this->registrationButton);
			this->Controls->Add(this->TreadmillButton);
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
