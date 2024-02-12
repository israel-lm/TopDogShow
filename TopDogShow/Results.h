#pragma once

#include "DBHandler.h"
#include "Competitors.h"

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum class ResultType
	{
		GENERAL = 1,
		CATEGORY = 10
	};

	private ref class Rank
	{
	public:
		String^ name;
		int place;
		int points;
	};

	public ref class Results : public System::Windows::Forms::Form
	{
	public:
		Results()
		{
			InitializeComponent();
			dbHandler = DBHandler::Instance;
			competitors = Competitors::Instance;

			if (dbHandler)
			{
				wallClimbResults = dbHandler->getWallClimbResults();
				highJumpResults = dbHandler->getHighJumpResults();
				longJumpResults = dbHandler->getLongJumpResults();
				treadmillResults = dbHandler->getTreadmillResults();
			}
		}

		void showResults(ResultType type, Categories^ category)
		{
			switch (type)
			{
			case ResultType::GENERAL:
				showGeneralResults();
				break;
			case ResultType::CATEGORY:
				showResultsByCategory(category);
				break;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Results()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Label^ headerLabel;
		System::Windows::Forms::Button^ printButton;
		System::Windows::Forms::Button^ exitButton;
		System::Windows::Forms::DataGridView^ resultGrid;
		System::Windows::Forms::DataGridViewTextBoxColumn^ placing;
		System::Windows::Forms::DataGridViewTextBoxColumn^ dogName;
		System::Windows::Forms::DataGridViewTextBoxColumn^ points;
		System::ComponentModel::Container ^components;

		DBHandler^ dbHandler = nullptr;
		Competitors^ competitors = nullptr;
		Dictionary<String^, MarkTablePerformanceData^>^ wallClimbResults = nullptr;
		Dictionary<String^, MarkTablePerformanceData^>^ highJumpResults = nullptr;
		Dictionary<String^, LongJumpPerformanceData^>^ longJumpResults = nullptr;
		Dictionary<String^, TreadmilllPerformanceData^>^ treadmillResults = nullptr;


		void showGeneralResults()
		{

		}

		void showResultsByCategory(Categories^ category)
		{

		}

		List<Rank^>^ calculateResultsByCategory(Categories^ category)
		{
			Dictionary<Categories^, List<Dog^>^>^ dogsByCategory = competitors->getCompetitorsByCategory();
			return nullptr;
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->printButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->resultGrid = (gcnew System::Windows::Forms::DataGridView());
			this->placing = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dogName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->points = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// headerLabel
			// 
			this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerLabel->AutoSize = true;
			this->headerLabel->Location = System::Drawing::Point(300, 31);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->Size = System::Drawing::Size(270, 44);
			this->headerLabel->TabIndex = 0;
			this->headerLabel->Text = L"Results of ...";
			// 
			// printButton
			// 
			this->printButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->printButton->BackColor = System::Drawing::Color::White;
			this->printButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->printButton->Location = System::Drawing::Point(31, 928);
			this->printButton->Name = L"printButton";
			this->printButton->Size = System::Drawing::Size(133, 43);
			this->printButton->TabIndex = 14;
			this->printButton->Text = L"Print";
			this->printButton->UseVisualStyleBackColor = false;
			// 
			// exitButton
			// 
			this->exitButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->exitButton->BackColor = System::Drawing::Color::White;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->exitButton->Location = System::Drawing::Point(724, 928);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(133, 43);
			this->exitButton->TabIndex = 13;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			// 
			// resultGrid
			// 
			this->resultGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->resultGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->resultGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->placing, this->dogName,
					this->points
			});
			this->resultGrid->Location = System::Drawing::Point(91, 106);
			this->resultGrid->Name = L"resultGrid";
			this->resultGrid->RowHeadersWidth = 62;
			this->resultGrid->RowTemplate->Height = 28;
			this->resultGrid->Size = System::Drawing::Size(712, 779);
			this->resultGrid->TabIndex = 15;
			// 
			// placing
			// 
			this->placing->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->placing->HeaderText = L"Placing";
			this->placing->MinimumWidth = 8;
			this->placing->Name = L"placing";
			this->placing->Width = 201;
			// 
			// dogName
			// 
			this->dogName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->dogName->HeaderText = L"Dog Name";
			this->dogName->MinimumWidth = 8;
			this->dogName->Name = L"dogName";
			this->dogName->Width = 263;
			// 
			// points
			// 
			this->points->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->points->HeaderText = L"Points";
			this->points->MinimumWidth = 8;
			this->points->Name = L"points";
			this->points->Width = 181;
			// 
			// Results
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(25, 44);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(894, 994);
			this->Controls->Add(this->resultGrid);
			this->Controls->Add(this->printButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->headerLabel);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->Name = L"Results";
			this->Text = L"Top Dog Show";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
