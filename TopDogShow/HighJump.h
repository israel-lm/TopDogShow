#pragma once

#include "MarkTableDiscipline.h"

namespace TopDogShow
{
	public ref class HighJump : public MarkTableDiscipline
	{
	public:
		HighJump()
		{
			headerLabel->Text = L"High Jump";
		}

		void saveMarks() override {}
	};
}