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

namespace leetcode_25 {
	ListNode* Solution::reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k == 1) return head;

		int list_size = 0;
		ListNode* temp = head;
		while (temp != nullptr) {
			list_size++;
			temp = temp->next;
		}

		if (k > list_size) return nullptr;

		ListNode* dummy_head = new ListNode(0);
		dummy_head->next = head;
		ListNode* prev = dummy_head, * curr = dummy_head, * next = dummy_head;
		
		int remaining = list_size;
		while (curr->next && remaining >= k) {
			curr = prev->next;
			next = curr->next;

			for (int i = 1; i < k; i++) {
				curr->next = next->next;
				next->next = prev->next;
				prev->next = next;
				next = curr->next;
			}
			prev = curr;
			remaining -= k;
		}
		return dummy_head->next;
	}

	ListNode* Solution::myReverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k == 1) return head;
		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* next = nullptr;
		ListNode* ans = nullptr;
		std::vector<std::pair<ListNode*, ListNode*>> head_tail_pair;

		int i = 0;
		while (curr != nullptr) {
			// Check if there are sufficient nodes at the tail end of the list
			ListNode* aux = nullptr;
			int remaining = 0;
			aux = curr;
			while (aux != nullptr) {
				remaining++;
				aux = aux->next;
			}
			aux = prev;
			while (aux != nullptr) {
				remaining++;
				aux = aux->next;
			}
			if (remaining < k)
				break;

			// prev holds the reversed list
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;

			// If at the end of a k-group of nodes
			if ((i + 1) % k == 0) {
				if (!ans) ans = prev; // ans is set to the beginning of prev
				// advance to the tail of prev
				aux = prev;
				while (prev->next != nullptr)
					prev = prev->next;
				// store the head and tail of prev
				head_tail_pair.push_back(std::make_pair(aux, prev));
				prev = nullptr;
			}
			i++;
		}
		// re-links the slices of the list stored in the vector head_tail_pair
		if (head_tail_pair.empty()) return nullptr;
		int n = head_tail_pair.size();
		for (int i = 0; i < n - 1; i++) {
			ListNode* left_tail = head_tail_pair[i].second;
			ListNode* right_head = head_tail_pair[i + 1].first;
			left_tail->next = right_head;
		}
		// links, at the tail end, the remainder of the list (not reversed)
		ListNode* last_tail = head_tail_pair[n - 1].second;
		last_tail->next = next;
		return ans;
	}
}

/*std::cout << "\ni: " << i << std::endl;
std::cout << "remaining: " << remaining << std::endl;
std::cout << "prev: ";
printLinkedList(prev);
std::cout << "curr: ";
printLinkedList(curr);
std::cout << "next: ";
printLinkedList(next);
std::cout << "ans: ";
printLinkedList(ans);*/

namespace leetcode_25 {
	ListNode* vectorToLinkedList(std::vector<int>& vec) {
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

	std::vector<int> LinkedListToVector(ListNode* head) {
		if (head == nullptr) return {};
		std::vector<int> vec;
		ListNode* current = head;
		while (current != nullptr) {
			vec.push_back(current->val);
			current = current->next;
		}
		return vec;
	}
}

int test_25() {
	using namespace leetcode_25;
	Solution* solution = new Solution;
	ListNode* result;
	struct Test {
		std::vector<int> head;
		int k;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{1,2,3,4,5}, 1, {1,2,3,4,5}},
		{{1,2,3,4,5}, 2, {2,1,4,3,5}},
		{{1,2,3,4,5}, 3, {3,2,1,4,5}},
		{{1,2,3,4,5}, 4, {4,3,2,1,5}},
		{{1,2,3,4,5}, 5, {5,4,3,2,1}},
		{{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, 4, {}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		std::cout << "---------------------" << std::endl;
		ListNode* test_list = vectorToLinkedList(test.head);
		std::cout << "k: " << test.k << std::endl;
		printLinkedList(test_list);
		result = solution->reverseKGroup(test_list, test.k);
		printLinkedList(result);
		if (LinkedListToVector(result).size() != test.expected.size()) return 1;
	}
	return 0;
}