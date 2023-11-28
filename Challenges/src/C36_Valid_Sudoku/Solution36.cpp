#include "pch.h"
#include "./Solution36.h"

namespace leetcode_36 {
	class Solution {
	public:
		bool isValidSudoku(std::vector<std::vector<char>>& board);
	};
}

bool leetcode_36::Solution::isValidSudoku(std::vector<std::vector<char>>& board)
{
	std::unordered_set<char> u_set;
	// check for repetitions within a line
	for (int l = 0; l < 9; l++) {
		u_set.clear();
		for (int c = 0; c < 9; c++) {
			char elem = board[l][c];
			if (elem != '.') { // digits 0-9
				if (u_set.count(elem) != 0) {
					return false;
				}
				u_set.insert(elem);
			}
		}
	}

	// check for repetitions within a column
	for (int c = 0; c < 9; c++) {
		u_set.clear();
		for (int l = 0; l < 9; l++) {
			char elem = board[l][c];
			if (elem >= 48 && elem <= 57) { // digits 0-9
				if (u_set.count(elem) != 0) {
					return false;
				}
				u_set.insert(elem);
			}
		}
	}

	// check for repetitions within sub-boxes
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			u_set.clear();
			for (int l = i * 3; l < (i + 1) * 3; l++) {
				for (int c = j * 3; c < (j + 1) * 3; c++) {
					char elem = board[l][c];
					if (elem >= 48 && elem <= 57) { // digits 0-9
						if (u_set.count(elem) != 0) {
							return false;
						}
						u_set.insert(elem);
					}
				}
			}
		}
	}
	return true;
}

int test_36()
{
	using namespace leetcode_36;
	Solution solution;
	bool result;
	struct Test {
		std::vector<std::vector<char>> board;
		bool expected;
	};
	std::vector<Test> tests = {
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
		}, true},
		{{
			{'8','3','.','.','7','.','.','.','.'},
			{'6','.','.','1','9','5','.','.','.'},
			{'.','9','8','.','.','.','.','6','.'},
			{'8','.','.','.','6','.','.','.','3'},
			{'4','.','.','8','.','3','.','.','1'},
			{'7','.','.','.','2','.','.','.','6'},
			{'.','6','.','.','.','.','2','8','.'},
			{'.','.','.','4','1','9','.','.','5'},
			{'.','.','.','.','8','.','.','7','9'},
		}, false},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		utils::printMatrix(test.board);
		result = solution.isValidSudoku(test.board);
		std::cout << (result ? "Valid" : "Invalid") << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}
