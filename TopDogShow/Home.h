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
		Home(void);

	protected:
		~Home();

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

		PreDiscipline^ preDisciplineScreen = nullptr;
		Form^ treadmilScreen = nullptr;
		Results^ resultsScreen = nullptr;
		Registration^ registrationScreen = nullptr;

		DisciplineFactory* disciplineFactory;

		System::Void wallClimbButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void highJumpButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void longJumpButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void treadmilButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void leaveButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void registrationButton_Click(System::Object^ sender, System::EventArgs^ e);
		void InitializeComponent(void);
};
}
