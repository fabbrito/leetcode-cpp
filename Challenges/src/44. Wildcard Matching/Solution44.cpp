#include "pch.h"
#include "./Solution44.h"

namespace leetcode_44 {
	using namespace std;
	class Solution;
}

class leetcode_44::Solution {
public:
	// ---------------------- Non recursive approaches ---------------------
	bool isMatchBottomUp(string s, string p) {
		int n = s.length(), m = p.length();
		vector<vector<bool>> memo(n + 1, vector<bool>(m + 1, false));
		memo[n][m] = true;
		for (int i = n; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				// Check for matching chars or if there is a wildcard char in the pattern string
				bool curr_match = (i < n && j < m && (s[i] == p[j] || p[j] == '?' || p[j] == '*'));
				if (j < m && p[j] == '*') {            // found '*' in the pattern string
					memo[i][j] = memo[i][j + 1] ||      // assuming zero wildcards -> propagate the previous answer
						(curr_match && memo[i + 1][j]); // assuming a +1 wildcards -> propagate the previous answer
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
		int n = s.length(), m = p.length();
		vector<vector<bool>> memo(m + 1, vector<bool>(n + 1, false));
		memo[0][0] = true;
		for (int i = 1; i <= m; i++) {
			if (p[i - 1] == '*') {
				memo[i][0] = memo[i - 1][0];
			}
			for (int j = 1; j <= n; j++) {
				if (p[i - 1] == '*') {
					memo[i][j] = memo[i - 1][j] || memo[i][j - 1];
				}
				else if (p[i - 1] == s[j - 1] || '?' == p[i - 1]) {
					memo[i][j] = memo[i - 1][j - 1];
				}
			}
		}
		return memo[m][n];
	}

	bool isMatchTopDownFast(string s, string p) {
		int n = s.length();
		int m = p.length();

		// allocate the array
		bool** res = new bool* [m + 1];
		for (int i = 0; i <= m; i++)
			res[i] = new bool[n + 1] {false};

		res[0][0] = true;
		for (int i = 1; i <= m; i++) {
			if (p[i - 1] == '*') {
				res[i][0] = res[i - 1][0];
			}
			for (int j = 1; j <= n; j++) {
				if (p[i - 1] == '*') {
					res[i][j] = res[i - 1][j] || res[i][j - 1];
				}
				else if (p[i - 1] == s[j - 1] || '?' == p[i - 1]) {
					res[i][j] = res[i - 1][j - 1];
				}
			}
		}
		bool ans = res[m][n];

		// deallocate the array
		for (int i = 0; i <= m; i++)
			delete[] res[i];
		delete[] res;

		return ans;
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
		if (j >= p.length())
			return i >= s.length();
		// Check for a memoized subproblem
		if (memo[i][j] != -1)
			return memo[i][j] > 0;
		bool ans = 0;
		if (p[j] == '*') {                     // if '*' in the pattern string, then
			ans = solve(s, p, i, j + 1, memo) ||                 // solve as if there were zero wildcards
				(i < s.length() && solve(s, p, i + 1, j, memo)); // solve for a multiple wildcards

		}
		else { // no '*', advance both indexes
			// Check for matching chars or if there is a wildcard char in the pattern string
			bool match = i < s.length() && (s[i] == p[j] || p[j] == '?');
			ans = (match && solve(s, p, i + 1, j + 1, memo));
		}
		// update memo
		memo[i][j] = ans;
		return ans;
	}
};



int test_44() {
	using namespace leetcode_44;
	struct Test {
		string s;
		string p;
		bool expected;
	};
	vector<Test> tests = {
		{"abababc", "a*c", true},
		{"cccccccdddddabab", "c*ab", true},
		{"aa", "*", true},
		{"aa", "??", true},
		{"aaa", "??", false},
		{"aa", "a", false},
		{"cb", "?a", false},
		{"cdab", "ab*", false},
		{"cdab", "??ab", true},
	};

	cout << "Testing Solution" << "\r\n";
	for (auto& test : tests) {
		Solution solution;
		bool result0 = solution.isMatch(test.s, test.p);
		bool result1 = solution.isMatchBottomUp(test.s, test.p);
		bool result2 = solution.isMatchTopDown(test.s, test.p);
		bool result3 = solution.isMatchTopDownFast(test.s, test.p);
		cout << test.s << ", " << test.p << " -> (" << result0 << ", " << result1 << ", " << result2 << ", " << result3 << ")\r\n";
		if ((result0 && result1 && result2 && result3) != test.expected) return 1;
	}
	cout << "\r\nCaption: \r\n";
	cout << "    string, pattern -> Answers \r\n";
	cout << "    Answers : (recursive top down, iterative bottom up, iterative top down vector, iterative top down heap array) \r\n";
	return 0;
}