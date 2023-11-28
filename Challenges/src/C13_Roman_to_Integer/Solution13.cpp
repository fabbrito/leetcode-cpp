#include "pch.h"
#include "./Solution13.h"

namespace leetcode_13 {
	class Solution {
	public:
		int romanToValue(char c);
		int romanToIntSwitch(std::string s);
		int romanToInt(std::string s);
	};
}

int leetcode_13::Solution::romanToValue(char c) {
	int r = 0;
	switch (c) {
	case 'I':
		r = 1;
		break;
	case 'V':
		r = 5;
		break;
	case 'X':
		r = 10;
		break;
	case 'L':
		r = 50;
		break;
	case 'C':
		r = 100;
		break;
	case 'D':
		r = 500;
		break;
	case 'M':
		r = 1000;
		break;
	default:
		break;
	}
	return r;
}

int leetcode_13::Solution::romanToIntSwitch(std::string s) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (romanToValue(s[i]) < romanToValue(s[i + 1])) {
			res -= romanToValue(s[i]);
		}
		else {
			res += romanToValue(s[i]);
		}
	}
	return res;
}

int leetcode_13::Solution::romanToInt(std::string s)
{
	std::unordered_map<char, int> romanMap = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (romanMap[s[i]] < romanMap[s[i + 1]]) {
			res -= romanMap[s[i]];
		}
		else {
			res += romanMap[s[i]];
		}
	}
	return res;
}


int test_13()
{
	using namespace leetcode_13;
	Solution solution;
	struct Test {
		std::string s;
		int expected;
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
		int result0 = solution.romanToInt(test.s);
		int result1 = solution.romanToIntSwitch(test.s);
		std::cout << test.s << " -> " << result0 << " " << result1 << std::endl;
		if (result0 != test.expected || result1 != test.expected) return 1;
	}
	return 0;
}