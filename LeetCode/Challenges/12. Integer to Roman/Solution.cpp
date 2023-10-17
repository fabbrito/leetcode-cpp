#include <iostream>
#include <string>
#include <vector>
#include "Solution.h"

namespace leetcode_12 {
	std::string Solution::intToRoman(int num)
	{
		std::string res = "";
		std::vector<char> romanLetters = { 'I', 'V', 'X', 'L', 'C', 'D' , 'M' };
		std::vector<int> romanValues = { 1, 5, 10, 50, 100, 500, 1000 };

		int order = 0;
		std::string aux = "";
		while (num > 0 && order < 3) {
			int val = num % 10;
			aux = "";
			if (val == 9 || val == 4) {
				// smaller one to the left of the string to indicate subtraction
				aux += romanLetters[2 * order]; // 1**
				aux += romanLetters[2 * order + (val / 5) + 1]; // (val == 9) 10** or (val == 4) 5**
			}
			if (val >= 5 && val <= 8) {
				aux += romanLetters[2 * order + 1]; // 5**
				val -= 5;
			}
			if (val > 0 && val <= 3) {
				for (int i = 0; i < val; i++) {
					aux += romanLetters[2 * order]; // 1**
				}
			}
			res = aux + res;
			num /= 10;
			order++;
		}
		if (num > 0) {
			aux = "";
			for (int i = 0; i < num; i++) {
				aux += 'M';
			}
			res = aux + res;
		}
		return res;
	}
}

int test_12()
{
	using namespace leetcode_12;
	Solution* solution = new Solution;
	std::string result = "";
	struct Test {
		int num;
		std::string expected;
	};
	std::vector<Test> tests = {
		{3, "III"},
		{58, "LVIII"},
		{1994, "MCMXCIV"},
	};

	std::cout << "Testing Solution" << std::endl;
	for (int o = 0; o < 3; o++) {
		for (int v = 1; v < 10; v++) {
			int num = v * std::pow(10, o) + (v - 1) * (int) std::pow(10, o - 1) + (v - 2) * (int)std::pow(10, o - 2) + (v - 3) * (int)std::pow(10, o - 3);
			result = solution->intToRoman(num);
			std::cout << num << " -> " << result << std::endl;
		}
	}
	/*for (auto& test : tests) {
		result = solution->intToRoman(test.num);
		std::cout << test.num << " -> " << result << std::endl;
	}*/
	return 0;
}
