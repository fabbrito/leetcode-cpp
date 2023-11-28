#include "pch.h"
#include "./Solution5.h"

namespace leetcode_5 {
	std::string memoHelper(std::string s, int start, int end, std::vector<std::vector<std::string>>& memo);
	class Solution {
	public:
		std::string longestPalindrome(std::string s);
		std::string longestPalindromeMemo(std::string s);
		std::string longestPalindromeDP(std::string s);
		std::string longestPalindromeOptimized(std::string s);
	};
}


// Brute force - try all substrings
// We take full string and call same function recursively for the inner substring if both characters match
// if doesn't match then we call for substrings by skipping a character from either end and take the longest one.
// Using memoization: save the results so that we don't do duplicate work
std::string leetcode_5::memoHelper(std::string s, int start, int end, std::vector<std::vector<std::string>>& memo) {
	if (start > end) {
		return "";
	}
	if (start == end) return std::string(s, 0, 1);
	if (memo[start][end] != "") return memo[start][end];
	if (s[start] == s[end]) {
		std::string inner = memoHelper(s, start + 1, end - 1, memo);
		if (inner.size() == (end - start - 1)) {
			memo[start][end] = s.substr(start, end - start + 1);
			return memo[start][end];
		}
	}
	std::string skipRight = memoHelper(s, start, end - 1, memo);
	std::string skipLeft = memoHelper(s, start + 1, end, memo);
	if (skipRight.size() > skipLeft.size()) {
		memo[start][end] = skipRight;
	}
	else {
		memo[start][end] = skipLeft;
	}
	return memo[start][end];
}

std::string leetcode_5::Solution::longestPalindromeMemo(std::string s) {
	std::vector<std::vector<std::string>> memo(s.size(), std::vector<std::string>(s.size(), ""));
	return memoHelper(s, 0, s.size() - 1, memo);
}

// DP -> Same approach as above but instead of recursion we do bottom up
// To get all substrings, start from 0th index to the length of the string
// For each character we expand to the left until first character in the inner loop thus covering all substrings
std::string leetcode_5::Solution::longestPalindromeDP(std::string s) {
	int n = s.size();
	std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
	int largestYet = 1;
	std::string ans = std::string(s, 0, 1);
	// s[start] == s[end]
	//      if(end-start==1) || dp[start+1][end-1])
	//          dp[start][end] = true
	for (int end = 0; end < n; ++end) {
		// all single characters are palindrome of size 1
		dp[end][end] = true;
		for (int start = end - 1; start >= 0; --start) {
			if (s[start] == s[end]) {
				if (end - start == 1 || dp[start + 1][end - 1]) {
					dp[start][end] = true;
					if (end - start + 1 > largestYet) {
						largestYet = end - start + 1;
						ans = s.substr(start, end - start + 1);
					}
				}
			}
		}
	}
	return ans;
}



// Expand around center -> O(n^2) time complexity and constant space complexity 
// Start from left and for each character keep on expanding left and right until it is not a palindrome
// Move to the next one and compare with previous max palindrome length
std::string leetcode_5::Solution::longestPalindromeOptimized(std::string s) {
	int n = s.size();
	int start = 0, maxLen = 0;
	for (int i = 0; i < n;) {
		int left = i, right = i;
		// Cover duplicate letters to the right. Since we are starting from left, no need to do it for left
		while (right < n - 1 && s[right] == s[right + 1]) ++right;
		// Advance i. Keep it here since we want to do this exercise at each letter
		i = right + 1;
		// Now try to expand left and right to see if we have palindromic characters at each end
		while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
			++right;
			--left;
		}
		if (right - left + 1 > maxLen) {
			maxLen = right - left + 1;
			start = left;
		}
	}
	return s.substr(start, maxLen);
}

std::string leetcode_5::Solution::longestPalindrome(std::string s) {
	bool palindrome = true;

	for (int window = s.length(); window >= 1; window--) {
		for (int offset = 0; offset <= s.length() - window; offset++) {
			palindrome = true;
			for (int i = 0; i < window / 2; i++) {
				if (s[offset + i] != s[offset + window - i - 1]) {
					palindrome = false;
					break;
				}
			}
			if (palindrome) {
				return s.substr(offset, window);
			}
		}
	}
	return std::string();
}


int test_5() {
	using namespace leetcode_5;
	Solution solution;
	std::string result;
	struct Test {
		std::string s;
		std::vector<std::string> expected;
	};
	std::vector<Test> tests = {
		{"babad", {"bab", "aba"}},
		{"cbbd", {"bb"}},
		{"sa", {"s", "a"}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.longestPalindromeDP(test.s);
		std::cout << test.s << " -> " << result << std::endl;
	}
	return 0;
}


