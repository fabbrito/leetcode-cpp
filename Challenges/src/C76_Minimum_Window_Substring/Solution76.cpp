#include "pch.h"
#include "Solution76.h"

namespace leetcode_76 {
using namespace std;
class Solution {
public:
	string minWindow(string S, string T) {
		string result;
		if (S.empty() || T.empty()) {
			return result;
		}
		unordered_map<char, int> map;
		unordered_map<char, int> window;
		for (int i = 0; i < T.length(); i++) {
			map[T[i]]++;
		}
		int minLength = INT_MAX;
		int letterCounter = 0;
		for (int left = 0, right = 0; right < S.length(); ++right) {
			char c = S[right];
			if (map.find(c) != map.end()) {
				window[c]++;
				if (window[c] <= map[c]) {
					letterCounter++;
				}
			}
			if (letterCounter >= T.length()) {
				while (map.find(S[left]) == map.end() || window[S[left]] > map[S[left]]) {
					window[S[left]]--;
					left++;
				}
				if (right - left + 1 < minLength) {
					minLength = right - left + 1;
					result = S.substr(left, minLength);
				}
			}
		}
		return result;
	}

	string minWindowVector(string S, string T) {
		vector<int> map(128, 0);
		for (char c : T) {
			map[c]++;
		}

		int counter = T.length();
		int left = 0, right = 0;
		int len = INT_MAX, off = 0;

		while (right < S.length()) {
			if (map[S[right++]]-- > 0) {
				counter--;
			}
			while (counter == 0) {
				if (right - left < len) {
					off = left;
					len = right - off;
				}
				if (map[S[left++]]++ == 0) {
					counter++;
				}
			}
		}
		return len == INT_MAX ? "" : S.substr(off, len);
	}
};
}

int test_76() {
	using namespace leetcode_76;
	struct test_t {
		string s, t;
		string expected;
	};
	vector<test_t> tests = {
		{"a", "aa", ""},
		{"ADOBECODEBANC", "ABC", "BANC"},
		{"a", "a", "a"},
		{"a", "b", ""},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;

		auto result0 = solution.minWindow(test.s, test.t);
		auto result1 = solution.minWindowVector(test.s, test.t);
		std::cout << test.s << ", " << test.t << " -> \"" << result0 << "\" | \"" << result1 << "\"\r\n";
		if (result0 != test.expected || result1 != test.expected)
			return 1;
	}

	return 0;
}
