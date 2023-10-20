#include <iostream>
#include <vector>
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

namespace leetcode_24 {
	ListNode* Solution::swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode* ans = new ListNode(0);
		ans->next = head;

		ListNode* curr = ans;
		while (curr->next != nullptr && curr->next->next != nullptr) {
			ListNode* t1 = curr->next;
			ListNode* t2 = curr->next->next;
			curr->next = t2;
			t1->next = t2->next;
			t2->next = t1;
			curr = curr->next->next;
		}
		return ans->next;
	}
}

namespace leetcode_24 {
	ListNode* toLinkedList(std::vector<int>& vec) {
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

	void printLinkedList(ListNode* l) {
		if (l == nullptr)
			std::cout << "{}" << std::endl;
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

int test_24() {
	using namespace leetcode_24;
	Solution* solution = new Solution;
	ListNode* result;
	struct Test {
		std::vector<int> head;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{1,2,3,4}, {2,1,4,3}},
		{{1,2,3,4,5,6,7}, {2,1,4,3,6,5,7}},
		{{}, {}},
		{{1}, {1}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		ListNode* test_list = toLinkedList(test.head);
		printLinkedList(test_list);
		result = solution->swapPairs(test_list);
		std::cout << "result: ";
		printLinkedList(result);
		// if (result != test.expected) return 1;
	}
	return 0;
}