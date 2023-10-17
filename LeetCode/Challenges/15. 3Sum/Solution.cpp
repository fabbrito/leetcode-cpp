#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "Solution.h"
#include "printVector.h"

namespace leetcode_15 {
	std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums) {
		int n = nums.size();
		std::sort(nums.begin(), nums.end());

		std::vector<std::vector<int>> ans;

		for (int i = 0; i < n - 2; i++) {
			// first > 0 => all elements > 0
			if (nums[i] > 0)
				return ans;
			// check for repeating sequence of numbers inside the sorted vector
			// only the first one will be utilized in the logic to save time
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			// using 2 pointers, find the first 3 entries whose sum equals 0
			int pLeft = i + 1, pRight = n - 1;
			while (pLeft < pRight) {
				int triplet_sum = nums[i] + nums[pLeft] + nums[pRight];
				if (triplet_sum == 0) {
					ans.push_back({ nums[i], nums[pLeft], nums[pRight] });
					// check for repeating sequence of numbers and discard all but one
					while (pLeft < pRight && nums[pRight] == nums[pRight - 1])
						pRight--;
					while (pLeft < pRight && nums[pLeft] == nums[pLeft + 1])
						pLeft++;
					pLeft++, pRight--;
				}
				else if (triplet_sum > 0)
					pRight--;
				else
					pLeft++;
			}
		}
		return ans;
	};
}

int test_15() {
	using namespace leetcode_15;
	Solution* solution = new Solution;
	std::vector<std::vector<int>> result;
	struct Test {
		std::vector<int> nums;
		std::vector<std::vector<int>> expected;
	};
	std::vector<Test> tests = {
		{{ -2, 0, 1, 1, 2}, {{ -2, 0, 2 }, { -2, 1, 1 }}},
		{{ -1, 0, 1, 2, -1, -4 }, {{ -1, -1, 2 } ,{ -1, 0, 1 }}},
		{{ 0, 1, 1 }, {}},
		{{ 0, 0, 0 }, {{ 0, 0, 0 }}},
		{{ 0, 0, 0, 0 }, {{ 0, 0, 0 }}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->threeSum(test.nums);
		utils::printVector(test.nums, ", ", false);
		std::cout << " -> { ";
		for (int i = 0; i < result.size(); i++) {
			utils::printVector(result[i], ", ", false);
			if (i < result.size() - 1)
				std::cout << ", ";
		}
		std::cout << " }" << std::endl;

		// if (result != test.expected) return 1;
	}
	return 0;
}