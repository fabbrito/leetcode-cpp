#include "pch.h"
#include "Solution66.h"

namespace leetcode_66 {
	using namespace std;
	class Solution;
}

class leetcode_66::Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		vector<int> answer = digits;
		for (int i = digits.size() - 1; i >= 0; i--) {
			int value = answer[i] + carry;
			answer[i] = value % 10;
			carry = value / 10;
		}

		if (carry) {
			answer.insert(answer.begin(), carry);
		}
		return answer;
	}
};

int test_66()
{
	using namespace leetcode_66;
	struct Test {
		vector<int> digits;
		vector<int> expected;
	};
	vector<Test> tests = {
		{{1,2,3},{1,2,4}},
		{{4,3,2,1},{4,3,2,2}},
		{{9},{1,0}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.digits);
		auto result = solution.plusOne(test.digits);
		cout << " -> ";
		utils::printVector(result);
		cout << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}