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
		System::Windows::Forms::BindingSource^ gridDataSource = nullptr;
		System::Windows::Forms::DataGridViewTextBoxColumn^ placing;
		System::Windows::Forms::DataGridViewTextBoxColumn^ dogName;
		System::Windows::Forms::DataGridViewTextBoxColumn^ points;
		System::ComponentModel::Container^ components;


		DBHandler^ dbHandler = nullptr;
		Competitors^ competitors = nullptr;
		Dictionary<String^, MarkTablePerformanceData^>^ wallClimbResults = nullptr;
		Dictionary<String^, MarkTablePerformanceData^>^ highJumpResults = nullptr;
		Dictionary<String^, LongJumpPerformanceData^>^ longJumpResults = nullptr;
		Dictionary<String^, TreadmillPerformanceData^>^ treadmillResults = nullptr;


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
			addGridViewDataSource(calculateGeneralResults());
		}

		void addGridViewDataSource(List<Rank^>^ rank)
		{
			if (!gridDataSource)
			{
				gridDataSource = gcnew BindingSource();
				resultGrid->DataSource = gridDataSource;
			}				

			gridDataSource->Clear();			

			for each (Rank^ item in rank)
				gridDataSource->Add(item);
			resultGrid->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
		}

		void showResultsByCategory(String^ category)
		{
			addGridViewDataSource(calculateResultsByCategory(category));
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

		void assignPlace(List<Rank^>^ ranking, bool givePoints)
		{
			int placing = 0;
			for (int i = 0; i < ranking->Count; i++)
			{
				placing = i + 1;
				ranking[i]->place = placing;
				if (givePoints)
					ranking[i]->points = assignPoints(placing);
			}
		}

		String^ printRanking(List<Rank^>^ ranking)
		{
			StringBuilder^ stringBuilder = gcnew StringBuilder("Name      | Best Mark | Attempts | Place | Points\n");

			for each (Rank ^ item in ranking)
			{
				stringBuilder->Append(String::Format(
					"{0, -9} | {1, -9} | {2, 8} |{3, 5} | {4, 6}\n", 
					item->name, 
					item->bestMark,
					item->totalAttempts,
					item->place, 
					item->points
				));
			}

			return stringBuilder->ToString();
		}

		template<typename T>
		List<Rank^>^ getListOfBestMarks(List<Dog^>^ dogs, Dictionary<String^, T>^ performanceData)
		{
			List<Rank^>^ bestMarks = gcnew List<Rank^>();
			PerformanceData^ data = nullptr;

			for each (Dog^ dog in dogs)
			{
				try
				{
					data = performanceData[dog->getName()];
				}							
				catch (Exception^ e)
				{
					continue;
				}
				
				if (data)
					bestMarks->Add(gcnew Rank(dog->getName(), data->getBestResult(), 0, data->getTotalAttempts()));
			}

			return bestMarks;
		}

		void setOverallRanking(List<Rank^>^ rank)
		{
			Debug::WriteLine("Before sorting by point");
			Debug::WriteLine(printRanking(rank));
			rank->Sort(gcnew CompareByElement(Element::POINT));
			Debug::WriteLine("After sorting by point");
			Debug::WriteLine(printRanking(rank));
			
			rank->Sort(gcnew CompareByElement(Element::ATTEMPTS));
			Debug::WriteLine("After sorting by attempts");
			Debug::WriteLine(printRanking(rank));
			assignPlace(rank, false);
		}


		List<Rank^>^ getCategoryRanking(List<List<Rank^>^>^ ranks)
		{
			List<Rank^>^ categoryRank = gcnew List<Rank^>();
			Dictionary<String^, Rank^>^ dogsAndPoints = gcnew Dictionary<String^, Rank^>();

			for each (List<Rank^>^ item in ranks)
			{
				for each (Rank^ rank in item)
				{
					if (dogsAndPoints->ContainsKey(rank->name))
					{
						Rank^ currentValues = dogsAndPoints[rank->name];
						currentValues->points += rank->points;
						currentValues->totalAttempts += rank->totalAttempts;
					}
					else
					{
						dogsAndPoints[rank->name] = gcnew Rank(rank->name, -1, rank->points, rank->totalAttempts);
					}
				}
			}

			for each (KeyValuePair<String^, Rank^>^ kvp in dogsAndPoints)
			{
				categoryRank->Add(kvp->Value);
			}

			setOverallRanking(categoryRank);

			return categoryRank;
		}

		List<Rank^>^ calculateGeneralResults()
		{
			List<Rank^>^ generalRank = calculateResultsByCategory(Categories::LIGHT_WEIGHT);
			generalRank->AddRange(calculateResultsByCategory(Categories::MIDDLE_WEIGHT));			
			generalRank->AddRange(calculateResultsByCategory(Categories::HEAVY_WEIGHT));
			
			setOverallRanking(generalRank);

			return generalRank;
		}

		List<Rank^>^ calculateResultsByCategory(String^ category)
		{
			List<Rank^>^ categoryRank = nullptr;

			Dictionary<String^, List<Dog^>^>^ dogsByCategory = competitors->getCompetitorsByCategory();
			if (!dogsByCategory)
			{
				//TODO: show error
				return nullptr;
			}
			List<Dog^>^ dogs = nullptr;

			try
			{
				dogs = dogsByCategory[category];
			}
			catch (Exception^ e)
			{
				//TODO: show error
				return nullptr;
			}

			List<Rank^>^ wallClimBestresults = getListOfBestMarks<MarkTablePerformanceData^>(
				dogs, 
				wallClimbResults
			);

			List<Rank^>^ highJumpBestresults = getListOfBestMarks<MarkTablePerformanceData^>(
				dogs,
				highJumpResults
			);

			List<Rank^>^ longJumpBestresults = getListOfBestMarks<LongJumpPerformanceData^>(
				dogs,
				longJumpResults
			);

			List<Rank^>^ treadmillBestresults = getListOfBestMarks<TreadmillPerformanceData^>(
				dogs,
				treadmillResults
			);

			wallClimBestresults->Sort(gcnew CompareByElement(Element::MARK));			
			highJumpBestresults->Sort(gcnew CompareByElement(Element::MARK));
			longJumpBestresults->Sort(gcnew CompareByElement(Element::MARK));
			treadmillBestresults->Sort(gcnew CompareByElement(Element::MARK));
			
			/*Debug::WriteLine("Before sorting by attempts");
			Debug::WriteLine(String::Format("wallClimBestresults:\n{0}", printRanking(wallClimBestresults)));
			Debug::WriteLine(String::Format("highJumpBestresults:\n{0}", printRanking(highJumpBestresults)));
			Debug::WriteLine(String::Format("longJumpBestresults:\n{0}", printRanking(longJumpBestresults)));
			Debug::WriteLine(String::Format("treadmillBestresults:\n{0}", printRanking(treadmillBestresults)));*/

			/*sortByAttempts(wallClimBestresults);
			sortByAttempts(highJumpBestresults);*/

			wallClimBestresults->Sort(gcnew CompareByElement(Element::ATTEMPTS));
			highJumpBestresults->Sort(gcnew CompareByElement(Element::ATTEMPTS));

			/*Debug::WriteLine("After sorting by attempts");
			Debug::WriteLine(String::Format("wallClimBestresults:\n{0}", printRanking(wallClimBestresults)));
			Debug::WriteLine(String::Format("highJumpBestresults:\n{0}", printRanking(highJumpBestresults)));
			Debug::WriteLine(String::Format("longJumpBestresults:\n{0}", printRanking(longJumpBestresults)));
			Debug::WriteLine(String::Format("treadmillBestresults:\n{0}", printRanking(treadmillBestresults)));*/

			assignPlace(wallClimBestresults, true);
			assignPlace(highJumpBestresults, true);
			assignPlace(longJumpBestresults, true);
			assignPlace(treadmillBestresults, true);

			/*Debug::WriteLine("After assigning places");
			Debug::WriteLine(String::Format("wallClimBestresults:\n{0}", printRanking(wallClimBestresults)));
			Debug::WriteLine(String::Format("highJumpBestresults:\n{0}", printRanking(highJumpBestresults)));
			Debug::WriteLine(String::Format("longJumpBestresults:\n{0}", printRanking(longJumpBestresults)));
			Debug::WriteLine(String::Format("treadmillBestresults:\n{0}", printRanking(treadmillBestresults)));*/


			List<List<Rank^>^>^ rankList = gcnew List<List<Rank^>^>();
			rankList->Add(wallClimBestresults);
			rankList->Add(highJumpBestresults);
			rankList->Add(longJumpBestresults);
			rankList->Add(treadmillBestresults);

			categoryRank = getCategoryRanking(rankList);


			return categoryRank;
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->headerLabel->Location = System::Drawing::Point(233, 32);
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
			this->printButton->Location = System::Drawing::Point(31, 388);
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
			this->exitButton->Location = System::Drawing::Point(466, 388);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(133, 43);
			this->exitButton->TabIndex = 13;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			// 
			// resultGrid
			// 
			this->resultGrid->AllowUserToAddRows = false;
			this->resultGrid->AllowUserToDeleteRows = false;
			this->resultGrid->AllowUserToResizeColumns = false;
			this->resultGrid->AllowUserToResizeRows = false;
			this->resultGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->resultGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->resultGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->resultGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->resultGrid->DefaultCellStyle = dataGridViewCellStyle1;
			this->resultGrid->Location = System::Drawing::Point(31, 109);
			this->resultGrid->Name = L"resultGrid";
			this->resultGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->resultGrid->RowTemplate->Height = 28;
			this->resultGrid->Size = System::Drawing::Size(568, 250);
			this->resultGrid->TabIndex = 15;
			// 
			// placing
			// 
			this->placing->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->placing->HeaderText = L"Placing";
			this->placing->MinimumWidth = 8;
			this->placing->Name = L"placing";
			this->placing->Width = 150;
			// 
			// dogName
			// 
			this->dogName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->dogName->HeaderText = L"Dog Name";
			this->dogName->MinimumWidth = 8;
			this->dogName->Name = L"dogName";
			this->dogName->Width = 150;
			// 
			// points
			// 
			this->points->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->points->HeaderText = L"Points";
			this->points->MinimumWidth = 8;
			this->points->Name = L"points";
			this->points->Width = 150;
			// 
			// Results
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(25, 44);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(650, 454);
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
