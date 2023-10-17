#include <iostream>
#include <vector>
#include "Solution.h"
#include "Solution.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
namespace leetcode_2 {
	ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* head = nullptr;
		ListNode* current = nullptr;

		int carry = 0, sum = 0, val = 0, val_1 = 0, val_2 = 0;
		while ((carry != 0) || (l1 != nullptr) || (l2 != nullptr)) {
			if (l1 != nullptr) {
				val_1 = l1->val;
				l1 = l1->next;
			}
			else {
				val_1 = 0;
			}
			if (l2 != nullptr) {
				val_2 = l2->val;
				l2 = l2->next;
			}
			else {
				val_2 = 0;
			}
			sum = val_1 + val_2 + carry;
			val = sum % 10;
			carry = (int)(sum / 10);

			ListNode* newNode = new ListNode(val);
			if (head == nullptr) {
				head = newNode;
				current = newNode;
			}
			else {
				current->next = newNode;
				current = newNode;
			}
		}

		return head;
	}

	ListNode* to_linked_list(std::vector<int>& vec) {
		ListNode* head = nullptr;
		ListNode* current = nullptr;
		for (auto& val : vec) {
			ListNode* newNode = new ListNode(val);
			if (head == nullptr) {
				head = newNode;
				current = newNode;
			}
			else {
				current->next = newNode;
				current = newNode;
			}
		}
		return head;
	}

	void print_linked_list(ListNode* l) {
		ListNode* current = l;
		while (current != nullptr) {
			if (current->next != nullptr)
				std::cout << current->val << " -> ";
			else
				std::cout << current->val << std::endl;
			current = current->next;
		}
	}
}

int test_2() {
	using namespace leetcode_2;
	Solution* solution = new Solution;
	std::vector<int> result;
	struct Test {
		std::vector<int> list1;
		std::vector<int> list2;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{ {2, 4, 3}, {5, 6, 4}, {7, 0, 8} },
		{ {0}, {0}, {0} },
		{ {9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1} },
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		ListNode* l1 = to_linked_list(test.list1);
		ListNode* l2 = to_linked_list(test.list2);
		print_linked_list(l1);
		print_linked_list(l2);
		ListNode* result = solution->addTwoNumbers(l1, l2);
		print_linked_list(result);
	}

	return 0;
}
