#include "pch.h"
#include "Solution63.h"

namespace leetcode_63 {
	using namespace std;
	class Solution;
}

class leetcode_63::Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid.front().size();
		// "Exit" is blocked!
		if (grid[m - 1][n - 1]) return 0;
		vector<vector<int64_t>>memo(m, vector<int64_t>(n, 0));

		// fill last column with 1, dealing with obstacles
		for (int i = 0; i < m; i++) {
			//if obstacle found, invalidate previous spots
			if (grid[i][n - 1]) {
				for (int prev_i = i - 1; prev_i >= 0; prev_i--) {
					memo[prev_i][n - 1] = 0;
				}
			}
			else {
				memo[i][n - 1] = 1;
			}
		}
		// fill last row with 1, dealing with obstacles
		for (int j = 0; j < n; j++) {
			//if obstacle found, invalidate previous spots
			if (grid[m - 1][j]) {
				for (int prev_j = j - 1; prev_j >= 0; prev_j--) {
					memo[m - 1][prev_j] = 0;
				}
			}
			else {
				memo[m - 1][j] = 1;
			}
		}

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				if (grid[i][j]) continue;
				memo[i][j] = memo[i + 1][j] + memo[i][j + 1];
			}
		}
		return memo[0][0];
	}
};

int test_63()
{
	using namespace leetcode_63;
	struct Test {
		vector<vector<int>> grid;
		int expected;
	};
	vector<Test> tests = {
		{{{0,0,1},{0,0,0},{0,0,0}},5},
		{{{0,0,0},{0,0,1},{0,0,0}},3},
		{{{0,0,0},{0,1,0},{0,0,0}},2},
		{{{0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}},8},
		{{{0,1},{0,0}},1},
		{{{1}},0},
		{{{0}},1},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.grid, true);
		auto result = solution.uniquePathsWithObstacles(test.grid);
		std::cout << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}