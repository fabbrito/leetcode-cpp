#include "pch.h"
#include <C70_Climbing_Stairs/Solution70.h>

int main(int argc, char** argv)
{
	auto code = test_70();
#ifndef DEBUG
	std::cin.get();
#endif
	return code;
}