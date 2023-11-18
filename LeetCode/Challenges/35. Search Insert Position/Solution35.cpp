#include "pch.h"
#include "./Solution35.h"

namespace leetcode_35 {
	class Solution {
	public:
		int searchInsert(std::vector<int>& nums, int target);
	};
}

int leetcode_35::Solution::searchInsert(std::vector<int>& nums, int target)
{
	int l = 0, r = nums.size() - 1;
	while (l <= r) {
		int m = l + (r - l)/2;
		if (nums[m] == target)
			return m;
		else if (nums[m] > target)
			r = m - 1;
		else
			l = m + 1;
	}
	return r + 1;
}

int test_35()
{
	using namespace leetcode_35;
	Solution solution;
	int result;
	struct Test {
		std::vector<int> nums;
		int target;
		int expected;
	};
	std::vector<Test> tests = {
		{{1,3}, 2, 1},
		{{1,3,4,6}, 5, 3},
		{{1,3,4,6}, 4, 2},
		{{1,3,4,6}, 2, 1},
		{{1,3,4,6}, 7, 4},
		{{1,3,4,6}, 0, 0},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.nums, ", ", false);
		std::cout << ", " << test.target << " -> ";
		result = solution.searchInsert(test.nums, test.target);
		std::cout << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
