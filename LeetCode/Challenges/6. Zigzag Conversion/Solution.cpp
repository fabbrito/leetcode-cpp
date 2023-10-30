#include <iostream>
#include <vector>
#include <string>
#include "./Solution.h"
#include "printVector.h"


std::string leetcode_6::Solution::convert(std::string s, int numRows) {
	if (numRows <= 1) return s;
	std::string res;
	int i;
	for (int step = 0; step < numRows; step++) {
		i = step;
		while (i < s.length()) {
			res.push_back(s[i]);
			i += numRows * 2 - 2;
			if (step != 0 && step != numRows - 1) {
				int i0 = i - step * 2;
				if (i0 < s.length())
					res.push_back(s[i0]);
			}
		}
	}
	return res;
}

std::string leetcode_6::Solution::myConvert(std::string s, int numRows)
{
	if (numRows <= 1 || numRows >= s.length()) return s;
	std::string r = std::string();
	std::vector<std::string> vec(numRows, std::string());
	int pos = 0, index = 0;
	int groupLength = 2 * (numRows - 1);
	int quantGroups = s.length() / groupLength + 1;

	for (int i = 0; i < quantGroups; i++) {
		for (int j = 0; j < groupLength; j++) {
			pos = i * 2 * (numRows - 1) + j;
			if (pos >= s.length()) break;

			// index = j * (1 - j / numRows) + (groupLength - j) * (j / numRows);
			if (j < numRows)
				index = j;
			else
				index = groupLength - j;
			vec[index] += s[pos];
		}
	}
	for (auto& v : vec) r += v;
	return r;
}


int test_6() {
	using namespace leetcode_6;
	Solution* solution = new Solution;
	std::string result;
	struct Test {
		std::string s;
		int numRows;
		std::string expected;
	};
	std::vector<Test> tests = { { "PAYPALISHIRING", 3, "PAHNAPLSIIGYIR" }, { "PAYPALISHIRING", 4, "PINALSIGYAHRPI"}, { "A", 1, "A"} };

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution->convert(test.s, test.numRows);
		std::cout << test.s << ", " << test.numRows << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}