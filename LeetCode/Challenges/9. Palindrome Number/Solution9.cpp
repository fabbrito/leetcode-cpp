#include "pch.h"
#include "./Solution9.h"

namespace leetcode_9 {
	class Solution {
	public:
		bool isPalindrome(int x);
	};
}

bool leetcode_9::Solution::isPalindrome(int x)
{
	// A negative number can't be a palindrome by the definition
	// Numbers ending with 0 also can't be one, since leading zeros aren't allowed
	if (x < 0 || (x != 0 && x % 10 == 0)) return false;

	int reversed = 0;
	// Do the reverse number algorithm until we consume half of the digits of x
	while (x > reversed) {
		reversed = reversed * 10 + x % 10;
		x /= 10;
	}
	// Compare the last reversed and the digits of x not consumed
	// Considering both cases where log10(x) is odd and even
	return (x == reversed) || (x == reversed / 10);
}


int test_9() {
	using namespace leetcode_9;
	Solution solution;
	bool result = 0;
	struct Test {
		int x;
		bool expected;
	};
	std::vector<Test> tests = { {123, false}, {-123, false}, {120, false}, {121, true} };

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.isPalindrome(test.x);
		std::cout << test.x << " " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}