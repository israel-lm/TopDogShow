#pragma once

#include <map>
#include <list>
#include <string>
#include <msclr\marshal_cppstd.h>

#include "Dog.h"
#include "DBHandler.h"
#include "Constants.h"

namespace TopDogShow
{
	using namespace msclr::interop;
	using namespace System::Collections::Generic;

	public ref class Competitors
	{
	private:
		static Competitors^ instance = gcnew Competitors();
		Dictionary<Categories, List<Dog^>^>^ competitors;

		Competitors();
		void loadCompetitors();

	public:
		static property Competitors^ Instance
		{
			Competitors^ get()
			{
				return instance;
			}
		}

		Dictionary<Categories, List<Dog^>^>^ getCompetitors();
	};
}


