#include "pch.h"
#include "Solution75.h"

namespace leetcode_75 {
	using namespace std;
	class Solution;
}

class leetcode_75::Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, mid = 0, right = nums.size() - 1;
		while (mid <= right) {
			if (nums[mid] == 0) {
				std::swap(nums[left], nums[mid]);
				left++;
				mid++;
			}
			else if (nums[mid] == 1) {
				mid++;
			}
			else {
				std::swap(nums[mid], nums[right]);
				right--;
			}
		}
	}
};

int test_75()
{
	using namespace leetcode_75;
	struct Test {
		vector<int> nums;
		vector<int> expected;
	};
	vector<Test> tests = { // \[(([0-9],*)+)\] regex to change from [] to {}
		{{2,0,2,1,1,0},{0,0,1,1,2,2}},
		{{2,0,1},{0,1,2}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		//do {
		Solution solution;
		utils::printVector(test.nums);
		auto result = test.nums;
		solution.sortColors(result);
		std::cout << " -> ";
		utils::printVector(result);
		std::cout << "\r\n";
		if (result != test.expected) return 1;
		//} while (std::next_permutation(test.nums.begin(), test.nums.end()));
	}
	return 0;
}