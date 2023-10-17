#include <iostream>
#include <string>
#include <vector>
#include "Solution.h"

namespace leetcode_5 {
	std::string Solution::longestPalindrome(std::string s)
	{
		bool palindrome = true;

		for (int window = s.length(); window >= 1; window--) {
			for (int offset = 0; offset <= s.length() - window; offset++) {
				palindrome = true;
				for (int i = 0; i < window / 2; i++) {
					if (s[offset + i] != s[offset + window - i - 1]) {
						palindrome = false;
						break;
					}
				}
				if (palindrome) {
					return s.substr(offset, window);
				}
			}
		}
		return std::string();
	}
}

int test_5() {
	using namespace leetcode_5;
	Solution* solution = new Solution;
	std::string result;
	struct Test {
		std::string s;
		std::vector<std::string> expected;
	};
	std::vector<Test> tests = { {"babad", {"bab", "aba"}}, {"cbbd", {"bb"}} , {"sa", {"s"}} };

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->longestPalindrome(test.s);
		std::cout << test.s << " -> " << result << std::endl;
	}
	return 0;
}


