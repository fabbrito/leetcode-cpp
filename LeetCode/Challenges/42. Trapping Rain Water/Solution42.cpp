#include "Solution42.h"
#include "utils.h"

namespace leetcode_42 {
	using namespace std;
	class Solution;
}

class leetcode_42::Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		vector<int> dh(n + 1, 0);
		vector<int> ddh(n , 0);
		for (int i = 1; i < n; i++) {
			dh[i-1] = height[i] - height[i - 1];

			//if (i < n - 2)
				//ddh[i] = height[i + 2] - height[i + 1] * 2 + height[i];
		}
		utils::printVector(dh, ", ", false);
		return 1;
		for (int i = 1; i <= n; i++) {
			ddh[i] = dh[i] - dh[i - 1];
		}
		utils::printVector(ddh, ", ", false);
		return 0;
		vector<int> idx_max = { 0 }, idx_min;
		for (int i = 0; i < n - 2; i++) {
			if (dh[i] * dh[i + 1] < 0) { // sign change -> means zero crossing
				if (ddh[i] < 0) { // local max index
					idx_max.push_back(i + 1);
				}
				else { // local min index
					idx_min.push_back(i + 1);
				}
				//cout << i + 1 << ", " << height[i + 1] << " -> " << (ddh[i] < 0 ? "local max" : "local min") << endl;
			}
		}
		idx_max.push_back(n - 1);
		cout << "\r\n";
		utils::printVector(idx_max, ", ", false);
		utils::printVector(idx_min, ", ", false);
		return 1;
	}
};




int test_42()
{
	using namespace leetcode_42;
	Solution* solution = new Solution;
	int result;
	struct Test {
		vector<int> height;
		int expected;
	};
	vector<Test> tests = {
		{{4,2,0,3,2,5},9},
		{{0,1,0,2,1,0,1,3,2,1,2,1},6},
		{{1},0},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		utils::printVector(test.height, ", ", false);
		result = solution->trap(test.height);
		cout << " -> " << result << endl;
		if (result != test.expected) return 1;
	}
	delete solution;
	return 0;
}
