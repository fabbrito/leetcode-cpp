#ifndef FIND_POSITIONS_OF_ELEMTENT_IN_SORTED_ARRAY_H_INLCUDED
#define FIND_POSITIONS_OF_ELEMTENT_IN_SORTED_ARRAY_H_INLCUDED

//34. Find First and Last Position of Element in Sorted Array
namespace leetcode_34 {
    class Solution {
    public:
        std::vector<int> searchRange(std::vector<int>& nums, int target);

        int lower_bound(std::vector<int>& nums, int target);
        std::vector<int> searchRange2(std::vector<int>& nums, int target);
    };
}

int test_34();

#endif
