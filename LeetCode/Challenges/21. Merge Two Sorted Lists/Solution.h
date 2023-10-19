#ifndef MERGE_TWO_SORTED_LISTS_H_INLCUDED
#define MERGE_TWO_SORTED_LISTS_H_INLCUDED

//21. Merge Two Sorted Lists
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
    };
}

int test_21();

#endif