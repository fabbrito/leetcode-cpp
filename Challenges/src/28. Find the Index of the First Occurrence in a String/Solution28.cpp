#include "pch.h"
#include "./Solution28.h"

namespace leetcode_28 {
	class Solution {
	public:
		int strStr(std::string haystack, std::string needle);
	};
}

int leetcode_28::Solution::strStr(std::string haystack, std::string needle) {
	int h = haystack.size();
	int n = needle.size();
	int i = 0, j = 0;
	int ans = -1;
	while (i < h) {
		while (i + j < h && j < n && haystack[i + j] == needle[j])
			j++;
		if (j == n) {
			ans = i;
			break;
		}
		else {
			j = 0;
			i++;
		}
	}
	return ans;
}

int test_28() {
	using namespace leetcode_28;
	Solution solution;
	int result;
	struct Test {
		std::string h;
		std::string n;
		int expected;
	};
	std::vector<Test> tests = {
		{"a", "a", 0},
		{"a", "b", -1},
		{"sadbutsad", "sad", 0},
		{"sadbutsad", "but", 3},
		{"leetcode", "leeto", -1},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		result = solution.strStr(test.h, test.n);
		std::cout << "h: " << test.h << " | n: " << test.n;
		std::cout << " | res: " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}