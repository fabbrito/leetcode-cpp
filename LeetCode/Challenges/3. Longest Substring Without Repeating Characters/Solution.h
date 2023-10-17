#ifndef LONGEST_SUBSTRING_H_INCLUDED
#define LONGEST_SUBSTRING_H_INCLUDED


namespace leetcode_3 {
	class Solution {
	public:
		int lengthOfLongestSubstringSimple(std::string s);
		int lengthOfLongestSubstringUnorderedSet(std::string s);
		int lengthOfLongestSubstringUnorderedMap(std::string s);
		int lengthOfLongestSubstringIntArray(std::string s);
	};
}

int test_3();
#endif