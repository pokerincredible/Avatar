#pragma once

#ifdef AR_PLATFORM_WINDOWS

extern AR::Application* AR::CreateApplication();

int main(int argc, char** argv)
{
	AR::Log::Init();
	AR_CORE_WARN("Initialized Log!");
	int a = 6;
	AR_INFO("Hello! Var={0}", a);
	auto app = AR::CreateApplication();
	app->Run();
	delete app;
}

#endif // AR_PLATFORM_WINDOWS
