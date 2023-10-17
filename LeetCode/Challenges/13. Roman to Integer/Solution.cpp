#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Solution.h"

namespace leetcode_13 {
	int Solution::romanTovalue(char c) {
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

	int Solution::romanToIntSwitch(std::string s) {
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (romanTovalue(s[i]) < romanTovalue(s[i+1])) {
				res -= romanTovalue(s[i]);
			}
			else {
				res += romanTovalue(s[i]);
			}
		}
		return res;
	}

	int Solution::romanToInt(std::string s)
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
			if (romanMap[s[i]] < romanMap[s[i+1]]) {
				res -= romanMap[s[i]];
			}
			else {
				res += romanMap[s[i]];
			}
		}
		return res;
	}
}

int test_13()
{
	using namespace leetcode_13;
	Solution* solution = new Solution;
	int result = 0;
	struct Test {
		std::string s;
		int expected;
	};
	std::vector<Test> tests = {
		{"D", 500},
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
		result = solution->romanToIntSwitch(test.s);
		std::cout << test.s << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}