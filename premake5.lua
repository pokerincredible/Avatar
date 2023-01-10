workspace "VenusStudio"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Venus"
	location "Venus"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AR_PLATFORM_WINDOWS",
			"AR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "VE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "VE_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "VE_Dist"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Venus/vendor/spdlog/include",
		"Venus/src"
	}

	links
	{
		"Venus"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AR_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "AR_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "AR_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "AR_Dist"
			optimize "On"
