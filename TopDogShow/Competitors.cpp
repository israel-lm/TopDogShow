#include "Competitors.h"

using namespace System::Collections::Generic;
using namespace System;


TopDogShow::Competitors::Competitors()
{
}


void TopDogShow::Competitors::loadCompetitors()
{
	DBHandler^ handler = DBHandler::Instance;
	List<TopDogShow::Dog^>^ dogs = gcnew List<TopDogShow::Dog^>;
	

	if (!competitors)
		competitors = gcnew Dictionary<String^, List<Dog^>^>();
	competitors->Clear();

	if (handler)
	{
		DBErrorType result = handler->getAllDogs(dogs);

		if (result != DBErrorType::OK)
		{
			MessageBox::Show(
				marshal_as<String^>(DBErrorString.at(result)),
				"Information error",
				MessageBoxButtons::OK);
		}
		else
		{
			for each (Dog^ dog in dogs)
			{
				if (!competitors->ContainsKey(dog->getCategory()))
				{
					competitors[dog->getCategory()] = gcnew List<TopDogShow::Dog^>;
				}
				competitors[dog->getCategory()]->Add(dog);
			}
		}		
	}
}

Dictionary<String^, List<TopDogShow::Dog^>^>^ TopDogShow::Competitors::getCompetitors()
{
	this->loadCompetitors();
	return competitors;
}