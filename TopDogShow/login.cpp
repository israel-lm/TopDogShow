#include "Login.h"

TopDogShow::Login::Login(void)
{
	InitializeComponent();
}


TopDogShow::Login::~Login()
{
	if (components)
	{
		delete components;
	}
}


bool TopDogShow::Login::isLoginSuccessful()
{
	return loginSuccessful;
}

System::Void TopDogShow::Login::canecelButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

System::Void TopDogShow::Login::okButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = usernameText->Text;
	String^ password = passwordText->Text;

	if ((name->Length == 0) || (password->Length == 0))
	{
		MessageBox::Show(
			"Missing username or password.",
			"Information error",
			MessageBoxButtons::OK);
	}
	else
	{
		String^ connectionString = "Data Source=ENCSABCAMLT1115\\SQLEXPRESS;Initial Catalog=top_dog_show;Integrated Security=True;Encrypt=False";
		try
		{
			SqlConnection sqlConnection(connectionString);
			sqlConnection.Open();

			String^ sqlQuery = "SELECT * from users WHERE name=@name AND password=@password;";
			SqlCommand command(sqlQuery, % sqlConnection);
			command.Parameters->AddWithValue("@name", name);
			command.Parameters->AddWithValue("@password", password);

			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read())
			{
				loginSuccessful = true;
				this->Close();
			}
			else
				MessageBox::Show(
					"Wrong name or password.",
					"Authentication Failed.",
					MessageBoxButtons::OK
				);
		}
		catch (Exception^ e)
		{
			MessageBox::Show(
				e->Message,
				"Exception",
				MessageBoxButtons::OK
			);
		}

	}
}


void TopDogShow::Login::InitializeComponent(void)
{
	this->headerLabel = (gcnew System::Windows::Forms::Label());
	this->usernameText = (gcnew System::Windows::Forms::TextBox());
	this->passwordText = (gcnew System::Windows::Forms::TextBox());
	this->usernameLabel = (gcnew System::Windows::Forms::Label());
	this->passwordLabel = (gcnew System::Windows::Forms::Label());
	this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
	this->okButton = (gcnew System::Windows::Forms::Button());
	this->canecelButton = (gcnew System::Windows::Forms::Button());
	this->tableLayoutPanel1->SuspendLayout();
	this->SuspendLayout();
	// 
	// headerLabel
	// 
	this->headerLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->headerLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->headerLabel->ForeColor = System::Drawing::Color::White;
	this->headerLabel->Location = System::Drawing::Point(18, 23);
	this->headerLabel->Name = L"headerLabel";
	this->headerLabel->Size = System::Drawing::Size(455, 68);
	this->headerLabel->TabIndex = 0;
	this->headerLabel->Text = L"Login";
	this->headerLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	// 
	// usernameText
	// 
	this->usernameText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->usernameText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->usernameText->Location = System::Drawing::Point(25, 201);
	this->usernameText->Name = L"usernameText";
	this->usernameText->Size = System::Drawing::Size(448, 35);
	this->usernameText->TabIndex = 1;
	// 
	// passwordText
	// 
	this->passwordText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->passwordText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->passwordText->Location = System::Drawing::Point(25, 325);
	this->passwordText->Name = L"passwordText";
	this->passwordText->PasswordChar = '*';
	this->passwordText->Size = System::Drawing::Size(448, 35);
	this->passwordText->TabIndex = 2;
	// 
	// usernameLabel
	// 
	this->usernameLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->usernameLabel->ForeColor = System::Drawing::Color::White;
	this->usernameLabel->Location = System::Drawing::Point(21, 160);
	this->usernameLabel->Name = L"usernameLabel";
	this->usernameLabel->Size = System::Drawing::Size(452, 38);
	this->usernameLabel->TabIndex = 3;
	this->usernameLabel->Text = L"Username";
	// 
	// passwordLabel
	// 
	this->passwordLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->passwordLabel->ForeColor = System::Drawing::Color::White;
	this->passwordLabel->Location = System::Drawing::Point(20, 282);
	this->passwordLabel->Name = L"passwordLabel";
	this->passwordLabel->Size = System::Drawing::Size(453, 30);
	this->passwordLabel->TabIndex = 4;
	this->passwordLabel->Text = L"Password";
	// 
	// tableLayoutPanel1
	// 
	this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->tableLayoutPanel1->ColumnCount = 2;
	this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
		50)));
	this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
		50)));
	this->tableLayoutPanel1->Controls->Add(this->okButton, 1, 0);
	this->tableLayoutPanel1->Controls->Add(this->canecelButton, 0, 0);
	this->tableLayoutPanel1->Location = System::Drawing::Point(132, 398);
	this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
	this->tableLayoutPanel1->RowCount = 1;
	this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
	this->tableLayoutPanel1->Size = System::Drawing::Size(341, 54);
	this->tableLayoutPanel1->TabIndex = 5;
	// 
	// okButton
	// 
	this->okButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
	this->okButton->BackColor = System::Drawing::Color::White;
	this->okButton->Location = System::Drawing::Point(173, 3);
	this->okButton->Name = L"okButton";
	this->okButton->Size = System::Drawing::Size(165, 48);
	this->okButton->TabIndex = 0;
	this->okButton->Text = L"Ok";
	this->okButton->UseVisualStyleBackColor = false;
	this->okButton->Click += gcnew System::EventHandler(this, &Login::okButton_Click);
	// 
	// canecelButton
	// 
	this->canecelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
	this->canecelButton->BackColor = System::Drawing::Color::White;
	this->canecelButton->Location = System::Drawing::Point(3, 3);
	this->canecelButton->Name = L"canecelButton";
	this->canecelButton->Size = System::Drawing::Size(164, 48);
	this->canecelButton->TabIndex = 1;
	this->canecelButton->Text = L"Cancel";
	this->canecelButton->UseVisualStyleBackColor = false;
	this->canecelButton->Click += gcnew System::EventHandler(this, &Login::canecelButton_Click);
	// 
	// Login
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::DodgerBlue;
	this->ClientSize = System::Drawing::Size(485, 512);
	this->Controls->Add(this->tableLayoutPanel1);
	this->Controls->Add(this->passwordLabel);
	this->Controls->Add(this->usernameLabel);
	this->Controls->Add(this->passwordText);
	this->Controls->Add(this->usernameText);
	this->Controls->Add(this->headerLabel);
	this->MaximumSize = System::Drawing::Size(507, 568);
	this->MinimumSize = System::Drawing::Size(507, 568);
	this->Name = L"Login";
	this->Text = L"Top Dog Show";
	this->tableLayoutPanel1->ResumeLayout(false);
	this->ResumeLayout(false);
	this->PerformLayout();

}