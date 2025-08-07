// Local Windows Debugger - Configuration Properties → Debugging → Command → $(TargetPath) its now $(SolutionDir)setup.bat
// and Working Directory was $(ProjectDir) its now $(SolutionDir)

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