#include <iostream>
#include <string>
#include <vector>
#include "./Solution.h"

int leetcode_8::Solution::myAtoi(std::string s) {
	int n = s.length();
	int64_t r = 0;
	int p = 0, sign = 1;
	bool started = false;
	while (p < n) {
		// check for spaces
		if (s[p] == 32 && !started) {
			p++;
			continue;
		}
		// check for valid negative number
		else if (!started && s[p] == 45 && (p + 1) < n && s[p + 1] >= 48 && s[p + 1] <= 57) {
			started = true;
			sign = -1;
		}
		// check for valid positive number
		else if (!started && s[p] == 43 && (p + 1) < n && s[p + 1] >= 48 && s[p + 1] <= 57) {
			started = true;
			sign = 1;
		}
		// check for valid digits
		else if (s[p] >= 48 && s[p] <= 57) {
			started = true;
			r = 10 * r + (static_cast<int64_t>(s[p]) - 48);
			if (r * sign > INT_MAX) return INT_MAX;
			if (r * sign < INT_MIN) return INT_MIN;
		}
		else
			return static_cast<int32_t>(r * sign);

		p++;
	}
	return static_cast<int32_t>(r * sign);
}

int test_8() {
	using namespace leetcode_8;
	Solution* solution = new Solution;
	int result = 0;
	struct Test {
		std::string s;
		int expected;
	};
	std::vector<Test> tests = {
		{"00000-42a1234", 0},
		{"42", 42},
		{"-42", -42},
		{"+42", 42},
		{"   -42", -42},
		{"++-12", 0},
		{"4193 with words", 4193},
		{"2147483648", 2147483647},
		{"-2147483649", -2147483648},
		{"abs  12", 0},
		{"12 12", 12},
	};


	std::cout << " Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->myAtoi(test.s);
		std::cout << test.s << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;

}