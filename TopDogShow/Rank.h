#pragma once

namespace TopDogShow {
	using namespace System;

	public ref class Rank
	{

	public:
		[System::ComponentModel::DisplayName("Points")]
		property int points;

		[System::ComponentModel::DisplayName("Name")]
		property String^ name;

		[System::ComponentModel::DisplayName("Place")]
		property int place;

		int bestMark;
		int totalAttempts;

		Rank(String^ name, int bestMark, int points, int totalAttempts)
		{
			this->name = name;
			this->bestMark = bestMark;
			this->place = 0;
			this->points = points;
			this->totalAttempts = totalAttempts;
		}
	};
}
