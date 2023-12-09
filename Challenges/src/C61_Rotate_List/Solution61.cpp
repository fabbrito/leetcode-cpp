#include "pch.h"
#include "Solution61.h"

namespace leetcode_61 {
	using namespace std;
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* to_linked_list(const vector<int>& vec) {
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

	void print_linked_list(ListNode* list) {
		ListNode* current = list;
		cout << "| ";
		while (current != nullptr) {
			if (current->next != nullptr)
				cout << current->val << " -> ";
			else
				cout << current->val;
			current = current->next;
		}
		cout << " |\r\n";
		current = nullptr;
		delete current;
	}

	class Solution;
}

class leetcode_61::Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		auto iter = head;
		auto length = 1;
		while (iter->next != nullptr) {
			iter = iter->next; ++length;
		}
		// close the list (create a ring)
		iter->next = head;
		iter = head;
		// find one element before the new head
		for (int i = 0; i < length - (k % length) - 1; ++i) {
			iter = iter->next;
		}
		head = iter->next;
		// open the list (break the ring)
		iter->next = nullptr;
		return head;
	}
};

int test_61() {
	using namespace leetcode_61;
	struct Test {
		vector<int> list;
		int k;
		vector<int> expected;
	};
	vector<Test> tests = {
		{{1,2,3,4,5},2,{4,5,1,2,3}},
		{{0,1,2},4,{2,0,1}},
		{{1},4,{1}},
		{{},4,{}},
	};

	cout << "----------------- Testing Solution -----------------\r\n";
	for (auto& test : tests) {
		Solution solution;
		ListNode* head = to_linked_list(test.list);
		print_linked_list(head);
		ListNode* result = solution.rotateRight(head, test.k);
		print_linked_list(result);
		cout << "\r\n";
		head = nullptr, result = nullptr;
		delete head, delete result;
	}
	return 0;
}
