#include "printVector.h"

namespace utils {
	template <typename T>
	void printVector(const std::vector<T>& vec, std::string separator, bool endlFlag) {
		std::cout << "{ ";
		for (std::size_t i = 0; i < vec.size(); i++) {
			if (i < vec.size() - 1) std::cout << vec[i] << separator;
			else std::cout << vec[i];
		}
		std::cout << " }";
		if (endlFlag)
			std::cout << std::endl;
	}

	// help with templates: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
	template void printVector(const std::vector<int>& vec, std::string separator, bool endlFlag);
	template void printVector(const std::vector<char>& vec, std::string separator, bool endlFlag);
	template void printVector(const std::vector<std::string>& vec, std::string separator, bool endlFlag);
}