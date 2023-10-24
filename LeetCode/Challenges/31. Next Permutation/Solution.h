#ifndef NEXT_PERMUTATION_H_INLCUDED
#define NEXT_PERMUTATION_H_INLCUDED

//31. Next Permutation
namespace leetcode_31 {
    class Solution {
    public:
        void reverse(std::vector<int>& nums, int pStart, int pEnd);
        void nextPermutation(std::vector<int>& nums);
    };
}

int test_31();

#endif