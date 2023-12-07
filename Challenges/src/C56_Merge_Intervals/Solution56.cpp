#include "pch.h"
#include "Solution56.h"

namespace leetcode_56 {
	using namespace std;
	class Solution;
}

class leetcode_56::Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1) return intervals;
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans = { intervals[0] };
		for (int i = 1; i < intervals.size(); i++) {
			if (ans.back()[1] >= intervals[i][0]) { // intersection
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
			}
			else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
	}
};

int test_56()
{
	using namespace leetcode_56;
	struct Test {
		vector<vector<int>> intervals;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{{1,3},{2,6},{8,10},{15,18}},{{1,6},{8,10},{15,18}}},
		{{{1,4},{4,5}},{{1,5}}},
		{{{1,1},{1,2}},{{1,2}}},
		{{{1,4},{2,3}},{{1,4}}},
		{{{2,3},{1,4}},{{1,4}}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.intervals, true);
		auto result = solution.merge(test.intervals);
		cout << " -> ";
		utils::printMatrix(result, true);
		cout << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}