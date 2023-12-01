#include "pch.h"
#include "Solution51.h"

namespace leetcode_51 {
	using namespace std;
	class Solution;
	class Solution2;
}

class leetcode_51::Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		if (n <= 0) return {};
		vector<vector<string>> boards;
		vector<string> board(n, string(n, '.'));

		solve(0, board, boards);
		return boards;
	}
private:
	static bool is_valid(vector<string>& board, int row, int col) {
		// check col
		for (int i = row; i >= 0; --i) {
			if (board[i][col] == 'Q') {
				return false;
			}
		}
		// check left diagonal
		for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}

		//check right diagonal
		for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}

		return true;
	}
	static void solve(int row, vector<string>& board, vector<vector<string>>& boards) {
		// exit condition
		if (row == board.size()) {
			boards.push_back(board);
			return;
		}
		// iterate every possible position
		for (int col = 0; col < board.size(); ++col) {
			if (is_valid(board, row, col)) {
				// make decision
				board[row][col] = 'Q';
				// next iteration
				solve(row + 1, board, boards);
				// back-tracking
				board[row][col] = '.';
			}
		}
	}
};

class leetcode_51::Solution2 {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<bool> col_contains(n, false), anti_diag_contains(2 * n - 1, false), main_diag_contains(2 * n - 1, false);
		vector<vector<string>> boards;
		vector<string> board(n, string(n, '.'));
		solve(0, col_contains, anti_diag_contains, main_diag_contains, board, boards);
		return boards;
	}
private:
	static void solve(int r, vector<bool>& col_contains, vector<bool>& anti_diag_contains, vector<bool>& main_diag_contains, vector<string>& board, vector<vector<string>>& out_boards) {
		int n = size(col_contains);
		if (r == n) {
			out_boards.emplace_back(board);
			return;
		}
		for (int c = 0; c < n; c++) {
			if (!col_contains[c] && !anti_diag_contains[r + c] && !main_diag_contains[r - c + n - 1]) {
				col_contains[c] = anti_diag_contains[r + c] = main_diag_contains[r - c + n - 1] = true;
				board[r][c] = 'Q';
				solve(r + 1, col_contains, anti_diag_contains, main_diag_contains, board, out_boards);
				board[r][c] = '.';
				col_contains[c] = anti_diag_contains[r + c] = main_diag_contains[r - c + n - 1] = false;
			}
		}
	}
};

int test_51() {
	using namespace leetcode_51;
	struct Test {
		int n;
		vector<vector<string>> expected;
	};
	vector<Test> tests = {
		{5,{{"Q....","..Q..","....Q",".Q...","...Q."},{"Q....","...Q.",".Q...","....Q","..Q.."},{".Q...","...Q.","Q....","..Q..","....Q"},{".Q...","....Q","..Q..","Q....","...Q."},{"..Q..","Q....","...Q.",".Q...","....Q"},{"..Q..","....Q",".Q...","...Q.","Q...."},{"...Q.","Q....","..Q..","....Q",".Q..."},{"...Q.",".Q...","....Q","..Q..","Q...."},{"....Q",".Q...","...Q.","Q....","..Q.."},{"....Q","..Q..","Q....","...Q.",".Q..."}}},
		{4,{{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}}},
		{1,{{"Q"}}},
		{2,{}},
		{3,{}},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		Solution2 solution;
		cout << test.n << " -> ";
		auto result = solution.solveNQueens(test.n);
		utils::printMatrix(result, true);
		cout << "\r\n";

		if (result != test.expected) return 1;
	}
	return 0;
}
