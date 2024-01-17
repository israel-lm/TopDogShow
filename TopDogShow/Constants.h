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


	public enum class Categories: int
	{
		LIGHT_WEIGHT = 10,
		MEDIUM_WEIGHT = 20,
		HEAVY_WEIGHT = 30
	};


	static std::map<int, std::string> CategoryString = {
		{(int)Categories::LIGHT_WEIGHT, "Lightweight"},
		{(int)Categories::MEDIUM_WEIGHT, "Middleweight"},
		{(int)Categories::HEAVY_WEIGHT, "Heavyweight"}
	};
}

