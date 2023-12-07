#include "pch.h"
#include "Solution54.h"

namespace leetcode_54 {
	using namespace std;
	class Solution;
}

class leetcode_54::Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return {};
		}
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> result(m * n, 0);
		int idx = 0;
		// bounds
		int top = 0, bottom = m - 1, left = 0, right = n - 1;
		while ((top <= bottom && left <= right) || idx > m * n) {
			// Traverse right
			for (int i = left; i <= right; i++) {
				result[idx++] = matrix[top][i];
			}
			top++;
			// Traverse down
			for (int i = top; i <= bottom; i++) {
				result[idx++] = matrix[i][right];
			}
			right--;
			// Traverse left
			if (top <= bottom) {
				for (int i = right; i >= left; i--) {
					result[idx++] = matrix[bottom][i];
				}
				bottom--;
			}
			// Traverse up
			if (left <= right) {
				for (int i = bottom; i >= top; i--) {
					result[idx++] = matrix[i][left];
				}
				left++;
			}
		}
		return result;
	}
};

int test_54()
{
	using namespace leetcode_54;
	struct Test {
		vector<vector<int>> matrix;
		vector<int> expected;
	};
	vector<Test> tests = {
		{{{1,2},{3,4}},{1,2,4,3}},
		{{{1,2,3},{4,5,6},{7,8,9}},{1,2,3,6,9,8,7,4,5}},
		{{{1,2,3,4},{5,6,7,8},{9,10,11,12}},{1,2,3,4,8,12,11,10,9,5,6,7}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.matrix);
		auto result = solution.spiralOrder(test.matrix);
		utils::printVector(result);
		cout << "\r\n";
		cout << "----------------------------------------------------\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}