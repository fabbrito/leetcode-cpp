#ifndef MEDIAN_SORTED_ARRAYS_H_INCLUDED
#define MEDIAN_SORTED_ARRAYS_H_INCLUDED



namespace leetcode_4 {
	class Solution {
	public:
		double findMedianSortedArraysSimple(std::vector<int>& nums1, std::vector<int>& nums2);
		double findMedianSortedArraysPointers(std::vector<int>& nums1, std::vector<int>& nums2);
	};
}

int test_4();

#endif