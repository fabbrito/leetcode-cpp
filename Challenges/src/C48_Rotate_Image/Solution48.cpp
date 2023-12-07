#include "pch.h"
#include "Solution48.h"

namespace leetcode_48 {
	using namespace std;
	class Solution;
}

class leetcode_48::Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		size_t n = matrix.size();
		transpose(matrix);
		reverseColumns(matrix);
	}
private:
	static void transpose(vector<vector<int>>& matrix) {
		for (size_t r = 0; r < matrix.size(); r++) {
			for (size_t c = 0; c < r; c++) {
				swap(matrix[r][c], matrix[c][r]);
			}
		}
	}
	static void reverseColumns(vector<vector<int>>& matrix) {
		for (size_t r = 0; r < matrix.size(); r++) {
			reverse(matrix[r].begin(), matrix[r].end());
		}
	}
};

int test_48()
{
	using namespace leetcode_48;
	struct Test {
		vector<vector<int>> matrix;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}},{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}},
		{{{1,2,3},{4,5,6},{7,8,9}},{{7,4,1},{8,5,2},{9,6,3}}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.matrix);
		solution.rotate(test.matrix);
		utils::printMatrix(test.matrix);
		cout << "----------------------------------------------------\r\n";
		if (test.matrix != test.expected) return 1;
	}
	return 0;
}