#include "pch.h"
#include "Solution46.h"

namespace leetcode_46 {
	using namespace std;
	class Solution;
}

class leetcode_46::Solution {
public:
	vector<vector<int>> permuteFast(vector<int>& nums) {
		vector<vector<int>> ans = { nums };
		vector<int> vec = nums;
		nextPermutation(vec);
		while (vec != nums) {
			ans.push_back(vec);
			nextPermutation(vec);
		}
		return ans;
	}
private:
	static void reverse(vector<int>& nums, int pStart, int pEnd) {
		while (pStart < pEnd) {
			swap(nums[pStart], nums[pEnd]);
			pStart++;
			pEnd--;
		}
		return;
	}
	static void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 2;
		while (i >= 0 && nums[i] >= nums[i + 1])
			i--;
		if (i >= 0) {
			int j = n - 1;
			while (j >= 0 && nums[j] <= nums[i])
				j--;
			swap(nums[j], nums[i]);
		}
		reverse(nums, i + 1, n - 1);
		return;
	}
};

int test_46()
{
	using namespace leetcode_46;
	struct Test {
		vector<int> nums;
		vector<vector<int>> expected;
	};
	vector<Test> tests = {
		{{1,2,3},{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
		{{0,1},{{0,1},{1,0}}},
		{{1},{{1}}},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		cout << " -> ";
		vector<vector<int>> result = solution.permuteFast(test.nums);
		utils::printMatrix(result, true);
		cout << "\r\n";
		if (result != test.expected) return 1;
	}
	return 0;
}