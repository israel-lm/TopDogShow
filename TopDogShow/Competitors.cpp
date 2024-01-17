#include "Competitors.h"

using namespace System::Collections::Generic;


TopDogShow::Competitors::Competitors()
{
	this->loadCompetitors();
}


void TopDogShow::Competitors::loadCompetitors()
{
	DBHandler^ handler = DBHandler::Instance;
	List<TopDogShow::Dog^>^ dogs = gcnew List<TopDogShow::Dog^>;

	if (!competitors)
		competitors = gcnew Dictionary<Categories, List<Dog^>^>();

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

Dictionary<TopDogShow::Categories, List<TopDogShow::Dog^>^>^ TopDogShow::Competitors::getCompetitors()
{
	return competitors;
}