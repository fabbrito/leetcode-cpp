#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "Solution.h"

namespace leetcode_3 {
	bool check_if_unique(const std::string& s) {
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j++) {
				if (s[i] == s[j])
					return false;
			}
		}
		return true;
	}

	int Solution::lengthOfLongestSubstringSimple(std::string s)
	{
		std::string sub_s;
		int i_start = 0;
		int i_end = 0;
		int max_length = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = i; j < s.length(); j++) {
				sub_s = s.substr(i, j - i + 1);
				if (check_if_unique(sub_s) && sub_s.length() > max_length) {
					max_length = sub_s.length();
				}
			}
		}
		return max_length;
	}


	int Solution::lengthOfLongestSubstringUnorderedSet(std::string s)
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

	int Solution::lengthOfLongestSubstringUnorderedMap(std::string s) {
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

	int Solution::lengthOfLongestSubstringIntArray(std::string s) {
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
		int result0 = solution->lengthOfLongestSubstringUnorderedSet(test.s);
		int result1 = solution->lengthOfLongestSubstringUnorderedMap(test.s);
		int result2 = solution->lengthOfLongestSubstringIntArray(test.s);
		std::cout << test.s << " -> " << result0 << ", " << result1 << ", " << result2 << std::endl;
	}
	return 0;
}