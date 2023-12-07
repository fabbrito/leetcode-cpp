#include "pch.h"
#include "Solution59.h"

namespace leetcode_59 {
	using namespace std;
	class Solution;
}

class leetcode_59::Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, -1));
		int top = 0, bottom = n - 1, left = 0, right = n - 1;
		int val = 1;
		while (top <= bottom && left <= right) {
			// Traverse right
			for (int i = left; i <= right; i++) {
				matrix[top][i] = val++;
			}
			top++;
			// Traverse down
			for (int i = top; i <= bottom; i++) {
				matrix[i][right]=val++;
			}
			right--;
			// Traverse left
			if (top <= bottom) {
				for (int i = right; i >= left; i--) {
					matrix[bottom][i]=val++;
				}
				bottom--;
			}
			// Traverse up
			if (left <= right) {
				for (int i = bottom; i >= top; i--) {
					matrix[i][left]=val++;
				}
				left++;
			}
		}
		return matrix;
	}
};

int test_59()
{
	using namespace leetcode_59;
	struct Test {
		int n;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{4,{{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}}},
		{3,{{1,2,3},{8,9,4},{7,6,5}}},
		{2,{{1,2},{4,3}}},
		{1,{{1}}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		auto result = solution.generateMatrix(test.n);
		cout << test.n << " -> ";
		utils::printMatrix(result, true);
		cout << "\r\n";

		if (result != test.expected) return 1;
	}
	return 0;
}