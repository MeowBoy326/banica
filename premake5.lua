
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
        ("{COPY} ../vendor/raylib/lib/raylib.dll ../bin/" .. outputdir .. "/Banica")
    }
    
    
    cppdialect "C++20"
    staticruntime "On"
    systemversion "latest"

    filter "action:vs*"
      defines "VS"

    filter "action:gmake*"
      defines "MAKE"
    
    filter "configurations:Debug"
      defines "BNC_DEBUG"
      symbols "On"
    
    filter "configurations:Release"
      defines "BNC_BUILD"
      optimize "On"
