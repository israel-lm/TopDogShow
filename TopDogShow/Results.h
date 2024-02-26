#pragma once

#include "DBHandler.h"
#include "Competitors.h"
#include "Comparator.h"

namespace TopDogShow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Diagnostics;


	public ref class Results : public System::Windows::Forms::Form
	{
	public:
		Results(ResultType type, String^ category)
		{
			InitializeComponent();
			gridDataSource = gcnew BindingSource();
			dbHandler = DBHandler::Instance;
			competitors = Competitors::Instance;
			showResults(type, category);
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
		System::Windows::Forms::BindingSource^ gridDataSource;
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

		void showResults(ResultType type, String^ category)
		{
			updateResultsData();
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
		
		void updateResultsData()
		{
			if (dbHandler)
			{
				wallClimbResults = dbHandler->getWallClimbResults();
				highJumpResults = dbHandler->getHighJumpResults();
				longJumpResults = dbHandler->getLongJumpResults();
				treadmillResults = dbHandler->getTreadmillResults();
			}
		}

		void showGeneralResults()
		{

		}

		void showResultsByCategory(String^ category)
		{
			List<Rank^>^ ranking = calculateResultsByCategory(category);
			for each (Rank^ rank in ranking)
				gridDataSource->Add(rank);

			resultGrid->AutoGenerateColumns = true;
			resultGrid->DefaultCellStyle->ForeColor = Color::Black;
			resultGrid->DataSource = gridDataSource;
		}

		void assignMarkTablePlacing(List<Rank^>^ ranking, Dictionary<String^, MarkTablePerformanceData^>^ performanceData)
		{
			int place = 1;
			for (int i = (ranking->Count - 1); i >= 0; i--)
			{				
				if ((i > 0) && (ranking[i]->bestMark == ranking[i - 1]->bestMark))
				{
					String^ dogName1 = ranking[i]->name;
					String^ dogName2 = ranking[i - 1]->name;

					MarkTablePerformanceData^ results1 = performanceData[dogName1];
					MarkTablePerformanceData^ results2 = performanceData[dogName2];
					int totalAttempts1 = results1->getTotalAttempts();
					int totalAttempts2 = results2->getTotalAttempts();


					if (totalAttempts1 < totalAttempts2)
					{
						ranking[i]->place = place;
						ranking[i - 1]->place = place + 1;
						ranking[i]->points = assignPoints(i);
						ranking[i - 1]->points = assignPoints(i + 1);
					}
					else
					{
						ranking[i]->place = place + 1;
						ranking[i - 1]->place = place;
						ranking[i]->points = assignPoints(i + 1);
						ranking[i - 1]->points = assignPoints(i);
					}
					i--;
					place += 2;
				}
				else
				{
					ranking[i]->place = place;
					ranking[i]->points = assignPoints(place);
					place++;
				}
				
			}
		}

		int assignPoints(int placing)
		{
			int points = 0;
			switch (placing)
			{
			case 1:
				points = 25;
				break;
			case 2:
				points = 20;
				break;
			case 3:
				points = 15;
				break;
			case 4:
				points = 12;
				break;
			case 5:
				points = 10;
				break;
			default:
				points = 0;
			}
			return points;
		}

		void assignPlacing(List<Rank^>^ ranking)
		{
			for (int i = ranking->Count; i > 0; i--)
			{
				ranking[i - 1]->place = i;
				ranking[i - 1]->points = assignPoints(i);
					
			}
		}

		String^ printRanking(List<Rank^>^ ranking)
		{
			StringBuilder^ stringBuilder = gcnew StringBuilder("Name \tBest Mark \tPlace \tPoints\n");

			for each (Rank^ item in ranking)
			{
				stringBuilder->Append(String::Format("{0} \t{1} \t{2} \t{3}\n", item->name, item->bestMark, item->place, item->points));
			}

			return stringBuilder->ToString();
		}
		
		List<Rank^>^ calculateResultsByCategory(String^ category)
		{
			
			Dictionary<String^, List<Dog^>^>^ dogsByCategory = competitors->getCompetitorsByCategory();
			List<Rank^>^ wallClimBestresults = gcnew List<Rank^>();
			List<Rank^>^ highJumpBestresults = gcnew List<Rank^>();
			List<Rank^>^ longJumpBestresults = gcnew List<Rank^>();
			List<Rank^>^ treadmillBestresults = gcnew List<Rank^>();

			List<Rank^>^ categoryRank = gcnew List<Rank^>();

			for each (Dog^ dog in dogsByCategory[category])
			{
				PerformanceData^ wallClimb = wallClimbResults[dog->getName()];
				/*PerformanceData^ highJump = highJumpResults[dog->getName()];
				PerformanceData^ longJump = longJumpResults[dog->getName()];
				PerformanceData^ treadmill = treadmillResults[dog->getName()];*/
				if (wallClimb)
					wallClimBestresults->Add(gcnew Rank(dog->getName(), wallClimb->getBestResult()));
				/*highJumpBestresults->Add(gcnew Rank(dog->getName(), highJump->getBestResult()));
				longJumpBestresults->Add(gcnew Rank(dog->getName(), longJump->getBestResult()));
				treadmillBestresults->Add(gcnew Rank(dog->getName(), treadmill->getBestResult()));*/
			}

			wallClimBestresults->Sort(gcnew CompareByElement(Element::MARK));
			Debug::WriteLine("Before assignMarkTablePlacing");
			
			Debug::WriteLine(printRanking(wallClimBestresults));
			/*highJumpBestresults->Sort(gcnew CompareByElement(Element::MARK));
			longJumpBestresults->Sort(gcnew CompareByElement(Element::MARK));
			treadmillBestresults->Sort(gcnew CompareByElement(Element::MARK));*/

			assignMarkTablePlacing(wallClimBestresults, wallClimbResults);
			Debug::WriteLine("After assignMarkTablePlacing");
			Debug::WriteLine(printRanking(wallClimBestresults));
			/*assignMarkTablePlacing(highJumpBestresults, highJumpResults);
			assignPlacing(longJumpBestresults);
			assignPlacing(treadmillBestresults);*/
			wallClimBestresults->Sort(gcnew CompareByElement(Element::PLACE));
			/*highJumpBestresults->Sort(gcnew CompareByElement(Element::PLACE));*/

			//TODO: calculate the rank for the category

			return wallClimBestresults;
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
			this->resultGrid->Location = System::Drawing::Point(91, 106);
			this->resultGrid->Name = L"resultGrid";
			this->resultGrid->RowHeadersWidth = 62;
			this->resultGrid->RowTemplate->Height = 28;
			this->resultGrid->Size = System::Drawing::Size(712, 779);
			this->resultGrid->TabIndex = 15;
			this->resultGrid->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
			this->resultGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
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
