#include "pch.h"
#include "Solution20.h"

namespace leetcode_20 {
	class Solution {
	public:
		char closingBracket(char c);
		bool isValid(std::string s);
	};
}

namespace leetcode_20 {

	char Solution::closingBracket(char c) {
		char r = 0;
		switch (c) {
		case '(':
			r = ')';
			break;
		case '[':
			r = ']';
			break;
		case '{':
			r = '}';
			break;
		default:
			break;
		}
		return r;
	}

	bool Solution::isValid(std::string s) {
		std::stack<char> st;
		for (char& c : s) {
			if (c == '(' || c == '{' || c == '[') { // if the character is an opening bracket
				st.push(c); // push it onto the stack
			}
			else {
				// if the stack is empty or the closing bracket doesn't match the corresponding 
				// opening bracket at the top of the stack the string is not valid, so return false
				if (st.empty() || 
					(c == ')' && st.top() != '(') ||
					(c == '}' && st.top() != '{') ||
					(c == ']' && st.top() != '[')) {
					return false; 
				}
				st.pop(); // otherwise, pop the opening bracket from the stack
			}
		}
		// if all opening brackets have been matched, then the stack will be empty, so the string is
		// valid and return true; otherwise, there are unmatched opening brackets, so return false
		return st.empty();
	}
}

int test_20() {
	using namespace leetcode_20;
	Solution solution;
	bool result;
	struct Test {
		std::string s;
		bool expected;
	};
	std::vector<Test> tests = {
		{"()]", false},
		{"(([][]{{()}}))", true},
		{"(([][]{{(})}))", false},
		{"()", true},
		{"((", false},
		{"(())", true},
		{"()[]{}", true},
		{"(]", false},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.isValid(test.s);

		std::cout << test.s << " -> " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}