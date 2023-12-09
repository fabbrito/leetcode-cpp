#include "pch.h"
#include "Solution60.h"

namespace leetcode_60 {
	using namespace std;
	class Solution;
}

class leetcode_60::Solution {
public:
	string getPermutation(int n, int k) {
		int factorial = 1;
		vector<int> nums;
		helper(n, factorial, nums);

		string answer = "";
		solve(k - 1, factorial, nums, answer);
		return answer;
	}
private:
	static void helper(int n, int& factorial, vector<int>& nums) {
		for (int i = 1; i < n; i++) {
			factorial = factorial * i;
			nums.push_back(i);
		}
		nums.push_back(n);
	}
	static void solve(int k, int factorial, vector<int>& nums, string& answer) {
		answer += std::to_string(nums[k / factorial]);
		nums.erase(nums.begin() + k / factorial);

		if (nums.size() == 0) {
			return;
		}

		solve(k % factorial, factorial / nums.size(), nums, answer);
	}
};

int test_60()
{
	using namespace leetcode_60;
	struct Test {
		int n, k;
		string expected;
	};
	vector<Test> tests = {
		{8, 3000, "16287543"},
		{3,3,"213"},
		{3,6,"321"},
		{3,1,"123"},
		{4,9,"2314"},

	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		auto result = solution.getPermutation(test.n, test.k);
		cout << "n = " << test.n << ", k = " << test.k << " -> \"" << result << "\"\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}