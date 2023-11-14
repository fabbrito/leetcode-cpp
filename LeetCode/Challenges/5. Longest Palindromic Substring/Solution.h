#ifndef LONGEST_PALINDROMIC_SUBSTRING_H_INCLUDED
#define LONGEST_PALINDROMIC_SUBSTRING_H_INCLUDED


namespace leetcode_5 {
	class Solution {
	public:
		std::string longestPalindrome(std::string s);
		std::string longestPalindromeMemo(std::string s);
		std::string longestPalindromeDP(std::string s);
		std::string longestPalindromeOptimized(std::string s);
	};
}

int test_5();

#endif