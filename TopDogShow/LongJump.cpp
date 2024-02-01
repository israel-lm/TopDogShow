#include "LongJump.h"
#include "Utils.h"


using namespace TopDogShow;

LongJump::LongJump(String^ dogName)
{
    allTexts = gcnew List<TextBox^>();
	InitializeComponent();
    this->dogName->Text = dogName;
    dbHandler = DBHandler::Instance;
}


LongJump::~LongJump()
{
	if (components)
	{
		delete components;
	}
}


System::Void LongJump::cancelButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    resetFields();
    this->Close();
}

System::Void LongJump::finishButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (allTexts)
    {
        LongJumpPerformanceData^ performanceData = gcnew LongJumpPerformanceData();
        performanceData->dogName = dogName->Text;
        for each (TextBox^ text in allTexts)
        {
            int markValue = 0;
            try
            {
                markValue = (int)(Convert::ToDouble(text->Text) * 100); //convert to cm
            }
            catch (Exception^ e)
            {
                showMessage("Invalid mark value", "Long jump discipline");
                return;
            }
            performanceData->marks->Add(markValue);
        }
        dbHandler->saveLongJumpResults(performanceData);
    }
    resetFields();
    this->Close();
}

void LongJump::resetFields()
{
    for each (TextBox ^ text in allTexts)
    {
        text->Text = "";
    }
}

void LongJump::InitializeComponent(void)
{
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LongJump::typeid));
    this->headerLabel = (gcnew System::Windows::Forms::Label());
    this->dogPicture = (gcnew System::Windows::Forms::PictureBox());
    this->attemptLabel = (gcnew System::Windows::Forms::Label());
    this->markLabel = (gcnew System::Windows::Forms::Label());
    this->attempt1Label = (gcnew System::Windows::Forms::Label());
    this->attempt2Label = (gcnew System::Windows::Forms::Label());
    this->attempt3Label = (gcnew System::Windows::Forms::Label());
    this->attempt4Label = (gcnew System::Windows::Forms::Label());
    this->attempt5Label = (gcnew System::Windows::Forms::Label());
    this->mark1Box = (gcnew System::Windows::Forms::TextBox());
    this->allTexts->Add(mark1Box);
    this->mark2Box = (gcnew System::Windows::Forms::TextBox());
    this->allTexts->Add(mark2Box);
    this->mark3Box = (gcnew System::Windows::Forms::TextBox());
    this->allTexts->Add(mark3Box);
    this->mark4Box = (gcnew System::Windows::Forms::TextBox());
    this->allTexts->Add(mark4Box);
    this->mark5Box = (gcnew System::Windows::Forms::TextBox());
    this->allTexts->Add(mark5Box);
    this->markPanel = (gcnew System::Windows::Forms::Panel());
    this->finishButton = (gcnew System::Windows::Forms::Button());
    this->cancelButton = (gcnew System::Windows::Forms::Button());
    this->dogName = (gcnew System::Windows::Forms::Label());
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->BeginInit();
    this->markPanel->SuspendLayout();
    this->SuspendLayout();
    // 
    // headerLabel
    // 
    this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
    this->headerLabel->AutoSize = true;
    this->headerLabel->Location = System::Drawing::Point(307, 47);
    this->headerLabel->Name = L"headerLabel";
    this->headerLabel->Size = System::Drawing::Size(239, 44);
    this->headerLabel->TabIndex = 0;
    this->headerLabel->Text = L"Long Jump";
    // 
    // dogPicture
    // 
    this->dogPicture->Anchor = System::Windows::Forms::AnchorStyles::Right;
    this->dogPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dogPicture.Image")));
    this->dogPicture->Location = System::Drawing::Point(440, 183);
    this->dogPicture->Name = L"dogPicture";
    this->dogPicture->Size = System::Drawing::Size(255, 306);
    this->dogPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
    this->dogPicture->TabIndex = 1;
    this->dogPicture->TabStop = false;
    // 
    // attemptLabel
    // 
    this->attemptLabel->AutoSize = true;
    this->attemptLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->attemptLabel->Location = System::Drawing::Point(-1, 12);
    this->attemptLabel->Name = L"attemptLabel";
    this->attemptLabel->Size = System::Drawing::Size(123, 29);
    this->attemptLabel->TabIndex = 2;
    this->attemptLabel->Text = L"Attempt";
    // 
    // markLabel
    // 
    this->markLabel->AutoSize = true;
    this->markLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->markLabel->Location = System::Drawing::Point(-1, 51);
    this->markLabel->Name = L"markLabel";
    this->markLabel->Size = System::Drawing::Size(80, 29);
    this->markLabel->TabIndex = 3;
    this->markLabel->Text = L"Mark";
    // 
    // attempt1Label
    // 
    this->attempt1Label->BackColor = System::Drawing::Color::White;
    this->attempt1Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->attempt1Label->ForeColor = System::Drawing::SystemColors::ControlText;
    this->attempt1Label->Location = System::Drawing::Point(84, 12);
    this->attempt1Label->Name = L"attempt1Label";
    this->attempt1Label->Size = System::Drawing::Size(60, 20);
    this->attempt1Label->TabIndex = 4;
    this->attempt1Label->Text = L"1";
    this->attempt1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // attempt2Label
    // 
    this->attempt2Label->BackColor = System::Drawing::Color::White;
    this->attempt2Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->attempt2Label->ForeColor = System::Drawing::SystemColors::ControlText;
    this->attempt2Label->Location = System::Drawing::Point(147, 12);
    this->attempt2Label->Name = L"attempt2Label";
    this->attempt2Label->Size = System::Drawing::Size(60, 20);
    this->attempt2Label->TabIndex = 5;
    this->attempt2Label->Text = L"2";
    this->attempt2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // attempt3Label
    // 
    this->attempt3Label->BackColor = System::Drawing::Color::White;
    this->attempt3Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->attempt3Label->ForeColor = System::Drawing::SystemColors::ControlText;
    this->attempt3Label->Location = System::Drawing::Point(210, 12);
    this->attempt3Label->Name = L"attempt3Label";
    this->attempt3Label->Size = System::Drawing::Size(60, 20);
    this->attempt3Label->TabIndex = 6;
    this->attempt3Label->Text = L"3";
    this->attempt3Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // attempt4Label
    // 
    this->attempt4Label->BackColor = System::Drawing::Color::White;
    this->attempt4Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->attempt4Label->ForeColor = System::Drawing::SystemColors::ControlText;
    this->attempt4Label->Location = System::Drawing::Point(273, 12);
    this->attempt4Label->Name = L"attempt4Label";
    this->attempt4Label->Size = System::Drawing::Size(60, 20);
    this->attempt4Label->TabIndex = 7;
    this->attempt4Label->Text = L"4";
    this->attempt4Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // attempt5Label
    // 
    this->attempt5Label->BackColor = System::Drawing::Color::White;
    this->attempt5Label->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->attempt5Label->ForeColor = System::Drawing::SystemColors::ControlText;
    this->attempt5Label->Location = System::Drawing::Point(336, 12);
    this->attempt5Label->Name = L"attempt5Label";
    this->attempt5Label->Size = System::Drawing::Size(60, 20);
    this->attempt5Label->TabIndex = 8;
    this->attempt5Label->Text = L"5";
    this->attempt5Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // mark1Box
    // 
    this->mark1Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->mark1Box->Location = System::Drawing::Point(84, 39);
    this->mark1Box->Name = L"mark1Box";
    this->mark1Box->Size = System::Drawing::Size(60, 35);
    this->mark1Box->TabIndex = 9;
    // 
    // mark2Box
    // 
    this->mark2Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->mark2Box->Location = System::Drawing::Point(147, 39);
    this->mark2Box->Name = L"mark2Box";
    this->mark2Box->Size = System::Drawing::Size(60, 35);
    this->mark2Box->TabIndex = 10;
    // 
    // mark3Box
    // 
    this->mark3Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->mark3Box->Location = System::Drawing::Point(210, 39);
    this->mark3Box->Name = L"mark3Box";
    this->mark3Box->Size = System::Drawing::Size(60, 35);
    this->mark3Box->TabIndex = 11;
    // 
    // mark4Box
    // 
    this->mark4Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->mark4Box->Location = System::Drawing::Point(273, 39);
    this->mark4Box->Name = L"mark4Box";
    this->mark4Box->Size = System::Drawing::Size(60, 35);
    this->mark4Box->TabIndex = 12;
    // 
    // mark5Box
    // 
    this->mark5Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->mark5Box->Location = System::Drawing::Point(336, 39);
    this->mark5Box->Name = L"mark5Box";
    this->mark5Box->Size = System::Drawing::Size(60, 35);
    this->mark5Box->TabIndex = 13;
    // 
    // markPanel
    // 
    this->markPanel->Anchor = System::Windows::Forms::AnchorStyles::Left;
    this->markPanel->Controls->Add(this->attempt1Label);
    this->markPanel->Controls->Add(this->mark5Box);
    this->markPanel->Controls->Add(this->attemptLabel);
    this->markPanel->Controls->Add(this->mark4Box);
    this->markPanel->Controls->Add(this->markLabel);
    this->markPanel->Controls->Add(this->mark3Box);
    this->markPanel->Controls->Add(this->attempt2Label);
    this->markPanel->Controls->Add(this->mark2Box);
    this->markPanel->Controls->Add(this->attempt3Label);
    this->markPanel->Controls->Add(this->mark1Box);
    this->markPanel->Controls->Add(this->attempt4Label);
    this->markPanel->Controls->Add(this->attempt5Label);
    this->markPanel->Location = System::Drawing::Point(12, 183);
    this->markPanel->Name = L"markPanel";
    this->markPanel->Size = System::Drawing::Size(403, 93);
    this->markPanel->TabIndex = 14;
    // 
    // finishButton
    // 
    this->finishButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
    this->finishButton->BackColor = System::Drawing::Color::White;
    this->finishButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->finishButton->ForeColor = System::Drawing::SystemColors::ControlText;
    this->finishButton->Location = System::Drawing::Point(545, 562);
    this->finishButton->Name = L"finishButton";
    this->finishButton->Size = System::Drawing::Size(150, 30);
    this->finishButton->TabIndex = 16;
    this->finishButton->Text = L"Finish";
    this->finishButton->UseVisualStyleBackColor = false;
    this->finishButton->Click += gcnew System::EventHandler(this, &LongJump::finishButton_Click);
    // 
    // cancelButton
    // 
    this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
    this->cancelButton->BackColor = System::Drawing::Color::White;
    this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->cancelButton->ForeColor = System::Drawing::SystemColors::ControlText;
    this->cancelButton->Location = System::Drawing::Point(338, 562);
    this->cancelButton->Name = L"cancelButton";
    this->cancelButton->Size = System::Drawing::Size(150, 30);
    this->cancelButton->TabIndex = 15;
    this->cancelButton->Text = L"Cancel";
    this->cancelButton->UseVisualStyleBackColor = false;
    this->cancelButton->Click += gcnew System::EventHandler(this, &LongJump::cancelButton_Click);
    // 
    // dogName
    // 
    this->dogName->Anchor = System::Windows::Forms::AnchorStyles::Right;
    this->dogName->AutoSize = true;
    this->dogName->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->dogName->Location = System::Drawing::Point(435, 502);
    this->dogName->Name = L"dogName";
    this->dogName->Size = System::Drawing::Size(151, 29);
    this->dogName->TabIndex = 17;
    this->dogName->Text = L"Dog Name";
    // 
    // LongJump
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(25, 44);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::DodgerBlue;
    this->ClientSize = System::Drawing::Size(714, 604);
    this->Controls->Add(this->dogName);
    this->Controls->Add(this->finishButton);
    this->Controls->Add(this->cancelButton);
    this->Controls->Add(this->markPanel);
    this->Controls->Add(this->dogPicture);
    this->Controls->Add(this->headerLabel);
    this->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->ForeColor = System::Drawing::Color::White;
    this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
    this->MinimumSize = System::Drawing::Size(730, 530);
    this->Name = L"LongJump";
    this->Text = L"Top Dog Show";
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dogPicture))->EndInit();
    this->markPanel->ResumeLayout(false);
    this->markPanel->PerformLayout();
    this->ResumeLayout(false);
    this->PerformLayout();

}