#include "pch.h"
#include "./Solution3.h"

namespace leetcode_3 {
	class Solution {
	public:
		int lengthOfLongestSubstring(std::string s);
		int lengthOfLongestSubstringUnorderedMap(std::string s);
		int lengthOfLongestSubstringIntArray(std::string s);
	};
}

int leetcode_3::Solution::lengthOfLongestSubstring(std::string s)
{
	std::unordered_set<char> charSet;
	int maxLength = 0;
	int left = 0;
	for (int right = 0; right < s.length(); right++) {
		if (charSet.count(s[right]) == 0) {
			charSet.insert(s[right]);
			maxLength = std::max(maxLength, right - left + 1);
		}
		else {
			while (charSet.count(s[right]) > 0) {
				charSet.erase(s[left]);
				left++;
			}
			charSet.insert(s[right]);
		}

	}
	return maxLength;
}

int leetcode_3::Solution::lengthOfLongestSubstringUnorderedMap(std::string s) {
	int n = s.length();
	int maxLength = 0;
	std::unordered_map<char, int> charMap;
	int left = 0;

	for (int right = 0; right < n; right++) {
		if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
			charMap[s[right]] = right;
			maxLength = std::max(maxLength, right - left + 1);
		}
		else {
			left = charMap[s[right]] + 1;
			charMap[s[right]] = right;
		}
	}

	return maxLength;
}

int leetcode_3::Solution::lengthOfLongestSubstringIntArray(std::string s) {
	int n = s.length();
	int maxLength = 0;
	std::vector<int> charIndex(128, -1);
	int left = 0;

	for (int right = 0; right < n; right++) {
		if (charIndex[s[right]] >= left) {
			left = charIndex[s[right]] + 1;
		}
		charIndex[s[right]] = right;
		maxLength = std::max(maxLength, right - left + 1);
	}

	return maxLength;
}

int test_3() {
	using namespace leetcode_3;
	Solution* solution = new Solution;
	struct Test {
		std::string s;
		int expected;
	};
	std::vector<Test> tests = {
		{"abcabcbb", 3},
		{"bbbbb", 1},
		{"pwwkew",3},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		int result = solution->lengthOfLongestSubstring(test.s);
		int result1 = solution->lengthOfLongestSubstringUnorderedMap(test.s);
		int result2 = solution->lengthOfLongestSubstringIntArray(test.s);
		std::cout << test.s << " -> " << result << ", " << result1 << ", " << result2 << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}