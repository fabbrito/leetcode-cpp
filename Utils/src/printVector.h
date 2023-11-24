#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace utils {
	template <typename T>
	void printVector(const std::vector<T>& vec, std::string separator = ", ", bool endlFlag = false);
}