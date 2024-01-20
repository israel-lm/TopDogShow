#pragma once

namespace TopDogShow
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref struct MarksData
	{
		float mark;
		bool result;
		int attempts;
	};

	public ref struct PerformanceData
	{
		String^ dogName;
	};

	public ref struct MarkTablePerformanceData : public PerformanceData
	{
		List<MarksData^>^ marks;
	};

	public ref struct LongJumpPerformanceData : PerformanceData
	{
		List<float> marks;
	};

	public ref struct TreadmillPerformanceData : PerformanceData
	{
		float distance;
	};
}


