#include "pch.h"
#include "Solution33.h"

namespace leetcode_33 {
	class Solution {
	public:
		int search(std::vector<int>& nums, int target);
		int mySearch(std::vector<int>& nums, int target);
	};
}

int leetcode_33::Solution::search(std::vector<int>& nums, int target) {
	int start = 0, end = nums.size() - 1;
	int mid = (start + end) / 2;
	while (start <= end) {
		mid = (start + end) / 2;
		if (target == nums[mid]) {
			return mid;
		}
		if (nums[start] <= nums[mid]) { // left side sorted
			if (nums[start] <= target && nums[mid] >= target) { // target within index range [start, mid]
				end = mid - 1;
			}
			else { // target within index range (mid, end]
				start = mid + 1;
			}
		}
		else { // right side sorted
			if (nums[end] >= target && nums[mid] <= target) { // target within index range [mid, end]
				start = mid + 1;
			}
			else { // target within index range [start, mid)
				end = mid - 1;
			}
		}
	}
	return -1;
}

int leetcode_33::Solution::mySearch(std::vector<int>& nums, int target) {
	int n = nums.size();

	//calculate index k of pivot
	int p = n / 2;
	int i = 0;
	while (p < n && i < p) {
		if (nums[i] > nums[p]) {
			p = (i + p) / 2;
		}
		else {
			i = p;
			p = (n + p) / 2;
		}
	}
	int k = n - p - 1;

	p = n / 2;
	i = 0;
	int real_pivot = 0;
	while (p < n && i < p) {
		real_pivot = p - k < 0 ? n + p - k : p - k;
		if (target > nums[real_pivot]) {
			i = p;
			p = (n + p) / 2;
		}
		else if (target < nums[real_pivot]) {
			p = (i + p) / 2;
		}
		else
			return real_pivot;
	}
	real_pivot = p - k < 0 ? n + p - k : p - k;
	if (target == nums[real_pivot])
		return real_pivot;
	return -1;
}

int test_33() {
	using namespace leetcode_33;
	Solution solution;
	int result;
	struct Test {
		std::vector<int> nums;
		int target;
		int expected;
	};
	std::vector<Test> tests = {
		{{0,1,2,4,5,6,7}, 0, 0},
		{{7,0,1,2,4,5,6}, 0, 1},
		{{6,7,0,1,2,4,5}, 0, 2},
		{{5,6,7,0,1,2,4}, 0, 3},
		{{4,5,6,7,0,1,2}, 0, 4},
		{{2,4,5,6,7,0,1}, 0, 5},
		{{1,2,4,5,6,7,0}, 0, 6},
		{{4,5,6,7,0,1,2}, 3, -1},
		{{1}, 0, -1},
		{{1,3}, 3, 1},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.nums, ", ", false);
		result = solution.search(test.nums, test.target);
		std::cout << ", " << test.target << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}