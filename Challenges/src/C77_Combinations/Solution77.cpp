#include "pch.h"
#include "Solution77.h"

namespace leetcode_77 {

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) {
				--i;
			}
			else if (i == k - 1) {
				result.push_back(p);
			}
			else {
				++i;
				p[i] = p[i - 1];
			}
		}
		return result;
	}

public:
	vector<vector<int>> combineRecursive(int n, int k) {
		vector<int> vec;
		vector<vector<int>> res = {};
		helper(n, k, 1, vec, res);
		return res;
	}

private:
	static void helper(int n, int k, int idx, vector<int>& vec,
		vector<vector<int>>& res) {
		// base case
		if (k == vec.size()) {
			res.push_back(vec);
			return;
		}
		for (int i = idx; i < n + 1; ++i) {
			vec.push_back(i);
			helper(n, k, i + 1, vec, res);
			vec.pop_back();
		}
	}
};

}  // namespace leetcode_77

int test_77() {
	using namespace leetcode_77;
	struct test_t {
		int n, k;
		vector<vector<int>> expected;
	};
	vector<test_t> tests = {
		// \[(([0-9],*)+)\] -> {$1} regex to change from [1,2,3] to {1,2,3}
		{4, 2, {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}},
		{4, 3, {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}}},
		{1, 1, {{1}}},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		auto result = solution.combine(test.n, test.k);
		std::cout << test.n << ", " << test.k << " -> ";
		utils::printMatrix(result, true, ", ");
		std::cout << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}
