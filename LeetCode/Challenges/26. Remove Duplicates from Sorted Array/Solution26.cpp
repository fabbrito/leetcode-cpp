#include "pch.h"
#include "./Solution26.h"

namespace leetcode_26 {
	class Solution {
	public:
		int removeDuplicates(std::vector<int>& nums);
	};
}

namespace leetcode_26 {
	int Solution::removeDuplicates(std::vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return 1;
		int pCurr = 0, pIns = 0;
		int pNext = 0;
		// pIns is the pointer to the next available position in the unique vector (beginning of nums)
		// pCurr traverses the vector from one unique element to another
		// pNext points to the next unique element in the vector
		while (pCurr < n) {
			pNext = pCurr;
			// If repeating sequence of numbers found
			if (pCurr + 1 < n && nums[pCurr + 1] == nums[pCurr]) {
				// Traverse to the last one of the repeating sequence
				while (pNext < n && nums[pNext] == nums[pCurr]) {
					pNext++;
				}
				pNext--;
			}
			pNext++;
			// Swap values 
			if (pIns != pCurr)
				std::swap(nums[pIns], nums[pCurr]);
			pIns++;
			pCurr = pNext;
		}
		return pIns;
	}
}
int test_26() {
	using namespace leetcode_26;
	Solution solution;
	int result;
	struct Test {
		std::vector<int> nums;
		int expected;
	};
	std::vector<Test> tests = {
		{{0,0,0}, 1},
		{{0,0,1,1,1,2,2,3,3,4}, 5},
		{{0,1,2}, 3},
		{{0}, 1},
		{{1,1,2}, 2},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		result = solution.removeDuplicates(test.nums);
		utils::printVector(test.nums, ", ", false);
		std::cout << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}