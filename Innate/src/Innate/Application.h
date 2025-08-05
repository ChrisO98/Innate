#pragma once

#include "Core.h"

namespace Innate {
	
	class INNATE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
