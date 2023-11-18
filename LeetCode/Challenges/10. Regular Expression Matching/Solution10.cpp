#include "pch.h"
#include "./Solution10.h"

namespace leetcode_10 {
	class Solution {
	public:
		bool isMatch(std::string s, std::string p);
	};
}

bool leetcode_10::Solution::isMatch(std::string s, std::string p) {
	int n = s.length(), m = p.length();
	// with vectors
	std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
	dp[0][0] = true;

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			}
			else {
				dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
	}
	return dp[n][m];
}

int test_10() {
	using namespace leetcode_10;
	Solution solution;
	bool result = false;
	struct Test {
		std::string s;
		std::string p;
		bool expected;
	};
	std::vector<Test> tests = {
		{"cdab", "ab*", false},
		{"aa", "a", false},
		{"aa", "a*", true},
		{"ab", ".*", true},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.isMatch(test.s, test.p);
		std::cout << test.s << " " << test.p << " " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}