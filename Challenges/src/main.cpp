#include "pch.h"
#include <C64_Minimum_Path_Sum/Solution64.h>

int main(int argc, char** argv)
{
	auto code = test_64();
#ifndef DEBUG
	std::cin.get();
#endif
	return code;
}