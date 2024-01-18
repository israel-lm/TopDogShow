#pragma once

#include "MarkTableDiscipline.h"

namespace TopDogShow
{
	public ref class WallClimb : public MarkTableDiscipline
	{
	public:
		WallClimb(String^ dogName): MarkTableDiscipline(dogName)
		{

			headerLabel->Text = L"Wall Climb";
		}

		void saveMarks() override  {}
	};
}
