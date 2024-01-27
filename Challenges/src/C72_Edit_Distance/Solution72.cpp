#include "pch.h"
#include "Solution72.h"

namespace leetcode_72 {
	using namespace std;
	class Solution;
	class MySolution;
}


class leetcode_72::Solution {
public:
	int minDistance(string word0, string word1) {
		int n0 = word0.length(), n1 = word1.length();
		if (n0 == 0) return n1;
		if (n1 == 0) return n0;

		vector<vector<int>> dp(n0 + 1, vector<int>(n1 + 1, 0));

		for (int i = 0; i <= n0; ++i)
			dp[i][0] = i;

		for (int j = 0; j <= n1; ++j)
			dp[0][j] = j;

		for (int i = 1; i <= n0; ++i) {
			for (int j = 1; j <= n1; ++j) {
				if (word0[i - 1] != word1[j - 1])
					dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
				else
					dp[i][j] = dp[i - 1][j - 1];
			}
		}
		return dp[n0][n1];
	}
};

int test_72()
{
	using namespace leetcode_72;
	struct test_t {
		string word0, word1;
		int expected;
	};
	vector<test_t> tests = {
		{"zoologicoarchaeologist","zoogeologist", 10},
		{"horse", "", 5},
		{"horse", "ros", 3},
		{"intention", "execution", 5},
		{"weird","pouch", 5},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;

		auto result = solution.minDistance(test.word0, test.word1);
		std::cout << test.word0 << ", " << test.word1 << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}