#pragma once
#include "Dog.h"

namespace TopDogShow
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class MarksData
	{
	public:
		bool result;
		int attempts;

		MarksData(int attempts, bool result)
		{
			this->attempts = attempts;
			this->result = result;
		}
	};


	public ref class PerformanceData
	{
	public:
		Dog^ dog;

		virtual int getBestResult() = 0;
		virtual int getTotalAttempts() = 0;
	};


	public ref class MarkTablePerformanceData : public PerformanceData
	{
	public:
		Dictionary<int, MarksData^>^ marks;

		MarkTablePerformanceData(Dog^ dog, Dictionary<int, MarksData^>^ marks)
		{
			this->dog = dog;
			this->marks = marks;
		}	

		int getBestResult() override
		{
			int max = 0;

			for each (KeyValuePair<int, MarksData^>^ kvp in marks)
			{
				if (kvp->Key > max && kvp->Value->result)
					max = kvp->Key;
			}

			return max;
		}

		int getTotalAttempts() override
		{
			int totalAttempts = 0;

			for each (KeyValuePair<int, MarksData^> ^ kvp in marks)
			{
				if (kvp->Value->result)
					totalAttempts += kvp->Value->attempts;
			}

			return totalAttempts;
		}
	};

	
	public ref class LongJumpPerformanceData : PerformanceData
	{
	public:
		List<int>^ marks;

		LongJumpPerformanceData(Dog^ dog, List<int>^ markValues)
		{
			this->dog = dog;
			marks = markValues;
		}

		int getBestResult() override
		{
			int max = 0;
			for each (int value in marks)
			{
				if (value > max)
					max = value;
			}

			return max;
		}

		int getTotalAttempts() override
		{
			return marks->Count;
		}
	};

	
	public ref class TreadmilllPerformanceData : PerformanceData
	{
	public:
		int distance;

		TreadmilllPerformanceData(Dog^ dog, int distance)
		{
			this->distance = distance;
		}

		int getBestResult() override
		{
			return distance;
		}

		int getTotalAttempts() override
		{
			return 1;
		}
	};
}


