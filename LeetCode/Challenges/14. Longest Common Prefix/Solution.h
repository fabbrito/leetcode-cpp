#ifndef LONGEST_COMMON_PREFIX_H_INCLUDED
#define LONGEST_COMMON_PREFIX_H_INCLUDED

namespace leetcode_14 {
	class Solution {
	public:
		std::string longestCommonPrefixSorted(std::vector<std::string>& strs);
		std::string longestCommonPrefix(std::vector<std::string>& strs);
	};
}

int test_14();

#endif