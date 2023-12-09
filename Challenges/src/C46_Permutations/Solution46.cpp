#include "pch.h"
#include "Solution46.h"

namespace leetcode_46 {
	using namespace std;
	class Solution;
}

class leetcode_46::Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		solve(nums, 0, nums.size() - 1, result);
		return result;
	}
private:
	// Backtracking
	static void solve(vector<int>& nums, int pStart, int pEnd, vector<vector<int>>& result) {
		if (pStart == pEnd) {
			result.push_back(nums);
			return;
		}

		for (int i = pStart; i <= pEnd; i++) {
			swap(nums[pStart], nums[i]);
			solve(nums, pStart + 1, pEnd, result);
			swap(nums[pStart], nums[i]);
		}
	}
};

int test_46()
{
	using namespace leetcode_46;
	struct Test {
		vector<int> nums;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{1,2,3},{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
		{{0,1},{{0,1},{1,0}}},
		{{1},{{1}}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		cout << " -> ";
		vector<vector<int>> result = solution.permute(test.nums);
		utils::printMatrix(result, true);
		cout << "\r\n";

		sort(result.begin(), result.end());
		if (result != test.expected) return 1;
	}
	return 0;
}