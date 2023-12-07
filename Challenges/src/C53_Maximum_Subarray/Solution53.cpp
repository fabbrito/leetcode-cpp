#include "pch.h"
#include "Solution53.h"

namespace leetcode_53 {
	using namespace std;
	class Solution;
	class Solution2;
}

class leetcode_53::Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return solve(nums, 0, nums.size() - 1);
	}
private:
	int solve(vector<int>& nums, int left, int right) {
		if (left > right) {
			return INT_MIN;
		}
		int mid = left + (right - left) / 2;
		int m_left = 0, m_right = 0;
		for (int i = mid - 1, sum = 0; i >= left; i--) {
			sum += nums[i];
			m_left = max(sum, m_left);
		}
		for (int i = mid + 1, sum = 0; i <= right; i++) {
			sum += nums[i];
			m_right = max(sum, m_right);
		}
		int l_max = solve(nums, left, mid - 1);
		int r_max = solve(nums, mid + 1, right);
		return max(max(l_max, r_max), m_left + m_right + nums[mid]);
	}
};

class leetcode_53::Solution2 {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0, max_sum = INT_MIN;
		for (int num : nums) {
			sum += num;
			max_sum = max(max_sum, sum);
			if (sum < 0) {
				sum = 0;
			}
		}
		return max_sum;
	}
};


int test_53() {
	using namespace leetcode_53;
	struct Test {
		vector<int> nums;
		int expected;
	};
	vector<Test> tests = {
		{{-2,1,-3,4,-1,2,1,-5,4},6},
		{{5,4,-1,7,8},23},
		{{1},1},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		auto result = solution.maxSubArray(test.nums);
		cout << " -> " << result << "\r\n";

		if (result != test.expected) return 1;
	}
	return 0;
}
