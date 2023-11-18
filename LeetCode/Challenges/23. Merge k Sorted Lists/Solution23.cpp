#include "pch.h"
#include "Solution23.h"

namespace leetcode_23 {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	ListNode* toLinkedList(std::vector<int>& vec);
	void printLinkedList(ListNode* l);

	class CompareLists {
	public:
		bool operator()(ListNode* a, ListNode* b);
	};

	class Solution {
	public:
		ListNode* mergeKLists(std::vector<ListNode*>& lists);
		ListNode* mergeKLists2(std::vector<ListNode*>& lists);
	};
}

namespace leetcode_23 {

	ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
		// Creates a priority_queue with all the elements from all the lists
		// using the priority function greater<int>, which means the pq.top()
		// is the smallest element in the queue
		std::priority_queue<int, std::vector<int>, std::greater<int>>pq;
		int n = lists.size();
		for (int i = 0; i < n; i++) {
			ListNode* curr = lists[i];
			while (curr != NULL) {
				pq.push(curr->val);
				curr = curr->next;
			}
		}
		// Constructs a new list with the elements from pq
		ListNode* head = new ListNode(-1);
		ListNode* curr = head;
		while (!pq.empty()) {
			ListNode* node = new ListNode(pq.top());
			pq.pop();
			curr->next = node;
			curr = node;
		}
		return head->next;
	}
}

namespace leetcode_23 {
	bool CompareLists::operator()(ListNode* a, ListNode* b) {
		return (a->val > b->val);
	}

	ListNode* Solution::mergeKLists2(std::vector<ListNode*>& lists) {
		// Creates a priority_queue with the lists using the priority function
		// defined by CompareLists, which means that pq.top() retrieves the
		// list with the smallest current element in the queue
		std::priority_queue<ListNode*, std::vector<ListNode*>, CompareLists>pq;
		for (auto& l : lists) {
			if (l) pq.push(l);
		}
		// Constructs a new list with the elements from pq
		ListNode* head = new ListNode(-1);
		ListNode* curr = head;
		while (!pq.empty()) {
			ListNode* top_node = pq.top();
			pq.pop();
			curr->next = top_node;
			curr = top_node;
			if (top_node && top_node->next) {
				pq.push(top_node->next);
			}
		}
		return head->next;
	}
}

namespace leetcode_23 {
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

int test_23() {
	using namespace leetcode_23;
	Solution solution;
	struct Test {
		std::vector<std::vector<int>> lists;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{{1,2,4}, {1,3,4}}, {1,1,2,3,4,4}},
		{{{1,4,5}, {1,3,4}, {2,6}}, {1,1,2,3,4,4,5,6}},
		{{}, {}},
		{{{}}, {}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		std::vector<ListNode*> test_lists;
		for (auto& elem : test.lists) {
			ListNode* test_list = toLinkedList(elem);
			printLinkedList(test_list);
			test_lists.push_back(test_list);
		}
		ListNode* result = solution.mergeKLists(test_lists);
		std::cout << "result: ";
		printLinkedList(result);
		// if (result != test.expected) return 1;
		delete result;
	}
	return 0;
}
