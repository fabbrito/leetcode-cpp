#include <iostream>
#include <vector>
#include "./Solution.h"
#include "utils.h"

/* From: https://www.prepbytes.com/blog/cpp-programming/find-the-next-permutation-in-cpp/
* In this case, two helper functions are defined: reverse and nextPermutation.
* The reverse function takes a vector of integer nums and two indices start and end. It reorders the elements in the subarray nums[start…end].
* The nextPermutation function computes the next permutation in place given a vector of integer nums. It works as follows:
*	- Find the largest index i for which nums[i] < nums[i+1].
*	- If no such index exists, the array is already in descending order, and the next permutation cannot be computed.
*	- Calculate the largest index j such that nums[j] > nums[i]. Swap nums[i] and nums[j].
*	- Reverse the order of the elements from nums[i+1] to the end of the array.
*/

void leetcode_31::Solution::reverse(std::vector<int>& nums, int pStart, int pEnd) {
	while (pStart < pEnd) {
		std::swap(nums[pStart], nums[pEnd]);
		pStart++;
		pEnd--;
	}
	return;
}

void leetcode_31::Solution::nextPermutation(std::vector<int>& nums) {
	int n = nums.size();
	int i = n - 2;
	while (i >= 0 && nums[i] >= nums[i + 1])
		i--;
	if (i >= 0) {
		int j = n-1;
		while (j>=0 && nums[j] <= nums[i])
			j--;
		std::swap(nums[j], nums[i]);
	}
	reverse(nums, i + 1, n - 1);
	return;
}

int test_31() {
	using namespace leetcode_31;
	Solution* solution = new Solution;
	std::vector<int> result;
	struct Test {
		std::vector<int> nums;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{1,2,3}, {1,3,2}},
		{{1,3,2}, {2,1,3}},
		{{3,2,1}, {1,2,3}},
		{{1,1,5}, {1,5,1}},
		{{-1,2,3,4,5,6}, {-1,2,3,4,6,5}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.nums, ", ", false);
		std::cout << " -> ";
		solution->nextPermutation(test.nums);
		utils::printVector(test.nums);
		if (test.nums != test.expected) return 1;
		//if (result != test.expected) return 1;
	}
	return 0;
}