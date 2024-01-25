#include "pch.h"
#include "Solution65.h"

namespace leetcode_65 {
	using namespace std;
	class Solution;
}

class leetcode_65::Solution {
public:
	bool isNumber(string s) {
		int pos = 0;
		bool haveNum = false;
		size_t n = s.length();

		// Check all the prefix spaces
		while (pos < n && isSpace(s[pos])) pos++;

		// Check the next char if it's a +/- signal
		if (pos < n && isSign(s[pos])) pos++;

		// Check the numbers before a dot '.'
		while (pos < n && isDigit(s[pos])) {
			haveNum = true;
			pos++;
		}

		// Check the dot '.'
		if (pos < n && isDot(s[pos])) pos++;

		// Check the numbers after a dot '.'
		while (pos < n && isDigit(s[pos])) {
			haveNum = true;
			pos++;
		}

		// Check the 'e' / 'E' and if there's a +/- signal after
		if (haveNum && pos < n && isE(s[pos])) {
			haveNum = false;
			pos++;
			if (pos < n && isSign(s[pos])) pos++;
		}

		// Check the numbers after 'e' / 'E'
		while (pos < n && isDigit(s[pos])) {
			haveNum = true;
			pos++;
		}

		// Check all the remaining spaces
		while (pos < n && isSpace(s[pos])) pos++;

		// Everything is done, if the string not empty, return false.
		return (pos == n && haveNum);
	}
private:
	bool isSpace(char c) { return c == ' '; }
	bool isSign(char c) { return c == '+' || c == '-'; }
	bool isDot(char c) { return c == '.'; }
	bool isDigit(char c) { return c >= '0' && c <= '9'; }
	bool isE(char c) { return c == 'e' || c == 'E'; }
};

int test_65()
{
	using namespace leetcode_65;
	vector<string> valid = { "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789" };
	vector<string> invalid = { "abc", "e", ".","1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53" };

	std::cout << "----------------- Testing Invalid Numbers -----------------\r\n";
	for (auto& s : invalid) {
		Solution solution;
		auto result = solution.isNumber(s);
		std::cout << s << " -> " << result << "\r\n";
		if (result != false) return 1;
	}

	std::cout << "------------------ Testing Valid Numbers ------------------\r\n";
	for (auto& s : valid) {
		Solution solution;
		auto result = solution.isNumber(s);
		std::cout << s << " -> " << result << "\r\n";
		if (result != true) return 1;
	}

	return 0;
}