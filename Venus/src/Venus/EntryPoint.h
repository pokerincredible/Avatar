#pragma once

#ifdef VE_PLATFORM_WINDOWS

extern VE::Application* VE::CreateApplication();

int main(int argc, char** argv)
{
	VE::Log::Init();
	VE_CORE_WARN("Initialized Log!");
	int a = 6;
	VE_INFO("Hello! Var={0}", a);
	auto app = VE::CreateApplication();
	app->Run();
	delete app;
}

#endif // VE_PLATFORM_WINDOWS
