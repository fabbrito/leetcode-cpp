#include "pch.h"
#include "Solution80.h"

namespace leetcode_80 {

using namespace std;

class Solution {
public:
	int removeDuplicates2(vector<int>& nums) {
		const int MAX_REPETITIONS = 2;

		// pIns is the pointer to the next available position in the unique vector (beginning of nums)
		// pCurr traverses the vector from one unique element to another
		// pNext points to the next unique element in the vector
		int pIns = 0, pCurr = 0, pNext = 0;
		while (pCurr < nums.size()) {
			pNext = pCurr;
			while (pNext < nums.size() && nums[pNext] == nums[pCurr]) { pNext++; }
			int count = std::min(pNext - pCurr, MAX_REPETITIONS);
			for (int i = 0; i < count; ++i) {
				nums[pIns++] = nums[pCurr++];
			}
			pCurr = pNext;
		}
		return pIns;
	}
	int removeDuplicates(vector<int>& nums) {
		const int MAX_REPETITIONS = 2;
		int idx = 0;
		for (const int num : nums) {
			if (idx < MAX_REPETITIONS || num > nums[idx - MAX_REPETITIONS]) {
				nums[idx++] = num;
			}
		}
		return idx;
	}
};
}

int test_80() {
	using namespace leetcode_80;
	struct test_t {
		vector<int> nums;
		int expected;
		vector<int> expectedNums;
	};
	vector<test_t> tests = {
		// \[(([0-9]*,*)+)\] -> {$1} regex to change from [1,2,3] to {1,2,3}
		// \[((("[A-Za-z]")*,*)+)\] -> {$1} regex to change from ["A","B","C"] to {"A","B","C"}
		{{1,1,1,1,1,1,1,1,1,1,2,2,2,2,3,4,5,5,5,5,5},8,{1,1,2,2,3,4,5,5}},
		{{1,1,1,2,2,3},5,{1,1,2,2,3,-1}},
		{{0,0,1,1,1,1,2,3,3},7,{0,0,1,1,2,3,3,-1,-1}},
		{{0},1,{0}},
		{{0,0},2,{0,0}},
		{{0,0,0},2,{0,0}},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		utils::printVector(test.nums);
		auto result = solution.removeDuplicates(test.nums);
		std::cout << " -> " << result << ", ";
		utils::printVector(test.nums);
		std::cout << "\r\n";

		if (result != test.expected) return 1;
		for (int i = 0; i < result; ++i) {
			if (test.nums[i] != test.expectedNums[i]) {
				return 1;
			}
		}
	}

	return 0;
}
