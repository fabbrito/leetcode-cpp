#include "pch.h"
#include "./Solution10.h"

namespace leetcode_10 {
	using namespace std;
	class Solution;
}
class leetcode_10::Solution {
public:
	// ---------------------- Non recursive approaches ---------------------
	bool isMatchBottomUp(string s, string p) {
		int sn = s.length(), pn = p.length();
		vector<vector<bool>> memo(sn + 1, vector<bool>(pn + 1, false));
		memo[sn][pn] = true;
		for (int i = sn; i >= 0; i--) {
			for (int j = pn - 1; j >= 0; j--) {
				// Check for matching chars between p and s or if there is a '.' in the pattern string
				bool curr_match = (i < sn && (p[j] == s[i] || p[j] == '.'));
				if (j + 1 < pn && p[j + 1] == '*') { // found '*' in the pattern string
					memo[i][j] = memo[i][j + 2] || // assuming zero match -> propagate the previous answer
						(curr_match && memo[i + 1][j]); // assuming a +1 match -> propagate the previous answer
				}
				else { // no '*' found -> propagate the previous answer
					memo[i][j] = curr_match && memo[i + 1][j + 1];
				}
			}
		}
		// Answer is only 'true' if there is a path from (sn, pn) to (0, 0)
		return memo[0][0];
	}
	bool isMatchTopDown(string s, string p) {
		int sn = s.length(), pn = p.length();
		std::vector<std::vector<bool>> memo(sn + 1, std::vector<bool>(pn + 1, false));
		memo[0][0] = true;

		for (int i = 0; i <= sn; i++) {
			for (int j = 1; j <= pn; j++) {
				if (p[j - 1] == '*') {
					memo[i][j] = memo[i][j - 2] ||
						(i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && memo[i - 1][j]);
				}
				else {
					memo[i][j] = i > 0 && memo[i - 1][j - 1] &&
						(s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
			}
		}
		// Answer is only 'true' if there is a path from (0, 0) to (sn, pn)
		return memo[sn][pn];
	}
public:
	// ---------------------- Recursive approach ---------------------
	bool isMatch(string s, string p) {
		vector<vector<int>> memo(s.length() + 1, vector<int>(p.length(), -1));
		return solve(s, p, 0, 0, memo);
	}
private:
	static bool solve(string& s, string& p, int i, int j, vector<vector<int>>& memo) {
		// Base case: both indexes reach the end of their respective strings
		if (j == p.length())
			return i == s.length();
		// Check for a memoized subproblem
		if (memo[i][j] != -1)
			return memo[i][j] > 0;
		// Check for matching chars or if there is a '.' in the pattern string
		bool curr_match = i < s.length() && (s[i] == p[j] || p[j] == '.');
		bool ans = 0;
		if (j + 1 < p.length() && p[j + 1] == '*') { // if next char is '*' in the pattern string
			ans = (solve(s, p, i, j + 2, memo) || // recursively solve as if there were zero matches
				(curr_match && solve(s, p, i + 1, j, memo))); // or solve for a repeating pattern
		}
		else { // no '*', advance both indexes
			ans = (curr_match && solve(s, p, i + 1, j + 1, memo));
		}
		// update memo
		memo[i][j] = ans;
		return ans;
	}
};

int test_10() {
	using namespace leetcode_10;
	struct Test {
		string s;
		string p;
		bool expected;
	};
	vector<Test> tests = {
		{"cdab", "ab*", false},
		{"aaaa", "b*a", false},
		{"aaaa", "b*a*", true},
		{"aaaa", "a*", true},
		{"abcd", ".*", true},
	};

	cout << "Testing Solution" << "\r\n";
	for (auto& test : tests) {
		Solution solution;
		bool result0 = solution.isMatch(test.s, test.p);
		bool result1 = solution.isMatchBottomUp(test.s, test.p);
		bool result2 = solution.isMatchTopDown(test.s, test.p);
		cout << test.s << ", " << test.p << " -> (" << result0 << ", " << result1 << ", " << result2 << ")\r\n";
		if ((result0 && result1 && result2) != test.expected) return 1;
	}
	cout << "Caption: string, pattern -> Answers (recursive top down, iterative bottom up, iterative top down)" << "\r\n";
	return 0;
}