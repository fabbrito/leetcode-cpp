#include "pch.h"
#include "Solution69.h"

namespace leetcode_69 {
	using namespace std;
	class Solution;
}

class leetcode_69::Solution {
public:
	// Newton's method: r_n+1 = r_n - f(r_n)/f'(r_n)
	// Using f(r) = r**2 - x => f'(r_n) = 2 r_n
	// Then r_n+1 = r_n - (r_n**2 - x)/(2 r_n)
	//            = r_n - r_n/2 + x/(2 r_n)
	//      r_n+1 = (r_n + x/r_n)/2
	int mySqrt(int x) {
		long long r = 0.5 * x; // to skip first iter
		while (r * r > x)
			r = static_cast<long long>((r + x / r) / 2);
		return r;
	}

	int mySqrtBinarySearch(int x) {
		if (x == 0)
			return x;
		int left = 1, right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			// using 'mid == x / mid' to avoid casting mid to long long
			if (mid == x / mid)
				return mid;
			else if (mid > x / mid) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return right;
	}
};

int test_69()
{
	using namespace leetcode_69;
	struct test_t {
		int x;
		int expected;
	};
	vector<test_t> tests = {
		{4,2},
		{8,2},
		{9,3},
		{10,3},
		{1073741824,32768},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;

		auto result0 = solution.mySqrt(test.x);
		auto result1 = solution.mySqrtBinarySearch(test.x);
		std::cout << "sqrt(" << test.x << ") = " << result0 << " | " << result1 << "\r\n";
		if (result0 != test.expected || result1 != test.expected) return 1;
	}

	return 0;
}