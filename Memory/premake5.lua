workspace "Memory"
configurations { "Debug" }

project "Memory"
kind "ConsoleApp"
language "C"
cdialect("C23")
targetdir "bin/"

files { "**.h", "**.c" }

filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"
