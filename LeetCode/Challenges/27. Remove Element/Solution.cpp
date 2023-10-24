#include <iostream>
#include <vector>
#include "./Solution.h"
#include "utils.h"


int leetcode_27::Solution::removeElement(std::vector<int>& nums, int val)
{
	int n = nums.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] != val) {
			std::swap(nums[i], nums[j]);
			j++;
		}
	}
	return j;
}

int test_27() {
	using namespace leetcode_27;
	Solution* solution = new Solution;
	int result;
	struct Test {
		std::vector<int> nums;
		int val;
		int expected;
	};
	std::vector<Test> tests = {
		{{}, 4, 0},
		{{1}, 4, 1},
		{{3,2,2,3}, 3, 2},
		{{3,2,2,3}, 10, 4},
		{{0,1,2,2,3,0,4,2}, 2, 5},
		{{0,1,2,2,3,0,4,2,0,1,2,2,3,0,4}, 2, 10},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		utils::printVector(test.nums, ", ", false);
		std::cout << " val: " << test.val << std::endl;
		result = solution->removeElement(test.nums, test.val);
		utils::printVector(test.nums, ", ", false);
		std::cout << " res: " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}