#include "pch.h"
#include "Solution43.h"

namespace leetcode_43 {
	using namespace std;
	class Solution;
}

class leetcode_43::Solution {
public:
	string multiply(string num1, string num2) {
		string ans(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; i >= 0; i--) {
			for (int j = num2.size() - 1; j >= 0; j--) {
				int digit = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
				ans[i + j + 1] = digit % 10 + '0';
				ans[i + j] += digit / 10;
			}
		}

		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] != '0') return ans.substr(i);
		}

		return "0";
	}
};

int test_43()
{
	using namespace leetcode_43;
	Solution solution;
	string result;
	struct Test {
		string num1;
		string num2;
		string expected;
	};
	vector<Test> tests = {
		{"123","456","56088"},
		{"123","0","0"},
		{"0","30","0"},
		{"11223344556677889900","100","1122334455667788990000"},
		{"0","3","0"},
		{"2","3","6"},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		cout << test.num1 << " * " << test.num2;
		result = solution.multiply(test.num1, test.num2);
		cout << " = " << result << endl;
		if (result != test.expected) return 1;
	}
	return 0;
}