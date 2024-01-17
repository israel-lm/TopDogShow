#include "Login.h"
#include "Home.h"

//#include "Competitors.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace TopDogShow;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Login^ loginScreen = gcnew Login();
	Home^ homeScreen = gcnew Home();

	
	loginScreen->ShowDialog();

	if (loginScreen->isLoginSuccessful())
	{
		loginScreen->Close();
		Application::Run(homeScreen);
	}

	/*Competitors^ competitors = Competitors::Instance;

	Dictionary<Categories, List<Dog^>^>^ dogsBYCategory = competitors->getCompetitors();

	String^ toPrint;
	for each (KeyValuePair< Categories, List<Dog^>^> item in dogsBYCategory)
	{
		String^ category = marshal_as<String^>(CategoryString.at((int)item.Key));
		toPrint += String::Format("{0}\n", category);

		for each (Dog ^ dog in item.Value)
		{
			toPrint += String::Format("\t{0}\n", dog->getName());
		}
	}

	MessageBox::Show(
		toPrint,
		"List of dogs",
		MessageBoxButtons::OK
	);*/
}