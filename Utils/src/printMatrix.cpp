#include <iostream>
#include <vector>
#include <string>
#include "printMatrix.h"
#include "printVector.h"

namespace utils {
	template <typename T>
	void printMatrix(const std::vector<std::vector<T>>& vec, std::string separator, bool endlFlag) {
		std::cout << "{";
		for (int outer_i = 0; outer_i < vec.size(); outer_i++) {
			printVector(vec[outer_i], ", ", false);
			if (outer_i < vec.size() - 1)
				std::cout << ", ";
		}
		std::cout << "}";
		if (endlFlag) std::cout << std::endl;
	}

	template void printMatrix(const std::vector<std::vector<std::string>>& vec, std::string separator, bool endlFlag);
	template void printMatrix(const std::vector<std::vector<int>>& vec, std::string separator, bool endlFlag);
}