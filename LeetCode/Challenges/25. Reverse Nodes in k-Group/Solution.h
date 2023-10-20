#ifndef REVERSE_NODES_IN_K_GROUPS_H_INLCUDED
#define REVERSE_NODES_IN_K_GROUPS_H_INLCUDED

//25. Reverse Nodes in k-Group
namespace leetcode_25 {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* vectorToLinkedList(std::vector<int>& vec);
    std::vector<int> LinkedListToVector(ListNode* head);
    void printLinkedList(ListNode* l);

    class Solution {
    public:
        ListNode* myReverseKGroup(ListNode* head, int k);
        ListNode* reverseKGroup(ListNode* head, int k);
    };
}

int test_25();

#endif