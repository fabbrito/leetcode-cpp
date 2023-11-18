#include "pch.h"
#include "Solution40.h"

namespace leetcode_40 {
	using namespace std;
	class Solution;
}

class leetcode_40::Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& nums, int target) noexcept {
		vector<vector<int>> result = {};
		vector<int> v_solution = {};
		sort(nums.begin(), nums.end());
		size_t start_index = 0;
		solve(start_index, target, nums, result, v_solution);
		return result;
	}
private:
	void solve(size_t index, int target, vector<int>& nums, vector<vector<int>>& result, vector<int>& v_solution) noexcept {
		//base case
		if (target == 0) {
			result.push_back(v_solution);
			return;
		}
		for (size_t i = index; i < nums.size(); i++) {
			if (nums[i] > target)
				return;
			if (i > index && nums[i] == nums[i - 1])
				continue;
			//to avoid picking up the same elements and thus avoiding duplicates (no picking of element)
			v_solution.push_back(nums[i]);
			solve(i + 1, target - nums[i], nums, result, v_solution);
			v_solution.pop_back();
		}
	}
};


int test_40()
{
	using namespace leetcode_40;
	Solution solution;
	vector<vector<int>> result;
	struct Test {
		vector<int> nums;
		int target;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{10,1,2,7,6,1,5},8,{{1,1,6},{1,2,5},{1,7},{2,6}}},
		{{2,5,2,1,2},5,{{1,2,2},{5}}},
		{{2,3,5},8,{{3,5}}},
		{{2,2,3,6,7},7,{{2,2,3},{7}}},
		{{2},1,{}},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		result = solution.combinationSum2(test.nums, test.target);
		utils::printVector(test.nums, ", ", false);
		cout << ", " << test.target << " -> ";
		utils::printMatrix(result, true);
		cout << endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
