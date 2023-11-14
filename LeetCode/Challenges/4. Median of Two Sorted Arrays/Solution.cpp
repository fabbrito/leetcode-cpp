#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "./Solution.h"
#include "printVector.h"


double leetcode_4::Solution::findMedianSortedArraysSimple(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::vector<int> merged = nums1;
	for (int& elem : nums2) {
		merged.push_back(elem);
	}
	std::sort(merged.begin(), merged.end());

	int total = merged.size();
	if (total % 2 == 0) {
		double m1 = static_cast<double>(merged[total / 2 - 1]);
		double m2 = static_cast<double>(merged[total / 2]);
		return (m1 + m2) / 2.0;
	}
	else {
		return static_cast<double>(merged[total / 2]);
	}
}

double leetcode_4::Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	int n = nums1.size(), m = nums2.size();
	int i = 0, j = 0;
	int curr = 0, prev = 0;
	while (i + j <= (n + m) / 2) {
		prev = curr;
		if (i < n && j < m) {
			if (nums1[i] > nums2[j])
				curr = nums2[j++];
			else
				curr = nums1[i++];
		}
		else if (i < n)
			curr = nums1[i++];
		else
			curr = nums2[j++];
	}

	if ((n + m) % 2 == 0) {
		return static_cast<double>(curr + prev) / 2.0;
	}
	else {
		return static_cast<double>(curr);
	}
}

int test_4()
{
	using namespace leetcode_4;
	Solution* solution = new Solution;
	struct Test {
		std::vector<int> nums1;
		std::vector<int> nums2;
		double expected;
	};
	std::vector<Test> tests = {
		{ { 1,3 }, { 2 }, 2.0},
		{ { 1,2 }, { 3,4 }, 2.5},
		{ {  }, { 3,4 }, 3.5},
		{ {  }, { 1 }, 1},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.nums1, ", ", false);
		std::cout << ", ";
		utils::printVector(test.nums2, ", ", false);
		std::cout << " -> ";
		double result = solution->findMedianSortedArrays(test.nums1, test.nums2);
		std::cout << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
