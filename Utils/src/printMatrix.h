#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace utils {
	template <typename T>
	void printMatrix(const std::vector<std::vector<T>>& vec, bool flat = false, std::string separator = ", ");
}
