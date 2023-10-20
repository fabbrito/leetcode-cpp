#ifndef SWAP_NODES_IN_PAIRS_H_INLCUDED
#define SWAP_NODES_IN_PAIRS_H_INLCUDED

//24. Swap Nodes in Pairs
namespace leetcode_24 {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* toLinkedList(std::vector<int>& vec);
    void printLinkedList(ListNode* l);

    class Solution {
    public:
        ListNode* swapPairs(ListNode* head);
    };
}

int test_24();

#endif