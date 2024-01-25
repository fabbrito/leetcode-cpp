#include "pch.h"
#include "Solution70.h"

namespace leetcode_70 {
	using namespace std;
	class Solution;
}

class leetcode_70::Solution {
public:
	int climbStairs(int n) {
		if (n <= 2)
			return n;
		vector<int> memo(n + 1, 0);
		memo[1] = 1, memo[2] = 2;
		for (int v = 3; v <= n; v++) {
			memo[v] = memo[v - 1] + memo[v - 2];
		}
		return memo[n];
	}

	int climbStairsSimple(int n) {
		if (n <= 1)
			return n;
		int prev = 1, curr = 1;
		for (int i = 2; i <= n; i++) {
			int temp = curr;
			curr = prev + curr;
			prev = temp;
		}
		return curr;
	}
};

int test_70()
{
	using namespace leetcode_70;
	struct test_t {
		int n;
		int expected;
	};
	vector<test_t> tests = {
		{2,2},
		{3,3},
		{5,8},
		{45,1836311903},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		auto result0 = solution.climbStairs(test.n);
		auto result1 = solution.climbStairsSimple(test.n);
		std::cout << test.n << " -> " << result0 << " | " << result1 << "\r\n";
		if (result0 != test.expected || result1 != test.expected) return 1;
	}

	return 0;
}