#include "pch.h"
#include "Solution50.h"
#define EPSILON 100*DBL_EPSILON

namespace leetcode_50 {
	using namespace std;
	class Solution;
}

class leetcode_50::Solution {
public:
	double myPow(double x, int n) {
		if (x == 0 || x == 1) {
			return x;
		}
		if (n == 0) {
			return 1;
		}
		double pow_half = myPow(x, n / 2);
		if ((n % 2) == 0) {
			return pow_half * pow_half;
		}
		else {
			if (n > 0) {
				return x * pow_half * pow_half;
			}
			else {
				return (pow_half * pow_half) / x;
			}
		}
	}
};

int test_50()
{
	using namespace leetcode_50;
	struct Test {
		double x;
		int n;
		double expected;
	};
	vector<Test> tests = {
		{1.0,10,1.0},
		{2.0,10,1024.0},
		{2.1,3,9.261},
		{2.0,-2,0.25},
	};

	cout << "Testing Solution" << endl;
	for (auto& test : tests) {
		Solution solution;
		auto result = solution.myPow(test.x, test.n);
		cout << "pow(" << test.x << ", " << test.n << ") = " << result << "\r\n";

		if (fabs(result - test.expected) > EPSILON)
			return 1;
	}
	return 0;
}