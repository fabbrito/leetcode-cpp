#include "pch.h"
#include "Solution37.h"

namespace leetcode_37 {
	using namespace std;
	class Solution;
}

class leetcode_37::Solution {
public:
	using BitsetArray = array<bitset<9>, 9>;
	using Board = vector<vector<char>>;
	void solveSudoku(Board& board)const noexcept
	{
		BitsetArray row_contains = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		BitsetArray col_contains = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		BitsetArray cell_contains = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				char digit;
				if ((digit = board[row][col]) != '.') {
					int digit_idx = digit - '1';
					row_contains[row].set(digit_idx);
					col_contains[col].set(digit_idx);
					int cell = get_cell(row, col);
					cell_contains[cell].set(digit_idx);
				}
			}
		}
		solve(board, 0, 0, row_contains, col_contains, cell_contains);
	}
private:
	static constexpr int get_cell(int row, int col) noexcept {
		return (row / 3) * 3 + (col / 3);
	}

	static constexpr int get_next_row(int row, int col) noexcept {
		return row + (col + 1) / 9;
	}

	static constexpr int get_next_col(int col) noexcept {
		return (col + 1) % 9;
	}

	static constexpr pair<int, int> next_empty_position(Board& board, int row, int col) noexcept {
		while (row != 9) {
			if (board[row][col] == '.')
				return { row, col };
			row = get_next_row(row, col);
			col = get_next_col(col);
		}
		return { 9,0 };
	}

	static bool solve(Board& board, int row_start, int col_start, BitsetArray& row_contains, BitsetArray& col_contains, BitsetArray& cell_contains) noexcept {
		auto [row, col] = next_empty_position(board, row_start, col_start);
		if (row == 9)
			return true;

		int cell = get_cell(row, col);
		// consolidates all numbers already used
		bitset<9> const contains = row_contains[row] | col_contains[col] | cell_contains[cell];
		if (contains.all()) // no remaining numbers to be used
			return false;

		// loop through the digits and check if it was not used
		for (int digit_idx = 0; digit_idx < 9; digit_idx++) {
			if (!contains[digit_idx]) {
				// put digit on the board
				board[row][col] = static_cast<char>(digit_idx + '1');
				row_contains[row].set(digit_idx);
				col_contains[col].set(digit_idx);
				cell_contains[cell].set(digit_idx);

				// recursively check for a solution
				if (solve(board, row, col, row_contains, col_contains, cell_contains))
					return true;

				row_contains[row].reset(digit_idx);
				col_contains[col].reset(digit_idx);
				cell_contains[cell].reset(digit_idx);
			}
		}
		// none of the guesses succeeded
		board[row][col] = '.';
		return false;
	}
};


int test_37() {
	using namespace leetcode_37;
	Solution solution;
	struct Test {
		vector<vector<char>> board;
		vector<vector<char>> expected;
	};
	vector<Test> tests = {
		{{
			{'5','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'},
		},{
			{'5','3','4','6','7','8','9','1','2'},
			{'6','7','2','1','9','5','3','4','8'},
			{'1','9','8','3','4','2','5','6','7'},
			{'8','5','9','7','6','1','4','2','3'},
			{'4','2','6','8','5','3','7','9','1'},
			{'7','1','3','9','2','4','8','5','6'},
			{'9','6','1','5','3','7','2','8','4'},
			{'2','8','7','4','1','9','6','3','5'},
			{'3','4','5','2','8','6','1','7','9'},
		}},
		{{
			{'.','.','8','.','5','.','.','.','.'},
			{'2','.','.','4','.','.','.','.','9'},
			{'.','.','.','3','1','.','.','.','2'},
			{'.','7','.','.','.','.','.','9','.'},
			{'9','6','.','.','.','.','.','7','3'},
			{'8','.','5','.','.','.','1','.','6'},
			{'7','.','.','.','8','3','.','.','.'},
			{'6','.','.','.','.','1','.','.','5'},
			{'.','.','.','.','4','.','7','.','.'},
		},{
			{'4','3','8','2','5','9','6','1','7'},
			{'2','1','6','4','7','8','3','5','9'},
			{'5','9','7','3','1','6','4','8','2'},
			{'3','7','2','1','6','5','8','9','4'},
			{'9','6','1','8','2','4','5','7','3'},
			{'8','4','5','9','3','7','1','2','6'},
			{'7','2','4','5','8','3','9','6','1'},
			{'6','8','3','7','9','1','2','4','5'},
			{'1','5','9','6','4','2','7','3','8'},
		}
		},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		vector<vector<char>> board = test.board;
		utils::printMatrix(test.board);
		solution.solveSudoku(board);
		utils::printMatrix(board);
		if (board != test.expected) return 1;
	}
	return 0;
}
