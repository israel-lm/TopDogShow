#pragma once
#include "DisciplineFactory.h"
#include "Constants.h"
#include "Competitors.h"

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	public ref class PreDiscipline : public System::Windows::Forms::Form
	{
	public:
		PreDiscipline(void)
		{
			disciplineFactory = DisciplineFactory::getInstance();
			disciplineType = DisciplineType::Undefined;
			competitors = Competitors::Instance;
			InitializeComponent();
		}

		void setDisciplineType(DisciplineType type)
		{
			disciplineType = type;
		}

	protected:

		~PreDiscipline()
		{
			if (components)
				delete components;		

			if (disciplineFactory)
				delete disciplineFactory;
		}
	private:
		System::Windows::Forms::Label^ headerLabel;
		System::Windows::Forms::Label^ categoryLabel;
		System::Windows::Forms::Label^ dogLabel;
		System::Windows::Forms::ComboBox^ categoryCombo;
		System::Windows::Forms::ComboBox^ dogCombo;
		System::Windows::Forms::Button^ startButton;
		System::Windows::Forms::Button^ cancelButton;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->categoryLabel = (gcnew System::Windows::Forms::Label());
			this->dogLabel = (gcnew System::Windows::Forms::Label());
			this->categoryCombo = (gcnew System::Windows::Forms::ComboBox());
			this->dogCombo = (gcnew System::Windows::Forms::ComboBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->AutoSize = true;
			this->headerLabel->Location = System::Drawing::Point(22, 19);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(514, 44);
			this->headerLabel->TabIndex = 0;
			this->headerLabel->Text = L"Select Category and Dog";
			// 
			// categoryLabel
			// 
			this->categoryLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->categoryLabel->AutoSize = true;
			this->categoryLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->categoryLabel->Location = System::Drawing::Point(24, 147);
			this->categoryLabel->Name = L"categoryLabel";
			this->categoryLabel->Size = System::Drawing::Size(134, 29);
			this->categoryLabel->TabIndex = 1;
			this->categoryLabel->Text = L"Category";
			// 
			// dogLabel
			// 
			this->dogLabel->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->dogLabel->AutoSize = true;
			this->dogLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dogLabel->Location = System::Drawing::Point(24, 254);
			this->dogLabel->Name = L"dogLabel";
			this->dogLabel->Size = System::Drawing::Size(66, 29);
			this->dogLabel->TabIndex = 2;
			this->dogLabel->Text = L"Dog";
			// 
			// categoryCombo
			// 
			this->categoryCombo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->categoryCombo->FormattingEnabled = true;
			this->categoryCombo->Location = System::Drawing::Point(27, 179);
			this->categoryCombo->Name = L"categoryCombo";
			this->categoryCombo->Size = System::Drawing::Size(494, 52);
			this->categoryCombo->TabIndex = 3;
			// 
			// dogCombo
			// 
			this->dogCombo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->dogCombo->FormattingEnabled = true;
			this->dogCombo->Location = System::Drawing::Point(27, 286);
			this->dogCombo->Name = L"dogCombo";
			this->dogCombo->Size = System::Drawing::Size(494, 52);
			this->dogCombo->TabIndex = 4;
			// 
			// startButton
			// 
			this->startButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->startButton->BackColor = System::Drawing::Color::White;
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->startButton->Location = System::Drawing::Point(388, 412);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(133, 43);
			this->startButton->TabIndex = 5;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = false;
			this->startButton->Click += gcnew System::EventHandler(this, &PreDiscipline::startButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cancelButton->BackColor = System::Drawing::Color::White;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->cancelButton->Location = System::Drawing::Point(236, 412);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(133, 43);
			this->cancelButton->TabIndex = 6;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			// 
			// PreDiscipline
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(25, 44);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(538, 474);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->dogCombo);
			this->Controls->Add(this->categoryCombo);
			this->Controls->Add(this->dogLabel);
			this->Controls->Add(this->categoryLabel);
			this->Controls->Add(this->headerLabel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->MinimumSize = System::Drawing::Size(560, 530);
			this->Name = L"PreDiscipline";
			this->Text = L"Top Dog Show";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		DisciplineFactory* disciplineFactory = nullptr;
		DisciplineType disciplineType;
		Competitors^ competitors;
		
		System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if ((disciplineType != DisciplineType::Undefined) && disciplineFactory)
			{
				Form^ discipline = disciplineFactory->createDiscipline(disciplineType);
				discipline->TopMost = true;
				discipline->Show();
				this->Close();
			}
			else
			{
				//TODO: log and error out
			}	
			
		}
};
}
