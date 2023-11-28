#include "pch.h"
#include "./Solution34.h"


namespace leetcode_34 {
	class Solution {
	public:
		std::vector<int> searchRange(std::vector<int>& nums, int target);

		int lower_bound(std::vector<int>& nums, int target);
		std::vector<int> searchRange2(std::vector<int>& nums, int target);
	};
}

int leetcode_34::Solution::lower_bound(std::vector<int>& nums, int target) {
	int l = 0, r = nums.size();
	while (l < r) {
		int m = l + (r - l) / 2;
		if (nums[m] >= target)
			r = m;
		else
			l = m + 1;
	}
	return l;
}

std::vector<int> leetcode_34::Solution::searchRange2(std::vector<int>& nums, int target) {
	int l = 0, r = nums.size();
	int s = lower_bound(nums, target);
	int e = lower_bound(nums, target + 1) - 1;
	if (s < nums.size() && nums[s] == target) {
		return { s, e };
	}
	return { -1, -1 };
}

std::vector<int> leetcode_34::Solution::searchRange(std::vector<int>& nums, int target)
{
	int n = nums.size();
	int start = 0, end = n - 1;
	int i = (start + end) / 2;
	// Binary search for an index with the target value
	bool found = false;
	while (start <= end) {
		i = (start + end) / 2;
		if (nums[i] > target)
			end = i - 1;
		else if (nums[i] < target)
			start = i + 1;
		else {
			found = true;
			break;
		}
	}
	if (!found) return { -1,-1 };

	int temp = i;
	int j = 0;
	// find the start of the sequence
	while (start < i) {
		j = (start + i) / 2; // rounds to the left of the middle
		if (nums[j] < target)
			start = j + 1;
		else
			i = j;
	}
	start = i;
	i = temp;
	// find the end of the sequence
	while (i < end) {
		j = (i + end + 1) / 2; // rounds to the right of the middle
		if (nums[j] > target)
			end = j - 1;
		else
			i = j;
	}
	end = i;
	return { start, end };
}

int test_34()
{
	using namespace leetcode_34;
	Solution solution;
	std::vector<int> result;
	struct Test {
		std::vector<int> nums;
		int target;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{5,7,7,8,8,8,8,8,8,8,8,10}, 8, {3,10}},
		{{5,7,7,8,8,8,8,8,8,8,8,8}, 8, {3,11}},
		{{5,7,7,8,8,8,8,8,8,8,8,10}, 7, {1,2}},
		{{5,7,7,8,8,10}, 6, {-1,-1}},
		{{5,7,7,8,8,8,8,8,8,8,8,10}, 10, {11,11}},
		{{5,7,7,8,8,8,8,8,8,8,8,10}, 9, {-1,-1}},
		{{5,7,7,8,8,8,8,8,8,8,8,9,10}, 9, {11,11}},
		{{1,1,1,1,1,1,1,1,1,1,2}, 1, {0,9}},
		{{}, 0, {-1,-1}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.nums, ", ", false);
		std::cout << ", " << test.target << " -> ";
		result = solution.searchRange(test.nums, test.target);
		utils::printVector(result);
		if (result != test.expected) return 1;
	}
	return 0;
}