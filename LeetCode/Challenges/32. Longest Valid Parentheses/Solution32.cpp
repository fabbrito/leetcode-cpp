#include "pch.h"
#include "Solution32.h"

// Check
//Next Greater Element
//Next Smaller Element
//Previous Greater Element
//Previous Smaller Element
//Largest Rectangle in Histogram


namespace leetcode_32 {
	class Solution {
	public:
		bool isValid(std::string& s, int pStart, int pStop);
		int longestValidParenthesesSlow(std::string s);

		int longestValidParentheses(std::string s);
	};
}


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

int leetcode_32::Solution::longestValidParentheses(std::string s) {
	std::stack<int> st;
	st.push(-1);
	int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else {
			if (st.size() == 1) {
				st.pop();
				st.push(i);
			}
			else {
				st.pop();
				ans = std::max(ans, i - st.top());
			}
		}

	}
	return ans;
}

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
	Solution solution;
	int result;
	struct Test {
		std::string s;
		int expected;
	};
	std::vector<Test> tests = {
		{"", 0},
		{"(()", 2},
		{")))))()(((((", 2},
		{"(((((()", 2},
		{")))()()(((", 4},
		{")()())", 4},
		{"()(()()(", 4},
		{"(())()(()((", 6},
		{"((()))", 6},
		{"((())())", 8},
		{"((())())((())())((())())((())())((())())((())())", 48},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << test.s << " -> ";
		result = solution.longestValidParentheses(test.s);
		std::cout << result << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}