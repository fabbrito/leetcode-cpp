#ifndef ADD_TWO_NUMBERS_H_INCLUDED
#define ADD_TWO_NUMBERS_H_INCLUDED

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

namespace leetcode_2 {
	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	};
}

int test_2();

#endif