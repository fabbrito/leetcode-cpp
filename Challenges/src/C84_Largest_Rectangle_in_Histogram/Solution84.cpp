#include "pch.h"
#include "Solution84.h"

namespace leetcode_84 {

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> idxStack;
		int maxArea = 0;
		// added to help clear the stack when i == heights.size() - 1, in the original vector
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++) {
			while (!idxStack.empty() && heights[idxStack.top()] > heights[i]) {
				int h = heights[idxStack.top()];
				idxStack.pop();
				int sIdx = idxStack.empty() ? -1 : idxStack.top();
				if (h * (i - sIdx - 1) > maxArea)
					maxArea = h * (i - sIdx - 1);
			}
			idxStack.push(i);
		}
		return maxArea;
	}

	int largestRectangleAreaVector(vector<int>& height) {
		int maxArea = 0;
		height.push_back(0);
		vector<int> index;

		for (int i = 0; i < height.size(); i++) {
			while (index.size() > 0 && height[index.back()] >= height[i]) {
				int h = height[index.back()];
				index.pop_back();

				int sIdx = index.size() > 0 ? index.back() : -1;
				if (h * (i - sIdx - 1) > maxArea)
					maxArea = h * (i - sIdx - 1);
			}
			index.push_back(i);
		}
		return maxArea;
	}
};
}

int test_84() {
	using namespace leetcode_84;
	struct test_t {
		vector<int> heights;
		int expected;
	};
	vector<test_t> tests = {
		// \[(([0-9]*,*)+)\] -> {$1} regex to change from [1,2,3] to {1,2,3}
		// \[((("[A-Za-z]")*,*)+)\] -> {$1} regex to change from ["A","B","C"] to {"A","B","C"}
		{{2,1,5,6,2,3},10},
		{{2,2,2,2,2},10},
		{{2,4},4},
		{{1},1}
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.heights);
		auto result = solution.largestRectangleArea(test.heights);
		auto result1 = solution.largestRectangleAreaVector(test.heights);
		std::cout << " -> " << result << " | " << result1 << "\r\n";
		if (result != test.expected) return 1;
		if (result1 != test.expected) return 1;
	}
	return 0;
}