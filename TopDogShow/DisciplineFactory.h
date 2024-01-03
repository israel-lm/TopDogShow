#pragma once

#include <memory>
#include <string>

#include "IDiscipline.h"

namespace TopDogShow 
{
	using namespace System::Windows::Forms;

	class DisciplineFactory
	{
	public:
		Form^ createDiscipline(std::string disciplineType);
		virtual ~DisciplineFactory() {}
	};
}