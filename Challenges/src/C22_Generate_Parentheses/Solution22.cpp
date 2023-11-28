#include "pch.h"
#include "Solution22.h"

namespace leetcode_22 {
	class Solution {
	public:
		std::vector<std::string> modifyParenthesis(std::string s);
		std::vector<std::string> generateParenthesis(int n);

		std::vector<std::string> solveRecursively(int n, int pOpen, int pClose, std::string s, std::vector<std::string> prev_ans = {});
		std::vector<std::string> generateParenthesis2(int n);
	};
}

namespace leetcode_22 {
	std::vector<std::string> Solution::modifyParenthesis(std::string s) {
		int n = s.length();
		std::vector<std::string> ans;
		for (int i = 0; i < n; i++) {
			std::string aux = s.substr(0, i + 1);
			aux += "()";
			aux += s.substr(i + 1, n - i - 1);
			ans.push_back(aux);
		}
		ans.push_back("()" + s);
		ans.push_back(s + "()");
		return ans;
	}

	std::vector<std::string> Solution::generateParenthesis(int n) {
		if (n == 1) return { "()" };
		if (n == 2) return { "(())", "()()" };
		std::vector<std::string> ans;
		std::unordered_set<std::string> ans_set;
		std::vector<std::string> prev = generateParenthesis(n - 1);
		for (std::string& prev_elem : prev) {
			std::vector<std::string> aux = modifyParenthesis(prev_elem);
			for (std::string& elem : aux) {
				if (ans_set.count(elem) == 0) {
					ans_set.insert(elem);
					ans.push_back(elem);
				}
			}
		}
		return ans;
	}

	std::vector<std::string> Solution::solveRecursively(int n, int pOpen, int pClose, std::string s, std::vector<std::string> ans) {
		if (s.size() == 2 * n)
			ans.push_back(s);
		if (pOpen < n)
			ans = solveRecursively(n, pOpen + 1, pClose, s + "(", ans);
		if (pClose < pOpen)
			ans = solveRecursively(n, pOpen, pClose + 1, s + ")", ans);
		return ans;
	}

	std::vector<std::string> Solution::generateParenthesis2(int n) {
		return solveRecursively(n, 0, 0, "");
	}

}

int test_22() {
	using namespace leetcode_22;
	Solution solution;
	std::vector<std::string> result;
	struct Test {
		int n;
		std::vector<std::string> expected;
	};
	std::vector<Test> tests = {
		{3, {"((()))","(()())","(())()","()(())","()()()"}},
		{1, {"()"}},
		{2, {"(())","()()"}},
		{4, {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.generateParenthesis(test.n);
		std::cout << test.n << std::endl;
		std::sort(result.begin(), result.end());
		utils::printVector(result);
		std::sort(test.expected.begin(), test.expected.end());
		utils::printVector(test.expected);
		//std::cout << result.size() << ", " << test.expected.size() << std::endl;
		if (result.size() != test.expected.size()) return 1;
		//if (result != test.expected) return 1;
	}
	return 0;
}