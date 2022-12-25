#include "Avatar.h"
#include <iostream>

class Sandbox : public AR::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

AR::Application* AR::CreateApplication()
{
	return new Sandbox();
}