#include "pch.h"
#include "Solution38.h"

class Solution {
public:
	std::string countAndSay(int n) {
		if (n == 1) return "1";
		return say(countAndSay(n - 1));
	}
private:
	std::string say(std::string s) {
		int n = s.length();
		std::string ans = "";
		int i = 0, j = 0;
		while (i <= j && j < n) {
			while (j < n && s[j] == s[i]) j++;
			ans += ((j - i) + '0');
			ans += s[i];
			i = j;
		}
		return ans;
	}
};

int test_38() {
	Solution solution;
	std::string result;
	struct Test {
		int n;
		std::string expected;
	};
	std::vector<Test> tests = {
		{1, "1"},
		{2, "11"},
		{3, "21"},
		{4, "1211"},
		{10, "13211311123113112211"},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		result = solution.countAndSay(test.n);
		std::cout << test.n << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}