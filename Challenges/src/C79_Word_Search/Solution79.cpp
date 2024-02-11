#include "pch.h"
#include "Solution79.h"

namespace leetcode_79 {

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (size_t i = 0; i < board.size(); ++i) {
			for (size_t j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == word[0] && dfs(i, j, board, word)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	bool dfs(int i, int j, vector<vector<char>>& board, string_view word) {
		if (word.size() == 0) {
			return true;
		}
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0]) {
			return false;
		}
		char c = board[i][j];
		board[i][j] = '*';
		string_view s = word.substr(1);
		bool ret = dfs(i - 1, j, board, s) || dfs(i + 1, j, board, s) || dfs(i, j - 1, board, s) || dfs(i, j + 1, board, s);
		board[i][j] = c;
		return ret;
	}
};
}

int test_79() {
	using namespace leetcode_79;
	struct test_t {
		vector<vector<char>> board;
		string word;
		bool expected;
	};
	vector<test_t> tests = {
		// \[(([0-9]*,*)+)\] -> {$1} regex to change from [1,2,3] to {1,2,3}
		// \[((("[A-Za-z]")*,*)+)\] -> {$1} regex to change from ["A","B","C"] to {"A","B","C"}
		// "([A-Za-z])" -> '$1' regex to change from "A" to 'A'
		{
			{
				{'A','B','C','E'},
				{'S','F','C','S'},
				{'A','D','E','E'},
			},
			"SEE",
			true,
		},
		{
			{
				{'A','B','C','E'},
				{'S','F','C','S'},
				{'A','D','E','E'},
			},
			"ABCCED",
			true,
		},
		{
			{
				{'A','B','C','E'},
				{'S','F','C','S'},
				{'A','D','E','E'},
			},
			"ABCB",
			false,
		},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.board);
		auto result = solution.exist(test.board, test.word);
		std::cout << "\"" << test.word << "\" -> " << result << "\r\n";
		if (result != test.expected) return 1;

	}

	return 0;
}
