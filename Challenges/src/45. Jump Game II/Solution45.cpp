#include "pch.h"
#include "Solution45.h"

namespace leetcode_45 {
	using namespace std;
	class Solution;
}

class leetcode_45::Solution {
public:
	int jump(vector<int>& nums) {
		// modifies nums[i] to hold the maximum index we go up to in a single jump from i
		for (int i = 1; i < nums.size(); i++) {
			nums[i] = max(nums[i] + i, nums[i - 1]);
		}
		int ind = 0;
		int ans = 0;
		// accumulates the count of these maximized jumps.
		while (ind < nums.size() - 1) {
			ans++;
			ind = nums[ind];
		}
		return ans;
	}
};


//class leetcode_45::MySolution {
//public:
//	int jump(vector<int>& nums) {
//		vector<int> memo(nums.size(), -1);
//		int ans = minJumps(nums, 0, memo);
//		return ans;
//	}
//private:
//	int minIgnoreNegative(int a, int b) {
//		if (a < 0) return b;
//		if (b < 0) return a;
//		return min(a, b);
//	}
//	int minJumps(vector<int>& nums, int idx, vector<int>& memo) {
//		int answer = -1;
//		if (idx >= nums.size() - 1)
//			answer = 0;
//		else {
//			if (memo[idx] != -1) {
//				return memo[idx];
//			}
//			for (int jumps = nums[idx]; jumps > 0 ; jumps--) {
//				int idx_subproblem = idx + jumps;
//				if (idx_subproblem >= nums.size()) continue;
//				int subproblem = minJumps(nums, idx_subproblem, memo);
//				if (subproblem != -1)
//					answer = minIgnoreNegative(subproblem + 1, answer);
//			}
//		}
//		memo[idx] = answer;
//		return answer;
//	}
//};

int test_45()
{
	using namespace leetcode_45;
	Solution solution;
	struct Test {
		vector<int> nums;
		int expected;
	};
	vector<Test> tests = {
		{{5,9,3,2,1,0,2,3,3,1,0,0},3},
		{{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},8},
		{{2,3,0,1,4},2},
		{{2,3,1,1,4},2},
		{{2},0},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		utils::printVector(test.nums);
		int result = solution.jump(test.nums);
		cout << " = " << result << endl;
		if (result != test.expected) return 1;
	}
	return 0;
}