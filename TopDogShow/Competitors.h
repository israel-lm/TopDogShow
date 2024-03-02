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
		Dictionary<String^, List<Dog^>^>^ competitorsByCategory = nullptr;
		Dictionary<String^, Dog^>^ competitorsByName = nullptr;

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

		Dictionary<String^, List<Dog^>^>^ getCompetitorsByCategory();
		Dictionary<String^, Dog^>^ getCompetitorsByName();
	};
}


