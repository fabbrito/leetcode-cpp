#include "pch.h"
#include "Solution58.h"

namespace leetcode_58 {
	using namespace std;
	class Solution;
}

class leetcode_58::Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				len++;
			}
			else if (len > 0) {
				break;
			}
		}
		return len;
	}
};

int test_58()
{
	using namespace leetcode_58;
	struct Test {
		string s;
		int expected;
	};
	vector<Test> tests = {
		{"Hello World",5},
		{"   fly me   to   the moon  ",4},
		{"luffy is still joyboy",6},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		auto result = solution.lengthOfLastWord(test.s);
		cout << "\"" << test.s << "\" -> " << result << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}