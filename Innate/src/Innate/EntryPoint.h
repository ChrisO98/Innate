#pragma once

#ifdef IN_PLATFORM_WINDOWS

extern Innate::Application* Innate::CreateApplication();

int main(int argc, char** argv)
{
	printf("Innate Engine\n");
	auto app = Innate::CreateApplication();
	app->Run();
	delete app;
}

#endif