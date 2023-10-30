#include <iostream>
#include <string>
#include <vector>
#include "./Solution.h"

int leetcode_7::Solution::reverse(int x) {
	int ans = 0;
	while (x) {
		// check 32 bit range if r is outside the range then return 0
		// the check is done a step before the overflow occurs
		if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
		// find remainder and add its to r
		ans = ans * 10 + x % 10;
		// Update the value of x
		x /= 10;
	}
	return ans;
}

int test_7() {
	using namespace leetcode_7;
	Solution* solution = new Solution;
	int result;
	struct Test {
		int x;
		int expected;
	};
	std::vector<Test> tests = {
		{123, 321},
		{-123, -321},
		{120, 21},
		{1534236469, 0}
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->reverse(test.x);
		std::cout << test.x << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}