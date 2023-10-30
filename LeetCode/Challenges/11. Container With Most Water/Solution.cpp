#include <iostream>
#include <vector>
#include <string>
#include "./Solution.h"
#include "printVector.h"

int leetcode_11::Solution::maxArea(std::vector<int>& height)
{
	int n = height.size();
	int left = 0, right = n - 1;
	int maxArea = 0;

	while (right > left) {
		int area = (right - left) * std::min(height[right], height[left]);
		maxArea = std::max(maxArea, area);
		if (height[right] > height[left]) {
			left++;
		}
		else {
			right--;
		}
	}
	return maxArea;
}

int test_11() {
	using namespace leetcode_11;
	Solution* solution = new Solution;
	int result = 0;
	struct Test {
		std::vector<int> height;
		int expected;
	};
	std::vector<Test> tests = {
		{{1, 3, 2, 5, 25, 24, 5}, 24},
		{{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
		{{1, 1}, 1},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->maxArea(test.height);
		utils::printVector(test.height, ", ", false);
		std::cout << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}