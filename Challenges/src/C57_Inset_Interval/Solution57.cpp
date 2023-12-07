#include "pch.h"
#include "Solution57.h"

namespace leetcode_57 {
	using namespace std;
	class Solution;
}

class leetcode_57::Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& curr_interval) {
		vector<vector<int>> result;

		for (auto& interval : intervals) {
			// no overlap: the current interval begins after the end of the current one in test
			if (interval.back() < curr_interval.front()) {
				result.push_back(interval);
			}
			// no overlap: the current interval ends before the beginning of current one in test
			// This will insert the current interval in the middle of the vector of intervals, offsetting the
			// remaining ones to the right
			else if (interval.front() > curr_interval.back()) {
				result.push_back(curr_interval);
				curr_interval = interval;
			}
			// overlap: the current interval is within the current range in test.
			// Reconstruct the current interval to accommodate the merge of overlapping ranges
			else if (interval.back() >= curr_interval.front() || interval.front() <= curr_interval.back()) {
				curr_interval.front() = min(interval.front(), curr_interval.front());
				curr_interval.back() = max(curr_interval.back(), interval.back());
			}
		}
		// curr_interval will hold: the modified current interval or the last position of intervals
		result.push_back(curr_interval);
		return result;
	}
};

int test_57()
{
	using namespace leetcode_57;
	struct Test {
		vector<vector<int>> intervals;
		vector<int> newInterval;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{{1,2},{4,5},{6,7},{8,10},{12,16}},{3,17},{{1,2},{3,17}}},
		{{{1,2},{3,5},{6,7},{8,10},{12,16}},{0,11},{{0,11},{12,16}}},
		{{{1,2},{3,5},{6,7},{8,10},{12,16}},{0,16},{{0,16}}},
		{{{1,2},{3,5},{6,7},{8,10},{12,16}},{1,17},{{1,17}}},
		{{{1,3},{6,9}},{2,5},{{1,5},{6,9}}},
		{{{1,3},{6,9}},{4,7},{{1,3},{4,9}}},
		{{{1,3},{6,9}},{4,5},{{1,3},{4,5},{6,9}}},
		{{{1,2},{3,5},{6,7},{8,10},{12,16}},{4,8},{{1,2},{3,10},{12,16}}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printMatrix(test.intervals, true);
		cout << ", ";
		utils::printVector(test.newInterval);
		auto result = solution.insert(test.intervals, test.newInterval);
		cout << " -> ";
		utils::printMatrix(result, true);
		cout << "\r\n";

		sort(result.begin(), result.end(), [](vector<int> a, vector<int> b) {return a.front() < b.front(); });
		sort(test.expected.begin(), test.expected.end(), [](vector<int> a, vector<int> b) {return a.front() < b.front(); });
		if (result != test.expected) return 1;
	}
	return 0;
}