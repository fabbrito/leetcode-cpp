#include <iostream>
#include <string>
#include <vector>
#include "Solution.h"


std::string leetcode_12::Solution::intToRoman(int num)
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


int test_12()
{
	using namespace leetcode_12;
	Solution* solution = new Solution;
	std::string result = "";
	struct Test {
		std::string expected;
		int num;
	};
	std::vector<Test> tests = {
		{"DI", 501},
		{"MCMXCIV", 1994},
		{"LVIII", 58},
		{"XXI",21},
		{"XXXII",32},
		{"XLIII",43},
		{"LIV",54},
		{"LXV",65},
		{"LXXVI",76},
		{"LXXXVII",87},
		{"XCVIII",98},
		{"XCIX",99},
		{"CCX",210},
		{"CCCXXI",321},
		{"CDXXXII",432},
		{"DXLIII",543},
		{"DCLIV",654},
		{"DCCLXV",765},
		{"DCCCLXXVI",876},
		{"CMLXXXVII",987},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->intToRoman(test.num);
		std::cout << test.num << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
