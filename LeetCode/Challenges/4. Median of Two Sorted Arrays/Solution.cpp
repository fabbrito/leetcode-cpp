#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Solution.h"
#include "printVector.h"

namespace leetcode_4 {
	double Solution::findMedianSortedArraysSimple(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::vector<int> merged;
		for (int& elem : nums1) {
			merged.push_back(elem);
		}
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

	double Solution::findMedianSortedArraysPointers(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		int size1 = nums1.size(), size2 = nums2.size();
		int i = 0, j = 0, current = 0, previous = 0;
		for (int count = 0; count <= (size1 + size2) / 2; count++) {
			previous = current;
			if (i != size1 && j != size2) {
				if (nums1[i] > nums2[j]) {
					current = nums2[j++];
				}
				else {
					current = nums1[i++];
				}
			}
			else if (i < size1) {
				current = nums1[i++];
			}
			else {
				current = nums2[j++];
			}
		}

		if ((size1 + size2) % 2 == 0) {
			return (static_cast<double>(current) + static_cast<double>(previous)) / 2.0;
		}
		else {
			return static_cast<double>(current);
		}
	}
}

int test_4()
{
	using namespace leetcode_4;
	Solution* solution = new Solution;
	struct Test {
		std::vector<int> nums1;
		std::vector<int> nums2;
	};
	std::vector<Test> tests = {
		{ { 1, 3 }, { 2 } }, // 2.0 
		{ { 1, 2 }, { 3, 4 } }, // 2.5
		{ {  }, { 3, 4 } } // 3.5
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		double result = solution->findMedianSortedArraysPointers(test.nums1, test.nums2);
		utils::printVector(test.nums1, ", ", false);
		std::cout << ", ";
		utils::printVector(test.nums2, ", ", false);
		std::cout << " -> ";
		std::cout << result << std::endl;
	}
	return 0;
}
