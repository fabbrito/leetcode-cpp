#include "pch.h"
#include "Solution55.h"

namespace leetcode_55 {
	using namespace std;
	class Solution;
}

class leetcode_55::Solution {
public:
	bool canJump(vector<int>& nums) {
		// modifies nums[i] to hold the maximum index we go up to in a single jump from i
		for (int i = 1; i < nums.size(); i++) {
			nums[i] = max(nums[i] + i, nums[i - 1]);
		}
		int idx = 0;
		int jumps = 0;
		// accumulates the count of these maximized jumps.
		while (idx < nums.size() - 1 && jumps < nums.size()) {
			jumps++;
			idx = nums[idx];
		}
		return jumps != nums.size();
	}
};

int test_55()
{
	using namespace leetcode_55;
	struct Test {
		vector<int> nums;
		bool expected;
	};
	vector<Test> tests = {
		{{0},true},
		{{1,1,1,1,1},true},
		{{3,2,1,0,4},false},
		{{2,3,1,1,4},true},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		auto result = solution.canJump(test.nums);
		cout << " -> " << result << endl;
		if (result != test.expected) return 1;
	}
	return 0;
}