workspace "LinkedList"
configurations { "Debug" }

project "LinkedList"
kind "ConsoleApp"
language "C"
cdialect("C23")
targetdir "../bin/"

files { "**.h", "**.c" }

filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"
