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
		POINT
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
				result = a->bestMark.CompareTo(b->bestMark);
				break;
			case Element::PLACE:
				result = a->place.CompareTo(b->place);
				break;
			case Element::POINT:
				result = a->points.CompareTo(b->points);
				break;
			}
			return result;
		}
	};
}

