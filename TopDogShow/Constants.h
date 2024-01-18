#pragma once
#include <map>
#include <msclr\marshal_cppstd.h>

namespace TopDogShow
{
	using namespace System;
	using namespace msclr::interop;

	public enum class DisciplineType: int
	{
		Undefined = -100,
		WallClimb = 1,
		HighJump,
		LongJump,
		Treadmil
	};

	public ref class Categories
	{
	public:
		literal String^ LIGHT_WEIGHT = "Lightweight";
		literal String^ MIDDLE_WEIGHT = "Middleweight";
		literal String^ HEAVY_WEIGHT = "Heavyweight";
	};
}

