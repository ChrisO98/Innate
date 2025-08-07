#pragma once
#include <iostream>

#ifdef IN_PLATFORM_WINDOWS

extern Innate::Application* Innate::CreateApplication();

int main(int argc, char** argv)
{
	Innate::Log::Init();
	IN_CORE_WARN("Initialized Log!");
	int a = 5;
	IN_INFO("Hello Var={0}", a);

	auto app = Innate::CreateApplication();
	app->Run();
	delete app;
	std::cin.get(); // Wait for keypress
	return 0;
}

#endif