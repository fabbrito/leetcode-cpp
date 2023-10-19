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
namespace leetcode_19 {
	ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
		ListNode* curr = head;

		// calculate the size of the linked list
		int sz = 0;
		while (curr != nullptr) {
			sz++;
			curr = curr->next;
		}

		curr = head;
		int pos = sz - n;
		int i = 0;
		ListNode* ans = nullptr;
		while (curr != nullptr) {
			if (i != pos && ans == nullptr)
				ans = curr;
			if (i == pos - 1 && curr->next != nullptr)
				curr->next = curr->next->next;
			i++;
			curr = curr->next;
		}
		return ans;
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

int test_19() {
	using namespace leetcode_19;
	Solution* solution = new Solution;
	ListNode* result;
	struct Test {
		std::vector<int> head_vector;
		int n;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
		{{0,1,2,3,4,5,6,7,8,9,10}, 11, {1,2,3,4,5,6,7,8,9,10}},
		{{1}, 1, {}},
		{{1, 2}, 1, {1}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		ListNode* list = to_linked_list(test.head_vector);
		print_linked_list(list);
		result = solution->removeNthFromEnd(list, test.n);
		std::cout << "n: " << test.n << std::endl;
		print_linked_list(result);
		// if (result != test.expected) return 1;
	}
	return 0;
}