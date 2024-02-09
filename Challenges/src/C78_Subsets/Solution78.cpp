#include "pch.h"
#include "Solution78.h"

namespace leetcode_78 {

using namespace std;

class Solution {
public:
	// ----------------------------------
	// Iterative Solution
	// Time complexity : O(N*(2^N))
	// Space complexity : O(N*(2^N))
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res = { {} };
		for (auto& num : nums) {
			int sz = res.size();
			for (int j = 0; j < sz; j++) {
				vector<int> temp = res[j];
				temp.push_back(num);
				res.push_back(temp);
			}
		}
		return res;
	}
	// ----------------------------------
public:
	// ----------------------------------
	// Bit Manipulation
	// Time complexity : O(N*(2^N))
	// Space complexity : O(N*(2^N))
	// Explanation: {A,B,C}, n = 3
	//  ABC -> Result
	//  000 -> {}
	//  001 -> {C}
	//  010 -> {B}
	//  011 -> {B,C}
	//  ... -> ...
	//  110 -> {A,B}
	//  111 -> {A,B,C}
	vector<vector<int>> subsetsBit(vector<int>& nums) {
		vector<vector<int>> res = { {} };
		int n = nums.size();
		int num = pow(2, n);
		for (int idx = 1; idx < num; ++idx) {
			vector<int> temp;
			for (int bit = 0; bit < n; ++bit) {
				if (idx & 1 << bit) {
					temp.push_back(nums[bit]);
				}
			}
			res.push_back(temp);
		}
		return res;
	}
	// ----------------------------------
public:
	// ----------------------------------
	// Recursive Solution
	// Time complexity : O(N*(2^N))
	// Space complexity : O(N*(2^N))
	vector<vector<int>> subsetsRecursive(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> vec;
		helper(nums, 0, vec, res);
		return res;
	}
private:
	static void helper(vector<int>& nums, int i, vector<int>& vec, vector<vector<int>>& res) {
		res.push_back(vec);
		for (int j = i; j < nums.size(); j++) {
			vec.push_back(nums[j]);
			helper(nums, j + 1, vec, res);
			vec.pop_back();
		}
	}
	// ----------------------------------
};
}

int test_78() {
	using namespace leetcode_78;
	struct test_t {
		vector<int> nums;
		vector<vector<int>> expected;
	};
	vector<test_t> tests = { // \[(([0-9],*)+)\] -> {$1} regex to change from [1,2,3] to {1,2,3}
		{{1,2,3},{{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}}},
		{{0},{{},{0}}},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		std::cout << " -> ";
		auto result = solution.subsets(test.nums);
		utils::printMatrix(result, true, ", ");
		std::cout << "\r\n";
		if (result != test.expected) return 1;
	}

	return 0;
}
