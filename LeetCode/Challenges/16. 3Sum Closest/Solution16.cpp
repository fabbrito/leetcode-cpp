#include "pch.h"
#include "Solution16.h"

namespace leetcode_16 {
	class Solution {
	public:
		int threeSumClosest(std::vector<int>& nums, int target);
	};
}


int leetcode_16::Solution::threeSumClosest(std::vector<int>& nums, int target) {
	int n = nums.size();
	std::sort(nums.begin(), nums.end());
	int ans = 0;

	// min distance to the target is either achieved from the 3 first
	// elements of the sorted vector or from the 3 last elements
	int minDistance = INT_MAX;

	for (int i = 0; i < n - 2; i++) {
		// check for repeating sequence of numbers inside the sorted vector
		// to save time, only the first one will be utilized in the logic
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		// using 2 pointers, find the first 3 entries whose sum is closest to target
		int pLeft = i + 1, pRight = n - 1;
		while (pLeft < pRight) {
			int triplet_sum = nums[i] + nums[pLeft] + nums[pRight];
			int distance = std::abs(triplet_sum - target);
			if (distance <= minDistance) {
				ans = triplet_sum;
				minDistance = distance;
			}
			// With an ordered vector, to reduce the value of the sum, move pRight to the left
			if (triplet_sum > target)
				pRight--;
			else
				pLeft++;
		}
	}
	return ans;
}


int test_16() {
	using namespace leetcode_16;
	Solution solution;
	int result;
	struct Test {
		std::vector<int> nums;
		int target;
		int expected;
	};
	std::vector<Test> tests = {
		{ {-1000, -5, -5, -5, -5, -5, -5, -1, -1, -1}, -14, -15 },
		{{ 0, 1, 2}, 3, 3},
		{{ 0, 0, 0}, 1, 0},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.threeSumClosest(test.nums, test.target);
		utils::printVector(test.nums, ", ", false);
		std::cout << ", " << test.target << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}