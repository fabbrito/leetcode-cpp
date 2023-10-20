#ifndef MERGE_K_SORTED_LISTS_H_INLCUDED
#define MERGE_K_SORTED_LISTS_H_INLCUDED

//23. Merge k Sorted Lists
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

int test_23();

#endif