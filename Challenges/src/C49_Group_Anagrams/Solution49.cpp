#include "pch.h"
#include "Solution49.h"

namespace leetcode_49 {
	using namespace std;
	class Solution;
}

class leetcode_49::Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> str_map;
		for (string& str : strs) {
			string sorted_str = str;
			sort(sorted_str.begin(), sorted_str.end());
			str_map[sorted_str].emplace_back(str);
		}
		vector<vector<string>> anagrams;
		for (auto it = str_map.begin(); it != str_map.end();it++) {
			anagrams.emplace_back(it->second);
		}
		return anagrams;
	}
};

int test_49()
{
	using namespace leetcode_49;
	struct Test {
		vector<string> strs;
		vector<vector<string>> expected;
	};
	vector<Test> tests = {
		{{"eat","tea","tan","ate","nat","bat","bata"},{{"bat"},{"bata"},{"nat","tan"},{"ate","eat","tea"}}},
		{{"eat","tea","tan","ate","nat","bat"},{{"bat"},{"nat","tan"},{"ate","eat","tea"}}},
		{{"ac","c"},{{"c"},{"ac"}}},
		{{"a"},{{"a"}}},
		{{""},{{""}}},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.strs);
		cout << " -> ";
		auto result = solution.groupAnagrams(test.strs);

		for (auto& vec : result) {
			sort(vec.begin(), vec.end());
		}
		sort(result.begin(), result.end());

		for (auto& vec : test.expected) {
			sort(vec.begin(), vec.end());
		}
		sort(test.expected.begin(), test.expected.end());

		utils::printMatrix(result, true);
		cout << "\r\n";

		if (result != test.expected) return 1;
	}
	return 0;
}