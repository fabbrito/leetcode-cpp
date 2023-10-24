#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include "Solution.h"
#include "utils.h"

bool leetcode_32::Solution::isValid(std::string& s, int pStart, int pStop) {
	std::stack<char> st;
	for (int i = pStart; i <= pStop; i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (st.empty() || (s[i] == ')' && st.top() != '(')) {
				return false;
			}
			st.pop();
		}
	}
	return st.empty();
}

//int leetcode_32::Solution::partition(std::string& s, int pStart, int pEnd) {
//	int p = pEnd - 1;
//	while (p > pStart && (s[p] != '(' || s[p + 1] != ')'))
//		p--;
//	return p;
//}
//
//int leetcode_32::Solution::longestValidParenthesesRecursive(std::string& s, int p) {
//	int n = s.length();
//	int i = p, j = p;
//	int choice = -1; // possible values: -1, 0, 1
//	while (i >= 0 && j < n && i < j) {
//
//		bool flag = isValid(s, i, j);
//	}
//	return 0;
//}
//
//int leetcode_32::Solution::longestValidParentheses(std::string s) {
//	int n = s.length();
//	int start = 0, end = 7;
//
//	int p = partition(s, start, end);
//	int pL = partition(s, start, p);
//	bool flag = false;
//	int dist = p - pL - 2;
//	if (pL - dist >= 0)
//		flag = isValid(s, pL - dist, p + 1);
//	std::cout << pL << " " << p << " " << flag << "\r\n";
//
//	return 0;
//}

int leetcode_32::Solution::longestValidParenthesesSlow(std::string s) {
	int n = s.length();
	if (n == 0) return 0;
	int max_len = 0;
	int pStart = 0, pEnd = n - 1;

	// trim impossible to match brackets
	while (pEnd > pStart && s[pStart] == ')') // trim ) at the beginning of the string
		pStart++;
	while (pEnd > pStart && s[pEnd] == '(') // trim ( at the end of the string
		pEnd--;

	for (int i = pStart; i < pEnd; i++) {
		int j = pEnd;
		bool flag = isValid(s, i, j);
		while (i < j && !flag) {
			j--;
			flag = isValid(s, i, j);
			if (j - i + 1 < max_len)
				break;
		}
		int curr_len = j - i + 1;
		if (i != j && flag && curr_len > max_len)
			max_len = curr_len;
	}
	return max_len;
}


int test_32() {
	using namespace leetcode_32;
	Solution* solution = new Solution;
	int result;
	struct Test {
		std::string s;
		int expected;
	};
	std::vector<Test> tests = {
		{"(())()(()((", 6},
		{")))()()(((", 4},
		{"((()))", 6},
		{")()())", 4},
		{"()(()()(", 4},
		{"(()", 2},
		{"((())())", 8},
		{")))))()(((((", 2},
		{"(((((()", 2},
		{"", 0},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << test.s << " -> ";
		result = solution->longestValidParenthesesSlow(test.s);
		std::cout << result << "\r\n";

		if (result != test.expected) return 1;
	}
	return 0;
}