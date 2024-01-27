#include "pch.h"
#include "Solution74.h"

namespace leetcode_74 {
	using namespace std;
	class Solution;
}

class leetcode_74::Solution {
public:
	// Time: O(log(n)+log(m)) = O(log(n*m))
	// Space: O(1)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1])
			return false;

		// binary search along the first column to find in which row target might be in
		int left = 0, right = matrix.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target < matrix[mid][0]) {
				right = mid - 1;
			}
			else if (target > matrix[mid][0]) {
				left = mid + 1;
			}
			else {
				return true;
			}
		}

		// binary search to check if target is in the found row
		int i = right;
		left = 0, right = matrix[0].size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target < matrix[i][mid]) {
				right = mid - 1;
			}
			else if (target > matrix[i][mid]) {
				left = mid + 1;
			}
			else {
				return true;
			}
		}
		return false;
	}

	// Time: O(m+n)
	// Space: O(1)
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		if (target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1])
			return false;
		int x = 0, y = matrix[0].size() - 1;
		while (x < matrix.size() && y >= 0) {
			if (matrix[x][y] > target) {
				y--;
			}
			else if (matrix[x][y] < target) {
				x++;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

int test_74()
{
	using namespace leetcode_74;
	struct Test {
		vector<vector<int>> matrix;
		int target;
		bool expected;
	};
	vector<Test> tests = { // \[(([0-9],*)+)\] regex to change from [] to {}
		{{{1,3,5,7},{8,10,12,14},{15,17,19,21},{22,24,26,28}},0,false},
		{{{1,3,5,7},{8,10,12,14},{15,17,19,21},{22,24,26,28}},1,true},
		{{{1,3,5,7},{8,10,12,14},{15,17,19,21},{22,24,26,28}},2,false},
		{{{1,3,5,7},{8,10,12,14},{15,17,19,21},{22,24,26,28}},21,true},
		{{{1,3,5,7},{8,10,12,14},{15,17,19,21},{22,24,26,28}},28,true},
		{{{1,3,5,7},{8,10,12,14},{15,17,19,21},{22,24,26,28}},30,false},
		{{{1,3,5,7},{10,11,16,20},{23,30,34,60}},3,true},
		{{{1,3,5,7},{10,11,16,20},{23,30,34,60}},13,false}
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.matrix, true);
		auto result0 = solution.searchMatrix(test.matrix, test.target);
		auto result1 = solution.searchMatrix2(test.matrix, test.target);
		std::cout << ", " << test.target << " -> " << result0 << " | " << result1 << "\r\n";
		if (result0 != test.expected || result1 != test.expected) return 1;
	}
	return 0;
}