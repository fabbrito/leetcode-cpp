#include "pch.h"
#include "Solution67.h"

namespace leetcode_67 {
	using namespace std;
	class Solution;
}

class leetcode_67::Solution {
public:
	string addBinary(string a, string b) {
		string answer = "";

		int i = a.length() - 1, j = b.length() - 1;
		bool carry = false, A = false, B = false;
		while (i >= 0 || j >= 0 || carry) {
			A = i >= 0 && a[i] == '1';
			B = j >= 0 && b[j] == '1';
			char elem = (char)((int)(carry ^ (A ^ B)) + '0');
			answer = elem + answer;
			carry = (A && B) || ((A ^ B) && carry);
			i--;
			j--;
		}
		return answer;
	}
};

int test_67()
{
	using namespace leetcode_67;
	struct Test {
		string a, b;
		string expected;
	};
	vector<Test> tests = {
		{"11","1","100"},
		{"1010","1011","10101"},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;

		auto result = solution.addBinary(test.a, test.b);
		cout << test.a << " + " << test.b << " -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}