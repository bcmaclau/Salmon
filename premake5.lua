workspace "Salmon"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Salmon"
	location "Salmon"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
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
			"SMN_PLATFORM_WINDOWS",
			"SMN_BUILD_DLL"
		}

		postbuildcommands
		{
			--"copy bin\\%{cfg.buildcfg}\\${cfg.system}\\%{cfg.architecture}\\%{prj.name}.dll bin\\%{cfg.buildcfg}\\${cfg.system}\\%{cfg.architecture}\\Sandbox"
			"COPY $(TargetDir)\\Salmon.dll $(SolutionDir)\\bin\\Debug-windows-x86_64\\Sandbox"
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "SMN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SMN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SMN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/*.h",
		"%{prj.name}/src/*.cpp"
	}

	includedirs
	{
		"Salmon/vendor/spdlog/include",
		"Salmon/src"
	}

	links
	{
		"Salmon" 
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SMN_PLATFORM_WINDOWS"
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "SMN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SMN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SMN_DIST"
		optimize "On"