#include "pch.h"
#include "Solution21.h"

namespace leetcode_21 {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* to_linked_list(std::vector<int>& vec);
	void print_linked_list(ListNode* l);

	class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
		ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2);
	};
}

namespace leetcode_21 {
	ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
		if (!a || b && a->val > b->val) std::swap(a, b);
		if (a) a->next = mergeTwoLists(a->next, b);
		return a;
	}

	ListNode* Solution::mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
		if (!list1) return list2;
		if (!list2) return list1;

		ListNode* head_s = nullptr;
		ListNode* head_g = nullptr;

		if (list1->val > list2->val) {
			head_g = list1;
			head_s = list2;
		}
		else {
			head_g = list2;
			head_s = list1;
		}

		ListNode* ans = head_s;
		ListNode* curr = nullptr;
		while (head_s != nullptr || head_g != nullptr) {
			if (curr == nullptr) {
				curr = head_s;
				head_s = head_s->next;
			}
			if (head_s != nullptr && head_g != nullptr) {
				if (head_s->val < head_g->val) {
					curr->next = head_s;
					curr = head_s;
					head_s = head_s->next;
				}
				else {
					curr->next = head_g;
					curr = head_g;
					head_g = head_g->next;
				}
			}
			else if (head_s == nullptr) {
				curr->next = head_g;
				curr = head_g;
				head_g = head_g->next;
			}
			else {
				curr->next = head_s;
				curr = head_s;
				head_s = head_s->next;
			}
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

int test_21() {
	using namespace leetcode_21;
	Solution solution;
	struct Test {
		std::vector<int> list1;
		std::vector<int> list2;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{1,2,4}, {1,3,4}, {1,1,2,3,4,4}},
		{{-10,-5,0,0,0,0,0,0,0,0,0,0,0,5,10}, {-10,-1,1,10}, {}},
		{{}, {}, {}},
		{{}, {0}, {0}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		ListNode* list1 = to_linked_list(test.list1);
		ListNode* list2 = to_linked_list(test.list2);
		print_linked_list(list1);
		print_linked_list(list2);
		ListNode* result = solution.mergeTwoLists(list1, list2);
		print_linked_list(result);
		// if (result != test.expected) return 1;
		delete list1, delete list2, delete result;
	}
	return 0;
}