#include "pch.h"
#include "Solution496.h"

namespace leetcode_496 {
	class Solution {
	public:
		std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2);
	};
}

/*
* Time Complexity: O(n + m), where n is the size of nums2 and m the size of nums1
* Space Complexity: O(n + m), where n is the size of nums2 and m the size of nums1
*/

std::vector<int> leetcode_496::Solution::nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::unordered_map<int, int> umap; // map the greater next element for each number in nums2
	std::stack<int> st;
	for (auto& n : nums2) {
		// Pop elements from stack and update umap with next greater element
		while (!st.empty() && st.top() < n) {
			umap[st.top()] = n;
			st.pop();
		}
		st.push(n);
	}
	// Remaining elements in the stack don't have a next greater element, map them to -1
	while (!st.empty()) {
		umap[st.top()] = -1;
		st.pop();
	}
	std::vector<int> ans(nums1.size(), -1);
	for (int i = 0; i < nums1.size(); i++) {
		ans[i] = umap[nums1[i]];
	}
	return ans;
}

int test_496() {
	using namespace leetcode_496;
	Solution solution;
	std::vector<int> result;
	struct Test {
		std::vector<int> nums1;
		std::vector<int> nums2;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{3,1}, {6,3,2,1,5,4}, {5,5}},
		{{4,1,2}, {1,3,4,2}, {-1,3,-1}},
		{{2,4}, {1,2,3,4}, {3,-1}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.nums1, ", ", false);
		std::cout << ", ";
		utils::printVector(test.nums2, ", ", false);
		result = solution.nextGreaterElement(test.nums1, test.nums2);
		std::cout << " -> ";
		utils::printVector(result);

		if (result != test.expected) return 1;
	}
	return 0;
}