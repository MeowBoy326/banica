
workspace "Banica"
    configurations { 
        "Debug", 
        "Release" 
    }

    architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
   
project "Banica"
    location "Banica"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h"
    }
    
    includedirs
    {
      "vendor/raylib/include",
      "%{prj.name}/src",
      "vendor/raygui/include"
    }

    libdirs
    {
      "vendor/raylib/lib"
    }

    links
    {
      "raylibdll"
    }

    postbuildcommands
    {
        ("{COPY} ../vendor/raylib/lib/raylib.dll ../bin/" .. outputdir .. "/2223-9th-grade-sprint-math-games")
    }
    
    cppdialect "C++20"
    staticruntime "On"
    systemversion "latest"
    
    filter "configurations:Debug"
      symbols "On"
    
    filter "configurations:Release"
      defines "BN_BUILD"
      optimize "On"
