#include "pch.h"
#include "Solution81.h"

namespace leetcode_81 {

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (target == nums[mid]) {
				return true;
			}

			if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
				left++;
				right--;
			}
			else if (nums[left] <= nums[mid]) { // left side sorted
				if (nums[left] <= target && target < nums[mid]) { // target within index range [left, mid]
					right = mid - 1;
				}
				else { // target within index range (mid, right]
					left = mid + 1;
				}
			}
			else { // right side sorted
				if (nums[mid] < target && target <= nums[right]) { // target within index range [mid, right]
					left = mid + 1;
				}
				else { // target within index range [left, mid)
					right = mid - 1;
				}
			}
		}
		return false;
	}
};
}

int test_81() {
	using namespace leetcode_81;
	struct test_t {
		vector<int> nums;
		int target;
		int expected;
	};
	vector<test_t> tests = {
		// \[(([0-9]*,*)+)\] -> {$1} regex to change from [1,2,3] to {1,2,3}
		// \[((("[A-Za-z]")*,*)+)\] -> {$1} regex to change from ["A","B","C"] to {"A","B","C"}
		{{1,1,0,1,1,1,1},0,true},
		{{1,1,0,1,1,1,1},2,false},
		{{2,5,6,0,0,1,2},0,true},
		{{2,5,6,0,0,1,2},1,true},
		{{2,5,6,0,0,1,2},2,true},
		{{2,5,6,0,0,1,2},3,false},
		{{1,2,2,5,6,0,0},0,true},
		{{1,2,2,5,6,0,0},1,true},
		{{1,2,2,5,6,0,0},2,true},
		{{1,2,2,5,6,0,0},3,false},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		auto result = solution.search(test.nums, test.target);
		std::cout << ", " << test.target << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}
