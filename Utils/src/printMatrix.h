#ifndef PRINT_MATRIX_H_INCLUDED
#define PRINT_MATRIX_H_INCLUDED

namespace utils {
	template <typename T>
	void printMatrix(const std::vector<std::vector<T>>& vec, std::string separator = ", ", bool endlFlag = true);
}

#endif