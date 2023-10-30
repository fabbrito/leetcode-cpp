#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include "./Solution.h"
#include "printVector.h"


std::vector<int> leetcode_1::Solution::twoSumSimple(std::vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target)
				return { i, j };
		}
	}
	return { };
}

std::vector<int> leetcode_1::Solution::twoSumMap(std::vector<int>& nums, int target) {
	int n = nums.size();
	std::unordered_map<int, int> diff_to_idx;
	for (int i = 0; i < n; i++) {
		int diff = target - nums[i];
		if (diff_to_idx.count(diff) != 0) {
			return { diff_to_idx[diff], i };
		}
		else {
			diff_to_idx[nums[i]] = i;
		}
	}
	return { -1,-1 };
}

template<typename T>
std::vector<int> leetcode_1::Solution::sortIndexes(std::vector<T>& vec)
{
	// initialize original index locations
	std::vector<int> idx(vec.size());
	std::iota(idx.begin(), idx.end(), 0);

	// sort indexes based on comparing values in vec
	sort(idx.begin(), idx.end(),
		[&vec](int i1, int i2) {return vec[i1] < vec[i2]; });

	return idx;
}

std::vector<int> leetcode_1::Solution::twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> indexes = sortIndexes(nums);
	std::sort(nums.begin(), nums.end());
	int start = 0, end = nums.size() - 1, sum = 0;
	while (start < end) {
		sum = nums[start] + nums[end];
		if (sum == target) {
			return std::vector<int> { indexes[start], indexes[end] };
		}
		else if (sum > target) {
			end--;
		}
		else {
			start++;
		}
	}
	return std::vector<int>();
}


int test_1() {
	using namespace leetcode_1;
	Solution* solution = new Solution;
	std::vector<int> result;
	struct Test {
		std::vector<int> vec;
		int target;
		std::vector<int> expected;
	};

	std::vector<Test> tests = {
		{{2,7,11,15}, 9, {0,1}},
		{{15,7,11,-2}, 9, {2,3}},
		{{3,2,4}, 6, {1,2}},
		{{3,3}, 6, {0,1}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.vec, ", ", false);
		std::cout << ", " << test.target << " -> ";
		result = solution->twoSumMap(test.vec, test.target);
		utils::printVector(result);
		if (result != test.expected) return 1;
	}

	return 0;
}