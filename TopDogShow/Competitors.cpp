#include "Competitors.h"

using namespace System::Collections::Generic;
using namespace System;


TopDogShow::Competitors::Competitors()
{
	this->loadCompetitors();
}


void TopDogShow::Competitors::loadCompetitors()
{
	DBHandler^ handler = DBHandler::Instance;
	List<TopDogShow::Dog^>^ dogs = gcnew List<TopDogShow::Dog^>;
	

	if (!competitorsByCategory)
		competitorsByCategory = gcnew Dictionary<Categories^, List<Dog^>^>();
	if (!competitorsByName)
		competitorsByName = gcnew Dictionary<String^, Dog^>();
	
	competitorsByCategory->Clear();
	competitorsByName->Clear();

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
				if (!competitorsByCategory->ContainsKey(dog->getCategory()))
				{
					competitorsByCategory[dog->getCategory()] = gcnew List<TopDogShow::Dog^>;
				}
				competitorsByCategory[dog->getCategory()]->Add(dog);
				competitorsByName[dog->getName()] = dog;
			}
		}		
	}
}

Dictionary<TopDogShow::Categories^, List<TopDogShow::Dog^>^>^ TopDogShow::Competitors::getCompetitorsByCategory()
{
	return competitorsByCategory;
}

Dictionary<String^, TopDogShow::Dog^>^ TopDogShow::Competitors::getCompetitorsByName()
{
	return competitorsByName;
}