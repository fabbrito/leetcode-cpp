#include "pch.h"
#include "Solution82.h"

namespace leetcode_82 {

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

static ListNode* to_linked_list(std::vector<int>& vec) {
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

static void print_linked_list(ListNode* l) {
	if (l == nullptr)
		std::cout << "nullptr" << std::endl;
	ListNode* current = l;
	while (current != nullptr) {
		if (current->next != nullptr)
			std::cout << current->val << " -> ";
		else
			std::cout << current->val << std::endl;
		current = current->next;
	}
}

static void destroy_linked_list(ListNode* l) {
	while (l) {
		ListNode* tmp = l;
		l = tmp->next;
		delete(tmp);
	}
}

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		ListNode* prev = nullptr, * curr = head, * next = curr->next;
		while (next) {
			if (curr->val == next->val) {
				// 'next' holds the position of the next element that's different in value from 'curr'
				while (next && next->val == curr->val) {
					next = next->next;
				}
				if (!prev) { // This condition means element at the head is repeating. So, head pointer needs to be shifted.
					head = next;
				}
				else { // stitches the list, skipping repeated elements 
					prev->next = next;
				}
			}
			else {
				prev = curr;
			}

			// advance 'curr' and 'next'
			curr = next;
			if (next) {
				next = curr->next;
			}
		}
		return head;
	}
};
}

int test_82() {
	using namespace leetcode_82;
	struct test_t {
		vector<int> head;
		vector<int> expected;
	};
	vector<test_t> tests = {
		// \[(([0-9]*,*)+)\] -> {$1} regex to change from [1,2,3] to {1,2,3}
		// \[((("[A-Za-z]")*,*)+)\] -> {$1} regex to change from ["A","B","C"] to {"A","B","C"}
		{{1,2,3,3,4,4,5},{1,2,5}},
		{{1,1,1,2,3},{2,3}},
		{{},{}},
		{{1},{1}},
		{{1,1,2,2,3,3},{}},
	};

	std::cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		ListNode* head = to_linked_list(test.head);
		print_linked_list(head);
		ListNode* result = solution.deleteDuplicates(head);
		print_linked_list(result);
		std::cout << "\r\n";

		destroy_linked_list(head);
		result = nullptr;
		delete result;
	}

	return 0;
}
