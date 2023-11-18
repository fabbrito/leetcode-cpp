#include "pch.h"
#include "Solution17.h"

namespace leetcode_17 {
	class Solution {
	public:
		std::string digitToLetters(char digit);
		std::vector<std::string> letterCombinations(std::string digits);
	};
}

std::string leetcode_17::Solution::digitToLetters(char digit) {
	std::string letters;
	switch (digit) {
	case '2':
		letters = "abc";
		break;
	case '3':
		letters = "def";
		break;
	case '4':
		letters = "ghi";
		break;
	case '5':
		letters = "jkl";
		break;
	case '6':
		letters = "mno";
		break;
	case '7':
		letters = "pqrs";
		break;
	case '8':
		letters = "tuv";
		break;
	case '9':
		letters = "wxyz";
		break;
	default:
		break;
	}
	return letters;
}

std::vector<std::string> leetcode_17::Solution::letterCombinations(std::string digits) {
	int n = digits.length();

	std::string letters;
	std::vector<std::string> prev_ans, ans;

	for (int i = n - 1; i >= 0; i--) {
		letters = digitToLetters(digits[i]);
		prev_ans = ans;
		ans = {};
		for (auto& curr_elem : letters) {
			if (prev_ans.empty()) {
				ans.push_back({ curr_elem });
			}
			for (auto& prev_elem : prev_ans) {
				std::string aux = { curr_elem };
				aux += prev_elem;
				ans.push_back(aux);
			}
		}
	}
	return ans;
}


int test_17()
{
	using namespace leetcode_17;
	Solution solution;
	std::vector<std::string> result;
	struct Test {
		std::string digits;
		std::vector<std::string> expected;
	};
	std::vector<Test> tests = {
		{"23", {"ad","ae","af","bd","be","bf","cd","ce","cf"} },
		{"", {}},
		{"2", {"a", "b", "c"}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.letterCombinations(test.digits);

		std::cout << test.digits << " -> ";
		utils::printVector(result);
		// if (result != test.expected) return 1;
	}
	return 0;
}