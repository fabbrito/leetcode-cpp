#include "pch.h"
#include "Solution41.h"

namespace leetcode_41 {
	using namespace std;
	class Solution;
}

class leetcode_41::Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		for (auto& n : nums)
			if (n <= 0 || n > size)
				n = size + 1;
		for (size_t i = 0; i < size; i++) {
			int n = abs(nums[i]);
			size_t n_idx = static_cast<size_t>(n - 1);
			if (n <= size && nums[n_idx] > 0)
				nums[n_idx] *= -1;
		}
		for (size_t i = 0; i < size; i++)
			if (nums[i] > 0)
				return static_cast<int>(i + 1);
		return size+1;
	}
};


int test_41()
{
	using namespace leetcode_41;
	Solution solution;
	int result;
	struct Test {
		vector<int> nums;
		int expected;
	};
	vector<Test> tests = {
		{{0,1,2,3,3},4},
		{{0,1,2,3},4},
		{{0,4,1,2},3},
		{{-1},1},
		{{1},2},
		{{3,4,-1,1},2},
		{{1,2,0},3},
		{{7,8,9,11,12},1},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		utils::printVector(test.nums, ", ", false);
		result = solution.firstMissingPositive(test.nums);
		cout << " -> " << result << endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
