#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Solution.h"
#include "utils.h"

namespace leetcode_18 {
	std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target) {
		std::vector<std::vector<int>> ans = std::vector<std::vector<int>>();
		if (nums.size() < 4) return ans;

		size_t n = nums.size();
		std::sort(nums.begin(), nums.end());

		if (nums[n - 1] < target / 4) return ans;

		for (size_t i = 0; i <= n - 4; i++) {
			if (target / 4 < nums[i])
				return ans;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (size_t j = i + 1; j <= n - 3; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				int32_t sum2 = nums[i] + nums[j];
				size_t pLeft = j + 1, pRight = n - 1;
				while (pLeft < pRight && pRight > j && pLeft < n) {
					// check if adding *pLeft would overflow int32_t
					if (sum2 < 0 && nums[pLeft] < INT_MIN - sum2) {
						pLeft++;
						continue;
					}
					if (sum2 > 0 && nums[pLeft] > INT_MAX - sum2) {
						pRight--;
						continue;
					}
					// then check if adding *pRight would overflow int32_t
					if (sum2 < 0 && nums[pLeft] < 0 && (nums[pRight] + nums[pLeft] < INT_MIN - sum2)) {
						pLeft++;
						continue;
					}
					if (sum2 > 0 && nums[pLeft] > 0 && (nums[pRight] + nums[pLeft] > INT_MAX - sum2)) {
						pRight--;
						continue;
					}
					int32_t sum4 = nums[i] + nums[j] + nums[pLeft] + nums[pRight];
					if (sum4 == target) {
						ans.push_back({ nums[i] , nums[j] , nums[pLeft] , nums[pRight] });
						// check for repeating sequence of numbers and discard all but the first match
						while (pLeft < pRight && nums[pRight] == nums[pRight - 1])
							pRight--;
						while (pLeft < pRight && nums[pLeft] == nums[pLeft + 1])
							pLeft++;
						pLeft++, pRight--;
					}
					else if (sum4 > target) {
						pRight--;
					}
					else {
						pLeft++;
					}
				}
			}
		}
		return ans;
	}
}

int test_18() {
	using namespace leetcode_18;
	Solution* solution = new Solution;
	std::vector<std::vector<int>> result;
	struct Test {
		std::vector<int> nums;
		int target;
		std::vector<std::vector<int>> expected;
	};
	std::vector<Test> tests = {
		{{0,0,0,1000000000,1000000000,1000000000,1000000000}, 1000000000, {{0,0,0,1000000000}}},
		{{0,0,0,-1000000000,-1000000000,-1000000000,-1000000000}, -1000000000, {{0,0,0,-1000000000}}},
		{{1,0,-1,0,-2,2}, 0, {{-2,-1,1,2}, {-2,0,0,2} , {-1,0,0,1}}},
		{{2,2,2,2,2}, 8, {{2,2,2,2}}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->fourSum(test.nums, test.target);
		utils::printVector(test.nums, ", ", false);
		std::cout << ", " << test.target << " -> ";
		utils::printMatrix(result);
		//utils::printVector(result);
		// if (result != test.expected) return 1;
	}
	return 0;
}