#pragma once

#include <memory>
#include <string>

#include "IDiscipline.h"
#include "Constants.h"

namespace TopDogShow 
{
	using namespace System::Windows::Forms;

	class DisciplineFactory
	{
	private:
		static DisciplineFactory* instance;

		DisciplineFactory();

	public:
		DisciplineFactory(const DisciplineFactory& instance) = delete;

		Form^ createDiscipline(DisciplineType disciplineType, String^ dogName);
		static DisciplineFactory* getInstance();
		virtual ~DisciplineFactory() {}
	};
}