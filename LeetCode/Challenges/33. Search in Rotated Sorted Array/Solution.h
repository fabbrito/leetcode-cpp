#ifndef SEARCH_IN_ROTATED_SORTED_ARRAY_H_INLCUDED
#define SEARCH_IN_ROTATED_SORTED_ARRAY_H_INLCUDED

//33. Search in Rotated Sorted Array
namespace leetcode_33 {
    class Solution {
    public:
        int search(std::vector<int>& nums, int target);
        int mySearch(std::vector<int>& nums, int target);
    };
}

int test_33();

#endif