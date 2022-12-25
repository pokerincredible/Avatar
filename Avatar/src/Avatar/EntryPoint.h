#pragma once

#ifdef AR_PLATFORM_WINDOWS

extern AR::Application* AR::CreateApplication();

int main(int argc, char** argv)
{
	auto app = AR::CreateApplication();
	app->Run();
	delete app;
}

#endif // AR_PLATFORM_WINDOWS
