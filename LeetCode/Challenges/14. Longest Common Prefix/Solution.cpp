#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Solution.h"
#include "printVector.h"

namespace leetcode_14 {
	std::string Solution::longestCommonPrefixSorted(std::vector<std::string>& strs) {
		int n = strs.size();
		std::sort(strs.begin(), strs.end());
		std::string res = "";
		std::string first = strs[0], last = strs[n - 1];
		for (int i = 0; i < std::min(first.length(), last.length()); i++) {
			if (first[i] == last[i]) {
				res += first[i];
			}
			else break;
		}
		return res;
	}

	std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
	{
		if (strs.size() == 1) return strs[0];
		std::string res = "";
		bool stop = false;
		int p = 0;
		while (!stop) {
			for (int i = 0; i < strs.size() - 1; i++) {
				if (p >= strs[i].length() || p >= strs[i + 1].length()) {
					stop = true;
					break;
				}
				if (strs[i][p] != strs[i + 1][p]) {
					stop = true;
					break;
				}
				if (i == strs.size() - 2) {
					res += strs[i + 1][p];
					p++;
				}
			}
		}
		return res;
	}
}

int test_14()
{
	using namespace leetcode_14;
	Solution* solution = new Solution;
	std::string result;
	struct Test {
		std::vector<std::string> strs;
		std::string expected;
	};
	std::vector<Test> tests = {
		{{"flower", "flow", "flight"}, "fl"},
		{{"dog", "racecar", "car"}, ""},
		{{"", "racecar", "car"}, ""},
		{{"car"}, "car"},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printVector(test.strs, ", ", false);
		result = solution->longestCommonPrefixSorted(test.strs);
		std::cout << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
