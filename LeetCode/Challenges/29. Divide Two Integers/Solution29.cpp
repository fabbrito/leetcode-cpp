#include "pch.h"
#include "./Solution29.h"

namespace leetcode_29 {
	class Solution {
	public:
		int divide(int dividend, int divisor);
	};
}

//std::cout << "bit representation = " << std::bitset<32>(i)  << std::endl;

int leetcode_29::Solution::divide(int N, int D) {
	// N by D, placing the quotient in Q and the remainder in R
	// Consider the edge case INT_MIN=-2^31 whose change sign is not INT
	if (N == INT_MIN && D == -1)
		return INT_MAX;
	if (N == INT_MIN && D == 1)
		return INT_MIN;
	if (D == INT_MIN && N != INT_MIN) return 0;

	// Edge cases can lead to TLE
	if (N == D) return 1;
	if ((0 <= N && N < D) || (N < 0 && D < N)) return 0;

	bool is_negative = false;
	if (N > 0) {// N != INT_MIN
		N = -N;
		is_negative = !is_negative;
	}
	if (D < 0) {// D != INT_MIN
		D = -D;
		is_negative = !is_negative;
	}
	int Q = 0;
	while (-D >= N) {// TLE can happen when -N/D is large if only performing N += D
		int x = D;
		int k = 0;// Performing A += x, where x = D*(2^k) <= INT_MAX
		while (N <= -x && x <= INT_MAX) {
			N += x;
			Q += (1 << k);
			if (x < (1 << 30)) {
				x <<= 1;
				k++;
			}
		}
	}
	return (is_negative) ? Q : -Q;
}


int test_29() {
	using namespace leetcode_29;
	Solution solution;
	int result;
	struct Test {
		int dividend;
		int divisor;
		int expected;
	};
	std::vector<Test> tests = {
		{7, -3, -2},
		{3, -3, -1},
		{3, 3, 1},
		{1, 2, 0},
		{INT_MIN, 2,INT_MIN/2},
		{INT_MIN, 3,INT_MIN / 3},
		{INT_MIN, 3,INT_MIN / 3},
		{INT_MAX, 3, INT_MAX / 3},
		{INT_MAX, INT_MIN, 0},
		{INT_MIN, INT_MAX, -1},
		{INT_MIN, INT_MIN, 1},
		{INT_MIN + 2, INT_MAX, 0},
	};
	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		result = solution.divide(test.dividend, test.divisor);
		std::cout << test.dividend << " / " << test.divisor;
		std::cout << " = res: " << result << std::endl;
		if (result != test.expected) return 1;
	}
	return 0;
}