#include "Solution39.h"
#include "utils.h"

class Solution {
public:
	using IntMat = std::vector<std::vector<int>>;
	using IntVec = std::vector<int>;
	IntMat combinationSum(IntVec& nums, int target) noexcept {
		IntMat result = {};
		IntVec vec = {};
		std::sort(nums.begin(), nums.end());
		solve(nums, target, 0, result, vec);
		return result;
	}
private:
	static void solve(IntVec& nums, int target, int next, IntMat& result, IntVec& vec) noexcept {
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
	Solution* solution = new Solution;
	std::vector<std::vector<int>> result;
	struct Test {
		std::vector<int> nums;
		int target;
		std::vector<std::vector<int>> expected;
	};
	std::vector<Test> tests = {
		{{2,3,5},8,{{2,2,2,2},{2,3,3},{3,5}}},
		{{2,3,6,7},7,{{2,2,3},{7}}},
		{{2},1,{}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.nums, ", ", false);
		std::cout << ", " << test.target << " -> ";
		result = solution->combinationSum(test.nums, test.target);
		utils::printMatrix(result, true);
		std::cout << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
