#pragma once

#include "MarkTableDiscipline.h"

namespace TopDogShow
{
	public ref class WallClimb : public MarkTableDiscipline
	{
	public:
		WallClimb()
		{
			headerLabel->Text = L"Wall Climb";
		}

		void saveMarks() override  {}
	};
}
