#pragma once
#include "Rank.h"

namespace TopDogShow {
	using namespace System;

	enum class ResultType
	{
		UNDEFINED = -1,
		GENERAL = 1,
		CATEGORY = 10
	};

	enum class Element : int
	{
		MARK,
		PLACE,
		POINT,
		ATTEMPTS
	};

	public ref class CompareByElement : System::Collections::Generic::Comparer<Rank^>
	{
	private:
		Element comparator;
	public:

		CompareByElement(Element element)
		{
			this->comparator = element;
		}

		virtual int Compare(Rank^ a, Rank^ b) override
		{
			int result = -1;
			switch (comparator)
			{
			case Element::MARK:
				result = (a->bestMark > b->bestMark) ? -1 : 1;
				break;
			case Element::PLACE:
				result = (a->place < b->place) ? -1 : 1;
				break;
			case Element::POINT:
				result = (a->points > b->points) ? -1 : 1;
				break;
			case Element::ATTEMPTS:
				result = 0;
				if (
					(a->bestMark > 0 && b->bestMark > 0) && (a->bestMark == b->bestMark) ||
					(a->points > 0 && b->points > 0) && (a->points == b->points)
				)
					result = (a->totalAttempts < b->totalAttempts) ? -1 : 1;		
				
				break;
			}
			return result;
		}
	};
}

