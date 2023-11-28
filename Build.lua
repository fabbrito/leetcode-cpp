workspace "LeetCode"
architecture "x64"
configurations {"Debug", "Release", "Dist"}
startproject "Challenges"

-- Workspace-wide build options for MSVC
filter "system:windows"
buildoptions {"/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus"}

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Utils"
include "Utils/Build-Utils.lua"
group ""

include "Challenges/Build-Challenges.lua"
