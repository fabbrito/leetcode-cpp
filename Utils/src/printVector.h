#ifndef PRINT_VECTOR_H_INCLUDED
#define PRINT_VECTOR_H_INCLUDED

namespace utils {
	template <typename T>
	void printVector(const std::vector<T>& vec, std::string separator = ", ", bool endlFlag = true);
}

#endif