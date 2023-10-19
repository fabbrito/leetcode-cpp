#ifndef REMOVE_NTH_NODE_END_LINKED_LIST_H_INLCUDED
#define REMOVE_NTH_NODE_END_LINKED_LIST_H_INLCUDED

//19. Remove Nth Node From End of List
namespace leetcode_19 {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n);
        
    };
}

int test_19();

#endif