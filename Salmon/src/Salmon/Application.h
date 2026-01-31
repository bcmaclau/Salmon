#pragma once

#include "Core.h"

namespace Salmon{

	class SALMON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined by client
	Application* CreateApplication();
}
