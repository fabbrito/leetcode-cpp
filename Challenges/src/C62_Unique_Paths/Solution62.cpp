#include "pch.h"
#include "Solution62.h"

namespace leetcode_62 {
	using namespace std;
	class Solution;
}

class leetcode_62::Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> memo(m, vector<int>(n, 0));

		// Initialize the rightmost column and bottom row to 1 because there is only one way to reach each cell in those rows/columns.
		for (int i = 0; i < m; i++) {
			memo[i][n - 1] = 1;
		}
		for (int j = 0; j < n; j++) {
			memo[m - 1][j] = 1;
		}

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				memo[i][j] = memo[i + 1][j] // moves down
					+ memo[i][j + 1]; // moves right
			}
		}

		return memo[0][0];
	}

	int uniquePathsRecursive(int m, int n) {
		vector<vector<int>> memo(m, vector<int>(n, -1));
		memo[m - 1][n - 1] = 1;
		return helper(0, 0, m, n, memo);
	}
private:
	int helper(int i, int j, int m, int n, vector<vector<int>>& memo) {
		if (memo[i][j] != -1) {
			return memo[i][j];
		}
		// base cases: only one way if in the last column or in the last row
		if (i == m - 1 || j == n - 1) {
			memo[i][j] = 1;
			return 1;
		}

		int moves_right = helper(i, j + 1, m, n, memo);
		int moves_down = helper(i + 1, j, m, n, memo);
		int moves = moves_right + moves_down;
		memo[i][j] = moves;
		return moves;
	}
};

int test_62()
{
	using namespace leetcode_62;
	struct Test {
		int m, n;
		int expected;
	};
	vector<Test> tests = {
		{1,1,1},
		{3,2,3},
		{3,7,28},
		{21,12,84672315},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		auto result0 = solution.uniquePaths(test.m, test.n);
		auto result1 = solution.uniquePathsRecursive(test.m, test.n);
		cout << test.m << " x " << test.n << " -> " << result0 << " "<< result1 << "\r\n";
		if (result0 != result1 || result0 != test.expected) return 1;
	}
	cout << "m x n -> Iterative Recursive\r\n";
	return 0;
}