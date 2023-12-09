#include "pch.h"
#include "Solution64.h"

namespace leetcode_64 {
	using namespace std;
	class Solution;
}

class leetcode_64::Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid.front().size();
		vector<vector<int>> m_dist = grid;
		// fills last column
		for (int i = m - 2; i >= 0; i--) {
			m_dist[i][n - 1] = m_dist[i][n - 1] + m_dist[i + 1][n - 1];
		}
		// fills last row
		for (int j = n - 2; j >= 0; j--) {
			m_dist[m - 1][j] = m_dist[m - 1][j] + m_dist[m - 1][j + 1];
		}
		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				m_dist[i][j] = min(m_dist[i + 1][j], m_dist[i][j + 1]) + grid[i][j];
			}
		}
		return m_dist[0][0];
	}
};

int test_64()
{
	using namespace leetcode_64;
	struct Test {
		vector<vector<int>> grid;
		int expected;
	};
	vector<Test> tests = {
		{{{1}},1},
		{{{3,2,1}},6},
		{{{3},{2},{1}},6 },
		{{{1,3,1},{1,5,1},{4,2,1}},7},
		{{{1,2,3},{4,5,6}},12},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.grid, true);
		auto result = solution.minPathSum(test.grid);
		std::cout << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}