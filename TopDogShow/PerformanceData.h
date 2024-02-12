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
	};

	
	public ref class TreadmilllPerformanceData : PerformanceData
	{
	public:
		int distance;

		TreadmilllPerformanceData(Dog^ dog, int distance)
		{
			this->distance = distance;
		}
	};
}


