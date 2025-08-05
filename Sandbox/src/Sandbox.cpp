#include <Innate.h>


class Sandbox : public Innate::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}
};

Innate::Application* Innate::CreateApplication()
{
	return new Sandbox();
}