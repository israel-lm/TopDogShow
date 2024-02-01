#pragma once

#include "IDiscipline.h"
#include "PerformanceData.h"
#include "DBHandler.h"

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class MarkTableDiscipline : public Form
	{
	public:
		MarkTableDiscipline(String^ dogName)
		{	
			allCombos = gcnew List<ComboBox^>();
			allTexts = gcnew List<TextBox^>();
			InitializeComponent();
			dogNameLabel->Text = dogName;
			setComboHandlers();
			performanceData = gcnew MarkTablePerformanceData();
			performanceData->dogName = dogName;
			dbHandler = DBHandler::Instance;
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

		System::Windows::Forms::Label^ dogNameLabel;
		System::Windows::Forms::TableLayoutPanel^ markPanel1;
		System::Windows::Forms::TableLayoutPanel^ markPanel2;
		System::Windows::Forms::TableLayoutPanel^ markPanel3;
		System::Windows::Forms::TableLayoutPanel^ markPanel4;
		System::Windows::Forms::TableLayoutPanel^ markPanel5;
		System::Windows::Forms::TableLayoutPanel^ markPanel6;
		System::Windows::Forms::TableLayoutPanel^ markPanel7;
		System::Windows::Forms::TableLayoutPanel^ markPanel8;
		System::Windows::Forms::TableLayoutPanel^ markPanel9;
		System::Windows::Forms::TableLayoutPanel^ markPanel10;

		MarkTablePerformanceData^ performanceData = nullptr;
		DBHandler^ dbHandler;
		List<ComboBox^>^ allCombos;
		List<TextBox^>^ allTexts;

#pragma region Windows Form Designer generated code
		

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MarkTableDiscipline::typeid));
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->mark10Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark10Box);
			this->mark9Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark9Box);
			this->mark8Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark8Box);
			this->mark7Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark7Box);
			this->mark6Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark6Box);
			this->mark5Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark5Box);
			this->mark4Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark4Box);
			this->mark3Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark3Box);
			this->mark2Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark2Box);
			this->mark1Box = (gcnew System::Windows::Forms::TextBox());
			this->allTexts->Add(mark1Box);
			this->marksLabel = (gcnew System::Windows::Forms::Label());
			this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->finishButton = (gcnew System::Windows::Forms::Button());

			this->mark10Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark10Attempt3Combo);
			this->mark10Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark10Attempt2Combo);
			this->mark10Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark10Attempt1Combo);
			this->mark9Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark9Attempt3Combo);
			this->mark9Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark9Attempt2Combo);
			this->mark9Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark9Attempt1Combo);
			this->mark8Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark8Attempt3Combo);
			this->mark8Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark8Attempt2Combo);
			this->mark8Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark8Attempt1Combo);
			this->mark7Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark7Attempt3Combo);
			this->mark7Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark7Attempt2Combo);
			this->mark7Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark7Attempt1Combo);
			this->mark6Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark6Attempt3Combo);
			this->mark6Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark6Attempt2Combo);
			this->mark6Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark6Attempt1Combo);
			this->mark5Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark5Attempt3Combo);
			this->mark5Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark5Attempt2Combo);
			this->mark5Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark5Attempt1Combo);
			this->mark4Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark4Attempt3Combo);
			this->mark4Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark4Attempt2Combo);
			this->mark4Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark4Attempt1Combo);
			this->mark3Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark3Attempt3Combo);
			this->mark3Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark3Attempt2Combo);
			this->mark3Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark3Attempt1Combo);
			this->mark2Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark2Attempt3Combo);
			this->mark2Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark2Attempt2Combo);
			this->mark2Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark2Attempt1Combo);
			this->attemptsLabel = (gcnew System::Windows::Forms::Label());
			this->mark1Attempt3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark1Attempt3Combo);
			this->mark1Attempt2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark1Attempt2Combo);
			this->attempt1Label = (gcnew System::Windows::Forms::Label());
			this->attempt2Label = (gcnew System::Windows::Forms::Label());
			this->attempt3Label = (gcnew System::Windows::Forms::Label());
			this->mark1Attempt1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->allCombos->Add(mark1Attempt1Combo);
			this->dogNameLabel = (gcnew System::Windows::Forms::Label());
			this->markPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->markPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->BeginInit();
			this->markPanel1->SuspendLayout();
			this->markPanel2->SuspendLayout();
			this->markPanel3->SuspendLayout();
			this->markPanel4->SuspendLayout();
			this->markPanel5->SuspendLayout();
			this->markPanel6->SuspendLayout();
			this->markPanel7->SuspendLayout();
			this->markPanel8->SuspendLayout();
			this->markPanel9->SuspendLayout();
			this->markPanel10->SuspendLayout();
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->AutoSize = true;
			this->headerLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->headerLabel->Location = System::Drawing::Point(298, 9);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(330, 44);
			this->headerLabel->TabIndex = 0;
			this->headerLabel->Text = L"DisciplineName";
			// 
			// mark10Box
			// 
			this->mark10Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark10Box->Location = System::Drawing::Point(3, 3);
			this->mark10Box->Name = L"mark10Box";
			this->mark10Box->Size = System::Drawing::Size(50, 35);
			this->mark10Box->TabIndex = 10;
			// 
			// mark9Box
			// 
			this->mark9Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Box->Location = System::Drawing::Point(3, 3);
			this->mark9Box->Name = L"mark9Box";
			this->mark9Box->Size = System::Drawing::Size(50, 35);
			this->mark9Box->TabIndex = 9;
			// 
			// mark8Box
			// 
			this->mark8Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Box->Location = System::Drawing::Point(3, 3);
			this->mark8Box->Name = L"mark8Box";
			this->mark8Box->Size = System::Drawing::Size(50, 35);
			this->mark8Box->TabIndex = 8;
			// 
			// mark7Box
			// 
			this->mark7Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Box->Location = System::Drawing::Point(3, 3);
			this->mark7Box->Name = L"mark7Box";
			this->mark7Box->Size = System::Drawing::Size(50, 35);
			this->mark7Box->TabIndex = 7;
			// 
			// mark6Box
			// 
			this->mark6Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Box->Location = System::Drawing::Point(3, 3);
			this->mark6Box->Name = L"mark6Box";
			this->mark6Box->Size = System::Drawing::Size(50, 35);
			this->mark6Box->TabIndex = 6;
			// 
			// mark5Box
			// 
			this->mark5Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Box->Location = System::Drawing::Point(3, 3);
			this->mark5Box->Name = L"mark5Box";
			this->mark5Box->Size = System::Drawing::Size(50, 35);
			this->mark5Box->TabIndex = 5;
			// 
			// mark4Box
			// 
			this->mark4Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Box->Location = System::Drawing::Point(3, 3);
			this->mark4Box->Name = L"mark4Box";
			this->mark4Box->Size = System::Drawing::Size(50, 35);
			this->mark4Box->TabIndex = 4;
			// 
			// mark3Box
			// 
			this->mark3Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Box->Location = System::Drawing::Point(3, 3);
			this->mark3Box->Name = L"mark3Box";
			this->mark3Box->Size = System::Drawing::Size(50, 35);
			this->mark3Box->TabIndex = 3;
			// 
			// mark2Box
			// 
			this->mark2Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Box->Location = System::Drawing::Point(3, 3);
			this->mark2Box->Name = L"mark2Box";
			this->mark2Box->Size = System::Drawing::Size(50, 35);
			this->mark2Box->TabIndex = 2;
			// 
			// mark1Box
			// 
			this->mark1Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Box->Location = System::Drawing::Point(3, 3);
			this->mark1Box->Name = L"mark1Box";
			this->mark1Box->Size = System::Drawing::Size(50, 35);
			this->mark1Box->TabIndex = 1;
			// 
			// marksLabel
			// 
			this->marksLabel->AutoSize = true;
			this->marksLabel->Location = System::Drawing::Point(32, 163);
			this->marksLabel->Name = L"marksLabel";
			this->marksLabel->Size = System::Drawing::Size(94, 29);
			this->marksLabel->TabIndex = 0;
			this->marksLabel->Text = L"Marks";
			// 
			// dogPicture
			// 
			this->dogPicture->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->dogPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dogPicture.Image")));
			this->dogPicture->Location = System::Drawing::Point(536, 79);
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
			this->cancelButton->Location = System::Drawing::Point(536, 619);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(150, 30);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = false;
			this->cancelButton->Click += gcnew System::EventHandler(this, &MarkTableDiscipline::cancelButton_Click);
			// 
			// finishButton
			// 
			this->finishButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->finishButton->BackColor = System::Drawing::Color::White;
			this->finishButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->finishButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->finishButton->Location = System::Drawing::Point(743, 619);
			this->finishButton->Name = L"finishButton";
			this->finishButton->Size = System::Drawing::Size(150, 30);
			this->finishButton->TabIndex = 5;
			this->finishButton->Text = L"Finish";
			this->finishButton->UseVisualStyleBackColor = false;
			this->finishButton->Click += gcnew System::EventHandler(this, &MarkTableDiscipline::finishButton_Click);
			// 
			// mark10Attempt3Combo
			// 
			this->mark10Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->mark10Attempt3Combo->FormattingEnabled = true;
			this->mark10Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark10Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark10Attempt3Combo->Name = L"mark10Attempt3Combo";
			this->mark10Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark10Attempt3Combo->TabIndex = 32;
			// 
			// mark10Attempt2Combo
			// 
			this->mark10Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->mark10Attempt2Combo->FormattingEnabled = true;
			this->mark10Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark10Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark10Attempt2Combo->Name = L"mark10Attempt2Combo";
			this->mark10Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark10Attempt2Combo->TabIndex = 31;
			// 
			// mark10Attempt1Combo
			// 
			this->mark10Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->mark10Attempt1Combo->FormattingEnabled = true;
			this->mark10Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark10Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark10Attempt1Combo->Name = L"mark10Attempt1Combo";
			this->mark10Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark10Attempt1Combo->TabIndex = 30;
			// 
			// mark9Attempt3Combo
			// 
			this->mark9Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Attempt3Combo->FormattingEnabled = true;
			this->mark9Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark9Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark9Attempt3Combo->Name = L"mark9Attempt3Combo";
			this->mark9Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark9Attempt3Combo->TabIndex = 29;
			// 
			// mark9Attempt2Combo
			// 
			this->mark9Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Attempt2Combo->FormattingEnabled = true;
			this->mark9Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark9Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark9Attempt2Combo->Name = L"mark9Attempt2Combo";
			this->mark9Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark9Attempt2Combo->TabIndex = 28;
			// 
			// mark9Attempt1Combo
			// 
			this->mark9Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark9Attempt1Combo->FormattingEnabled = true;
			this->mark9Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark9Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark9Attempt1Combo->Name = L"mark9Attempt1Combo";
			this->mark9Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark9Attempt1Combo->TabIndex = 27;
			// 
			// mark8Attempt3Combo
			// 
			this->mark8Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Attempt3Combo->FormattingEnabled = true;
			this->mark8Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark8Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark8Attempt3Combo->Name = L"mark8Attempt3Combo";
			this->mark8Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark8Attempt3Combo->TabIndex = 26;
			// 
			// mark8Attempt2Combo
			// 
			this->mark8Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Attempt2Combo->FormattingEnabled = true;
			this->mark8Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark8Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark8Attempt2Combo->Name = L"mark8Attempt2Combo";
			this->mark8Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark8Attempt2Combo->TabIndex = 25;
			// 
			// mark8Attempt1Combo
			// 
			this->mark8Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark8Attempt1Combo->FormattingEnabled = true;
			this->mark8Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark8Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark8Attempt1Combo->Name = L"mark8Attempt1Combo";
			this->mark8Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark8Attempt1Combo->TabIndex = 24;
			// 
			// mark7Attempt3Combo
			// 
			this->mark7Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Attempt3Combo->FormattingEnabled = true;
			this->mark7Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark7Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark7Attempt3Combo->Name = L"mark7Attempt3Combo";
			this->mark7Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark7Attempt3Combo->TabIndex = 23;
			// 
			// mark7Attempt2Combo
			// 
			this->mark7Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Attempt2Combo->FormattingEnabled = true;
			this->mark7Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark7Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark7Attempt2Combo->Name = L"mark7Attempt2Combo";
			this->mark7Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark7Attempt2Combo->TabIndex = 22;
			// 
			// mark7Attempt1Combo
			// 
			this->mark7Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark7Attempt1Combo->FormattingEnabled = true;
			this->mark7Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark7Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark7Attempt1Combo->Name = L"mark7Attempt1Combo";
			this->mark7Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark7Attempt1Combo->TabIndex = 21;
			// 
			// mark6Attempt3Combo
			// 
			this->mark6Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Attempt3Combo->FormattingEnabled = true;
			this->mark6Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark6Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark6Attempt3Combo->Name = L"mark6Attempt3Combo";
			this->mark6Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark6Attempt3Combo->TabIndex = 20;
			// 
			// mark6Attempt2Combo
			// 
			this->mark6Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Attempt2Combo->FormattingEnabled = true;
			this->mark6Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark6Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark6Attempt2Combo->Name = L"mark6Attempt2Combo";
			this->mark6Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark6Attempt2Combo->TabIndex = 19;
			// 
			// mark6Attempt1Combo
			// 
			this->mark6Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark6Attempt1Combo->FormattingEnabled = true;
			this->mark6Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark6Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark6Attempt1Combo->Name = L"mark6Attempt1Combo";
			this->mark6Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark6Attempt1Combo->TabIndex = 18;
			// 
			// mark5Attempt3Combo
			// 
			this->mark5Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Attempt3Combo->FormattingEnabled = true;
			this->mark5Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark5Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark5Attempt3Combo->Name = L"mark5Attempt3Combo";
			this->mark5Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark5Attempt3Combo->TabIndex = 17;
			// 
			// mark5Attempt2Combo
			// 
			this->mark5Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Attempt2Combo->FormattingEnabled = true;
			this->mark5Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark5Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark5Attempt2Combo->Name = L"mark5Attempt2Combo";
			this->mark5Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark5Attempt2Combo->TabIndex = 16;
			// 
			// mark5Attempt1Combo
			// 
			this->mark5Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark5Attempt1Combo->FormattingEnabled = true;
			this->mark5Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark5Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark5Attempt1Combo->Name = L"mark5Attempt1Combo";
			this->mark5Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark5Attempt1Combo->TabIndex = 15;
			// 
			// mark4Attempt3Combo
			// 
			this->mark4Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Attempt3Combo->FormattingEnabled = true;
			this->mark4Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark4Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark4Attempt3Combo->Name = L"mark4Attempt3Combo";
			this->mark4Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark4Attempt3Combo->TabIndex = 14;
			// 
			// mark4Attempt2Combo
			// 
			this->mark4Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Attempt2Combo->FormattingEnabled = true;
			this->mark4Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark4Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark4Attempt2Combo->Name = L"mark4Attempt2Combo";
			this->mark4Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark4Attempt2Combo->TabIndex = 13;
			// 
			// mark4Attempt1Combo
			// 
			this->mark4Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark4Attempt1Combo->FormattingEnabled = true;
			this->mark4Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark4Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark4Attempt1Combo->Name = L"mark4Attempt1Combo";
			this->mark4Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark4Attempt1Combo->TabIndex = 12;
			// 
			// mark3Attempt3Combo
			// 
			this->mark3Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Attempt3Combo->FormattingEnabled = true;
			this->mark3Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark3Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark3Attempt3Combo->Name = L"mark3Attempt3Combo";
			this->mark3Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark3Attempt3Combo->TabIndex = 11;
			// 
			// mark3Attempt2Combo
			// 
			this->mark3Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Attempt2Combo->FormattingEnabled = true;
			this->mark3Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark3Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark3Attempt2Combo->Name = L"mark3Attempt2Combo";
			this->mark3Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark3Attempt2Combo->TabIndex = 10;
			// 
			// mark3Attempt1Combo
			// 
			this->mark3Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark3Attempt1Combo->FormattingEnabled = true;
			this->mark3Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark3Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark3Attempt1Combo->Name = L"mark3Attempt1Combo";
			this->mark3Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark3Attempt1Combo->TabIndex = 9;
			// 
			// mark2Attempt3Combo
			// 
			this->mark2Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Attempt3Combo->FormattingEnabled = true;
			this->mark2Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark2Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark2Attempt3Combo->Name = L"mark2Attempt3Combo";
			this->mark2Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark2Attempt3Combo->TabIndex = 8;
			// 
			// mark2Attempt2Combo
			// 
			this->mark2Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Attempt2Combo->FormattingEnabled = true;
			this->mark2Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark2Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark2Attempt2Combo->Name = L"mark2Attempt2Combo";
			this->mark2Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark2Attempt2Combo->TabIndex = 7;
			// 
			// mark2Attempt1Combo
			// 
			this->mark2Attempt1Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark2Attempt1Combo->FormattingEnabled = true;
			this->mark2Attempt1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark2Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark2Attempt1Combo->Name = L"mark2Attempt1Combo";
			this->mark2Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark2Attempt1Combo->TabIndex = 6;
			// 
			// attemptsLabel
			// 
			this->attemptsLabel->AutoSize = true;
			this->attemptsLabel->Location = System::Drawing::Point(191, 124);
			this->attemptsLabel->Name = L"attemptsLabel";
			this->attemptsLabel->Size = System::Drawing::Size(137, 29);
			this->attemptsLabel->TabIndex = 0;
			this->attemptsLabel->Text = L"Attempts";
			// 
			// mark1Attempt3Combo
			// 
			this->mark1Attempt3Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Attempt3Combo->FormattingEnabled = true;
			this->mark1Attempt3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark1Attempt3Combo->Location = System::Drawing::Point(294, 3);
			this->mark1Attempt3Combo->Name = L"mark1Attempt3Combo";
			this->mark1Attempt3Combo->Size = System::Drawing::Size(88, 37);
			this->mark1Attempt3Combo->TabIndex = 5;
			// 
			// mark1Attempt2Combo
			// 
			this->mark1Attempt2Combo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mark1Attempt2Combo->FormattingEnabled = true;
			this->mark1Attempt2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Success", L"Failure" });
			this->mark1Attempt2Combo->Location = System::Drawing::Point(182, 3);
			this->mark1Attempt2Combo->Name = L"mark1Attempt2Combo";
			this->mark1Attempt2Combo->Size = System::Drawing::Size(88, 37);
			this->mark1Attempt2Combo->TabIndex = 4;
			// 
			// attempt1Label
			// 
			this->attempt1Label->BackColor = System::Drawing::Color::White;
			this->attempt1Label->ForeColor = System::Drawing::Color::Black;
			this->attempt1Label->Location = System::Drawing::Point(107, 163);
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
			this->attempt2Label->Location = System::Drawing::Point(219, 163);
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
			this->attempt3Label->Location = System::Drawing::Point(331, 163);
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
			this->mark1Attempt1Combo->Location = System::Drawing::Point(70, 3);
			this->mark1Attempt1Combo->Name = L"mark1Attempt1Combo";
			this->mark1Attempt1Combo->Size = System::Drawing::Size(88, 37);
			this->mark1Attempt1Combo->TabIndex = 3;
			// 
			// dogNameLabel
			// 
			this->dogNameLabel->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dogNameLabel->AutoSize = true;
			this->dogNameLabel->Location = System::Drawing::Point(542, 524);
			this->dogNameLabel->Name = L"dogNameLabel";
			this->dogNameLabel->Size = System::Drawing::Size(151, 29);
			this->dogNameLabel->TabIndex = 7;
			this->dogNameLabel->Text = L"Dog Name";
			// 
			// markPanel1
			// 
			this->markPanel1->ColumnCount = 4;
			this->markPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel1->Controls->Add(this->mark1Box, 0, 0);
			this->markPanel1->Controls->Add(this->mark1Attempt1Combo, 1, 0);
			this->markPanel1->Controls->Add(this->mark1Attempt2Combo, 2, 0);
			this->markPanel1->Controls->Add(this->mark1Attempt3Combo, 3, 0);
			this->markPanel1->Location = System::Drawing::Point(37, 205);
			this->markPanel1->Name = L"markPanel1";
			this->markPanel1->RowCount = 1;
			this->markPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel1->Size = System::Drawing::Size(404, 39);
			this->markPanel1->TabIndex = 8;
			// 
			// markPanel2
			// 
			this->markPanel2->ColumnCount = 4;
			this->markPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel2->Controls->Add(this->mark2Box, 0, 0);
			this->markPanel2->Controls->Add(this->mark2Attempt1Combo, 1, 0);
			this->markPanel2->Controls->Add(this->mark2Attempt2Combo, 2, 0);
			this->markPanel2->Controls->Add(this->mark2Attempt3Combo, 3, 0);
			this->markPanel2->Location = System::Drawing::Point(37, 250);
			this->markPanel2->Name = L"markPanel2";
			this->markPanel2->RowCount = 1;
			this->markPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel2->Size = System::Drawing::Size(404, 39);
			this->markPanel2->TabIndex = 9;
			// 
			// markPanel3
			// 
			this->markPanel3->ColumnCount = 4;
			this->markPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel3->Controls->Add(this->mark3Box, 0, 0);
			this->markPanel3->Controls->Add(this->mark3Attempt1Combo, 1, 0);
			this->markPanel3->Controls->Add(this->mark3Attempt2Combo, 2, 0);
			this->markPanel3->Controls->Add(this->mark3Attempt3Combo, 3, 0);
			this->markPanel3->Location = System::Drawing::Point(37, 295);
			this->markPanel3->Name = L"markPanel3";
			this->markPanel3->RowCount = 1;
			this->markPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel3->Size = System::Drawing::Size(404, 39);
			this->markPanel3->TabIndex = 10;
			// 
			// markPanel4
			// 
			this->markPanel4->ColumnCount = 4;
			this->markPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel4->Controls->Add(this->mark4Box, 0, 0);
			this->markPanel4->Controls->Add(this->mark4Attempt1Combo, 1, 0);
			this->markPanel4->Controls->Add(this->mark4Attempt2Combo, 2, 0);
			this->markPanel4->Controls->Add(this->mark4Attempt3Combo, 3, 0);
			this->markPanel4->Location = System::Drawing::Point(37, 340);
			this->markPanel4->Name = L"markPanel4";
			this->markPanel4->RowCount = 1;
			this->markPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel4->Size = System::Drawing::Size(404, 39);
			this->markPanel4->TabIndex = 11;
			// 
			// markPanel5
			// 
			this->markPanel5->ColumnCount = 4;
			this->markPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel5->Controls->Add(this->mark5Box, 0, 0);
			this->markPanel5->Controls->Add(this->mark5Attempt1Combo, 1, 0);
			this->markPanel5->Controls->Add(this->mark5Attempt2Combo, 2, 0);
			this->markPanel5->Controls->Add(this->mark5Attempt3Combo, 3, 0);
			this->markPanel5->Location = System::Drawing::Point(37, 385);
			this->markPanel5->Name = L"markPanel5";
			this->markPanel5->RowCount = 1;
			this->markPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel5->Size = System::Drawing::Size(404, 39);
			this->markPanel5->TabIndex = 12;
			// 
			// markPanel6
			// 
			this->markPanel6->ColumnCount = 4;
			this->markPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel6->Controls->Add(this->mark6Box, 0, 0);
			this->markPanel6->Controls->Add(this->mark6Attempt1Combo, 1, 0);
			this->markPanel6->Controls->Add(this->mark6Attempt2Combo, 2, 0);
			this->markPanel6->Controls->Add(this->mark6Attempt3Combo, 3, 0);
			this->markPanel6->Location = System::Drawing::Point(37, 430);
			this->markPanel6->Name = L"markPanel6";
			this->markPanel6->RowCount = 1;
			this->markPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel6->Size = System::Drawing::Size(404, 39);
			this->markPanel6->TabIndex = 13;
			// 
			// markPanel7
			// 
			this->markPanel7->ColumnCount = 4;
			this->markPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel7->Controls->Add(this->mark7Box, 0, 0);
			this->markPanel7->Controls->Add(this->mark7Attempt1Combo, 1, 0);
			this->markPanel7->Controls->Add(this->mark7Attempt2Combo, 2, 0);
			this->markPanel7->Controls->Add(this->mark7Attempt3Combo, 3, 0);
			this->markPanel7->Location = System::Drawing::Point(37, 475);
			this->markPanel7->Name = L"markPanel7";
			this->markPanel7->RowCount = 1;
			this->markPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel7->Size = System::Drawing::Size(404, 39);
			this->markPanel7->TabIndex = 14;
			// 
			// markPanel8
			// 
			this->markPanel8->ColumnCount = 4;
			this->markPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel8->Controls->Add(this->mark8Box, 0, 0);
			this->markPanel8->Controls->Add(this->mark8Attempt1Combo, 1, 0);
			this->markPanel8->Controls->Add(this->mark8Attempt2Combo, 2, 0);
			this->markPanel8->Controls->Add(this->mark8Attempt3Combo, 3, 0);
			this->markPanel8->Location = System::Drawing::Point(37, 520);
			this->markPanel8->Name = L"markPanel8";
			this->markPanel8->RowCount = 1;
			this->markPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel8->Size = System::Drawing::Size(404, 39);
			this->markPanel8->TabIndex = 15;
			// 
			// markPanel9
			// 
			this->markPanel9->ColumnCount = 4;
			this->markPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel9->Controls->Add(this->mark9Box, 0, 0);
			this->markPanel9->Controls->Add(this->mark9Attempt1Combo, 1, 0);
			this->markPanel9->Controls->Add(this->mark9Attempt2Combo, 2, 0);
			this->markPanel9->Controls->Add(this->mark9Attempt3Combo, 3, 0);
			this->markPanel9->Location = System::Drawing::Point(37, 565);
			this->markPanel9->Name = L"markPanel9";
			this->markPanel9->RowCount = 1;
			this->markPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel9->Size = System::Drawing::Size(404, 39);
			this->markPanel9->TabIndex = 16;
			// 
			// markPanel10
			// 
			this->markPanel10->ColumnCount = 4;
			this->markPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->markPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.77778F)));
			this->markPanel10->Controls->Add(this->mark10Attempt3Combo, 3, 0);
			this->markPanel10->Controls->Add(this->mark10Box, 0, 0);
			this->markPanel10->Controls->Add(this->mark10Attempt2Combo, 2, 0);
			this->markPanel10->Controls->Add(this->mark10Attempt1Combo, 1, 0);
			this->markPanel10->Location = System::Drawing::Point(37, 610);
			this->markPanel10->Name = L"markPanel10";
			this->markPanel10->RowCount = 1;
			this->markPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->markPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->markPanel10->Size = System::Drawing::Size(404, 39);
			this->markPanel10->TabIndex = 17;
			// 
			// MarkTableDiscipline
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(905, 668);
			this->Controls->Add(this->marksLabel);
			this->Controls->Add(this->markPanel10);
			this->Controls->Add(this->markPanel9);
			this->Controls->Add(this->markPanel8);
			this->Controls->Add(this->markPanel7);
			this->Controls->Add(this->markPanel6);
			this->Controls->Add(this->markPanel5);
			this->Controls->Add(this->markPanel4);
			this->Controls->Add(this->markPanel3);
			this->Controls->Add(this->markPanel2);
			this->Controls->Add(this->markPanel1);
			this->Controls->Add(this->dogNameLabel);
			this->Controls->Add(this->finishButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->dogPicture);
			this->Controls->Add(this->headerLabel);
			this->Controls->Add(this->attempt1Label);
			this->Controls->Add(this->attempt2Label);
			this->Controls->Add(this->attempt3Label);
			this->Controls->Add(this->attemptsLabel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->MinimumSize = System::Drawing::Size(830, 630);
			this->Name = L"MarkTableDiscipline";
			this->Text = L"Top Dog Show";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->EndInit();
			this->markPanel1->ResumeLayout(false);
			this->markPanel1->PerformLayout();
			this->markPanel2->ResumeLayout(false);
			this->markPanel2->PerformLayout();
			this->markPanel3->ResumeLayout(false);
			this->markPanel3->PerformLayout();
			this->markPanel4->ResumeLayout(false);
			this->markPanel4->PerformLayout();
			this->markPanel5->ResumeLayout(false);
			this->markPanel5->PerformLayout();
			this->markPanel6->ResumeLayout(false);
			this->markPanel6->PerformLayout();
			this->markPanel7->ResumeLayout(false);
			this->markPanel7->PerformLayout();
			this->markPanel8->ResumeLayout(false);
			this->markPanel8->PerformLayout();
			this->markPanel9->ResumeLayout(false);
			this->markPanel9->PerformLayout();
			this->markPanel10->ResumeLayout(false);
			this->markPanel10->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		resetFields();
		this->Close();
	}

	System::Void finishButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (performanceData)
		{
			if (headerLabel->Text == L"High Jump")
				dbHandler->saveHighJumpResults(performanceData);
			else
				dbHandler->saveWallClimbResults(performanceData);
		}
		else
			MessageBox::Show(
				"No performance data",
				"Information error",
				MessageBoxButtons::OK
			);
		resetFields();
		this->Close();
	}

	void resetFields()
	{
		for each (TextBox^ text in allTexts)
		{
			if (text)
				text->Text = "";
		}

		for each (ComboBox^ box in allCombos)
		{
			if (box)
				box->SelectedIndex = -1;
		}
	}

	System::Void setComboHandlers()
	{
		for each (ComboBox^ box in allCombos)
		{
			if (box)
				box->SelectedIndexChanged += gcnew System::EventHandler(this, &MarkTableDiscipline::enterAttempt);
		}	
	}

	int getMarkFromControl(Control^ control)
	{
		int mark = 0;
		try
		{
			mark = (int)(Convert::ToDouble(control->Text) * 100); //convert to cm
		}
		catch (Exception^ e) {}
		return mark;
	}

	void updateAttemptsAndResult(Control^ control, int& attempts, bool& result)
	{
		ComboBox^ currentBox = (ComboBox^)control;
		int selectedIndex = currentBox->SelectedIndex;
		if (selectedIndex > -1)
		{
			attempts++;
			if (selectedIndex == 0)
			{
				result = true;
				return;
			}
		}
	}

	System::Void enterAttempt(System::Object^ sender, System::EventArgs^ e)
	{
		ComboBox^ box = (ComboBox^)sender;

		if (box && box->SelectedIndex >= 0)
		{
			TableLayoutPanel^ currentPanel = (TableLayoutPanel^)box->Parent;
			if (currentPanel)
			{
				int controlIndex = 0;
				int mark = 0;
				int attempts = 0;
				bool positiveResult = false;

				for each (Control ^ control in currentPanel->Controls)
				{
					if (control->Text != "")
					{
						switch (controlIndex)
						{
						case 0: // read the mark
							mark = getMarkFromControl(control);
							break;
						case 1: // read result of 1st attempt
						case 2: // read result of 2nd attempt
						case 3: //read result of 3rd attempt
							updateAttemptsAndResult(control, attempts, positiveResult);
							break;
						}
					}
					controlIndex++;
				}

				if (performanceData)
				{
					if (!performanceData->marks->ContainsKey(mark))
					{
						MarksData^ data = gcnew MarksData();
						performanceData->marks[mark] = data;
					}
					performanceData->marks[mark]->attempts = attempts;
					performanceData->marks[mark]->result = positiveResult;
				}
			}
		}
	}
};
}
