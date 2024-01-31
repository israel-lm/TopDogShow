#pragma once

namespace TopDogShow
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class MarksData
	{
	public:
		bool result;
		int attempts;
	};

	[Serializable]
	public ref class PerformanceData
	{
	public:
		String^ dogName;
	};

	[Serializable]
	public ref class MarkTablePerformanceData : public PerformanceData
	{
	public:
		Dictionary<int, MarksData^>^ marks;

		MarkTablePerformanceData()
		{
			marks = gcnew Dictionary<int, MarksData^>();
		}		
	};

	[Serializable]
	public ref class LongJumpPerformanceData : PerformanceData
	{
	public:
		List<int>^ marks;

		LongJumpPerformanceData()
		{
			marks = gcnew List<int>();
		}
	};

	[Serializable]
	public ref class TreadmilllPerformanceData : PerformanceData
	{
	public:
		int distance;
	};
}


