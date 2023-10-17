#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Solution.h"
#include "printVector.h"

namespace leetcode_1 {
	std::vector<int> Solution::twoSumSimple(std::vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
					return { i, j };
			}
		}
		return { };
	}

	template<typename T>
	std::vector<int> Solution::sortIndexes(std::vector<T>& vec)
	{
		// initialize original index locations
		std::vector<int> idx(vec.size());
		std::iota(idx.begin(), idx.end(), 0);

		// sort indexes based on comparing values in vec
		sort(idx.begin(), idx.end(),
			[&vec](int i1, int i2) {return vec[i1] < vec[i2]; });

		return idx;
	}

	std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
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
}

int test_1() {
	using namespace leetcode_1;
	using utils::printVector;
	Solution* solution = new Solution;
	std::vector<int> result;
	struct Test { std::vector<int> vec; int target; };

	std::vector<Test> tests = {
		{{15, 7, 11, -2}, 9},
		{{3, 2, 4}, 6},
		{{3, 3}, 6},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		printVector(test.vec, ", ", false);
		std::cout << ", " << test.target << " -> ";
		result = solution->twoSum(test.vec, test.target);
		printVector(result);
	}

	return 0;
}