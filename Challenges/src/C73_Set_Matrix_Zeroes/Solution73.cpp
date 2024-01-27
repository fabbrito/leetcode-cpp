#include "pch.h"
#include "Solution73.h"

namespace leetcode_73 {
	using namespace std;
	class Solution;
}

class leetcode_73::Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix.front().size();

		vector<int> vRows(n, 1), vCols(m, 1);
		
		// Find the zeros and mark their positions in the rows and cols vectors, respectively
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 0) {
					vRows[i] = 0;
					vCols[j] = 0;
				}
			}
		}
		// Set zeros to the rows and columns, following the data in the data vectors
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vRows[i] == 0 || vCols[j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

int test_73()
{
	using namespace leetcode_73;
	struct Test {
		vector<vector<int>> matrix;
		vector<vector<int>> expected;
	};
	vector<Test> tests = { // \[(([0-9],*)+)\] regex to change from [] to {}
		{{{0,1,2,0},{3,4,5,2},{1,3,1,5}},{{0,0,0,0},{0,4,5,0},{0,3,1,0}}},
		{{{1,1,1},{1,0,1},{1,1,1}},{{1,0,1},{0,0,0},{1,0,1}}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.matrix);
		solution.setZeroes(test.matrix);
		utils::printMatrix(test.matrix);
		std::cout << "\r\n";
		if (test.matrix != test.expected) return 1;
	}
	return 0;
}