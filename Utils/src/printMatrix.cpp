#include "printVector.h"
#include "printMatrix.h"

namespace utils {
	template <typename T>
	void printMatrix(const std::vector<std::vector<T>>& vec, bool flat, std::string separator) {
		std::cout << (flat ? "{ " : "{\r\n");
		for (int outer_i = 0; outer_i < vec.size(); outer_i++) {
			if (!flat) std::cout << "  ";
			printVector(vec[outer_i], separator, false);
			if (outer_i < vec.size() - 1)
				std::cout << separator;
			std::cout << (flat ? " " : "\r\n");
		}
		std::cout << (flat ? "}" : "}\r\n");
	}

	template void printMatrix(const std::vector<std::vector<std::string>>& vec, bool flat, std::string separator);
	template void printMatrix(const std::vector<std::vector<int>>& vec, bool flat, std::string separator);
	template void printMatrix(const std::vector<std::vector<char>>& vec, bool flat, std::string separator);
}