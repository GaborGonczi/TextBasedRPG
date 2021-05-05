workspace "Game"
	architecture "x86"
	configurations {"Debug","Relase"}
	project "Engine"
		kind "StaticLib"
		language "C++"
		targetdir "bin/%{cfg.buildcfg}/%{cfg.architecture}/%{cfg.kind}"
		files{ "src/Engine/cpp/*.cpp","src/Engine/h/*.h"}
		includedirs { "src/Engine/h/" }
	 
		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

		filter "configurations:Release"
		 defines { "NDEBUG" }
		 optimize "On"

		filter "system:windows"
		 systemversion "latest"