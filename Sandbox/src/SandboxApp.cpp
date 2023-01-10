#include "Venus.h"
#include <iostream>

class Sandbox : public VE::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

VE::Application* VE::CreateApplication()
{
	return new Sandbox();
}