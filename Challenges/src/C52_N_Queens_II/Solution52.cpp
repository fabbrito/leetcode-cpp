#include "pch.h"
#include "Solution52.h"

namespace leetcode_52 {
	using namespace std;
	class Solution;
}

class leetcode_52::Solution {
public:
	int totalNQueens(int n) {
		vector<bool> col_contains(n), anti_diag_contains(2 * n - 1), main_diag_contains(2 * n - 1);
		return solve(col_contains, anti_diag_contains, main_diag_contains, 0);
	}
private:
	static int solve(vector<bool>& col_contains, vector<bool>& anti_diag_contains, vector<bool>& main_diag_contains, int r) {
		int n = size(col_contains), count = 0;
		if (r == n) {
			return 1;
		}
		for (int c = 0; c < n; c++) {
			if (!col_contains[c] && !anti_diag_contains[r + c] && !main_diag_contains[r - c + n - 1]) {
				col_contains[c] = anti_diag_contains[r + c] = main_diag_contains[r - c + n - 1] = true;
				count += solve(col_contains, anti_diag_contains, main_diag_contains, r + 1);
				col_contains[c] = anti_diag_contains[r + c] = main_diag_contains[r - c + n - 1] = false;
			}
		}
		return count;
	}
};


int test_52() {
	using namespace leetcode_52;
	struct Test {
		int n;
		int expected;
	};
	vector<Test> tests = {
		{9,352},
		{5,10},
		{4,2},
		{1,1},
		{2,0},
		{3,0},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		auto result = solution.totalNQueens(test.n);
		cout << test.n << " -> " << result << "\r\n";

		if (result != test.expected) return 1;
	}
	return 0;
}
