#include "pch.h"
#include "Solution39.h"

namespace leetcode_39 {
	using namespace std;
	class Solution;
}


class leetcode_39::Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& nums, int target) noexcept {
		vector<vector<int>> result = {};
		vector<int> vec = {};
		sort(nums.begin(), nums.end());
		solve(nums, target, 0, result, vec);
		return result;
	}
private:
	static void solve(vector<int>& nums, int target, int next, vector<vector<int>>& result, vector<int>& vec) noexcept {
		if (target == 0) {
			result.push_back(vec);
			return;
		}

		if (next == nums.size() || target < nums[next])
			return;

		vec.push_back(nums[next]);
		solve(nums, target - nums[next], next, result, vec);
		vec.pop_back();

		solve(nums, target, next + 1, result, vec);
	}
};


int test_39()
{
	using namespace leetcode_39;
	Solution solution;
	vector<vector<int>> result;
	struct Test {
		vector<int> nums;
		int target;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{2,3,5},8,{{2,2,2,2},{2,3,3},{3,5}}},
		{{2,3,6,7},7,{{2,2,3},{7}}},
		{{2},1,{}},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		utils::printVector(test.nums, ", ", false);
		cout << ", " << test.target << " -> ";
		result = solution.combinationSum(test.nums, test.target);
		utils::printMatrix(result, true);
		cout << endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
