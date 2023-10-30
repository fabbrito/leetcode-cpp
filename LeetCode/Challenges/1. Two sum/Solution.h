#ifndef TWO_SUM_H_INCLUDED
#define TWO_SUM_H_INCLUDED

// 1. Two Sum
namespace leetcode_1 {
	class Solution {
	public:
		template <typename T>
		std::vector<int> sortIndexes(std::vector<T>& v);
		std::vector<int> twoSumSimple(std::vector<int>& nums, int target);
		std::vector<int> twoSumMap(std::vector<int>& nums, int target);
		std::vector<int> twoSum(std::vector<int>& nums, int target);
	};
}


int test_1();

#endif