#include "pch.h"
#include "Solution42.h"

namespace leetcode_42 {
	using namespace std;
	class Solution;
}

class leetcode_42::Solution {
public:
	int trap(vector<int>& heights) {
		size_t n = heights.size();
		if (n <= 2) return 0;

		size_t left = 0, right = n - 1;
		int leftMax = heights[left], rightMax = heights[right];
		int water = 0;

		while (left < right) {
			if (leftMax < rightMax) {
				water += leftMax - heights[left];
				leftMax = max(leftMax, heights[++left]);
			}
			else {
				water += rightMax - heights[right];
				rightMax = max(rightMax, heights[--right]);
			}
		}
		return water;
	}
};


//class leetcode_42::MySolution {
//public:
//	int trap(vector<int>& heights) const noexcept {
//		int ans = 0;
//		int start = 0, end = heights.size() - 1;
//		solve(heights, ans, start, end);
//		return ans;
//	}
//private:
//	static constexpr pair<int, int> partition(vector<int>& heights, int start, int end) noexcept {
//		int max_a = 0, max_b = 0;
//		int max_i = start, max_j = end;
//		int i = start, j = end;
//		while (i < j) {
//			if (heights[i] > max_a) {
//				max_i = i;
//				max_a = heights[i];
//			}
//			if (heights[j] > max_b) {
//				max_j = j;
//				max_b = heights[j];
//			}
//			if (heights[i] < heights[j])
//				i++;
//			else
//				j--;
//		}
//		return { max_i, max_j };
//	}
//	static void solve(vector<int>& heights, int& ans, int start, int end) noexcept {
//		if (start == end) return;
//		if (start < 0 || start >= heights.size()) return;
//		if (end < 0 || end >= heights.size()) return;
//
//		auto [left, right] = partition(heights, start, end);
//		int side = min(heights[left], heights[right]);
//		for (int i = left + 1; i < right; i++) {
//			ans += side - heights[i];
//		}
//		solve(heights, ans, start, left);
//		solve(heights, ans, right, end);
//	}
//};


int test_42()
{
	using namespace leetcode_42;
	Solution solution;
	int result;
	struct Test {
		vector<int> height;
		int expected;
	};
	vector<Test> tests = {
		{{0,1,2,3,4,5,6,7,8,9,10},0},
		{{0,0,0,0,0,0,0,0,0,0,0},0},
		{{0,1,0,2,1,0,1,3,2,1,2,1},6},
		{{4,2,0,3,2,5},9},
		{{1},0},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		utils::printVector(test.height, ", ", false);
		result = solution.trap(test.height);
		cout << " -> " << result << endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
