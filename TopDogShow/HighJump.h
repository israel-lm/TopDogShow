#pragma once

#include "MarkTableDiscipline.h"

namespace TopDogShow
{
	public ref class HighJump : public MarkTableDiscipline
	{
	public:
		HighJump(String^ dogName): MarkTableDiscipline(dogName)
		{
			headerLabel->Text = L"High Jump";
		}

		void saveMarks() override {}
	};
}