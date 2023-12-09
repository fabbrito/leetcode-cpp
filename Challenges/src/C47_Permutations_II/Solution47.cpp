#include "pch.h"
#include "Solution47.h"

namespace leetcode_47 {
	using namespace std;
	class Solution;
}

class leetcode_47::Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		solve(nums, 0, nums.size(), result);
		return result;
	}
private:
	static void solve(vector<int> nums, int pStart, int pEnd, vector<vector<int>>& result) {
		if (pStart == pEnd - 1) {
			result.push_back(nums);
			return;
		}
		for (int k = pStart; k < pEnd; k++) {
			if (pStart != k && nums[pStart] == nums[k]) {
				continue;
			}
			swap(nums[pStart], nums[k]);
			solve(nums, pStart + 1, pEnd, result);
		}
	}
};

int test_47()
{
	using namespace leetcode_47;
	struct Test {
		vector<int> nums;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{2,2,1,1},{{1,1,2,2},{1,2,1,2},{1,2,2,1},{2,1,1,2},{2,1,2,1},{2,2,1,1}}},
		{{1,1,2},{{1,1,2},{1,2,1},{2,1,1}}},
		{{1,2,3},{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
		{{0,1},{{0,1},{1,0}}},
		{{1},{{1}}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		cout << " -> ";
		vector<vector<int>> result = solution.permuteUnique(test.nums);
		utils::printMatrix(result, true);
		cout << "\r\n";

		sort(result.begin(), result.end());
		if (result != test.expected) return 1;
	}
	return 0;
}