workspace "DArray"
configurations { "Debug" }

project "DArray"
kind "ConsoleApp"
language "C"
targetdir "bin/"

files { "**.h", "**.c" }

filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"
