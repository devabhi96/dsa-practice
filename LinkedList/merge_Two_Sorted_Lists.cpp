// Merge Two Sorted Lists
// LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/
//
// Given two sorted linked lists, merge them into one sorted list by
// splicing together the nodes of the two input lists (no new nodes
// allocated for values).
// e.g. l1 = 1->2->4, l2 = 1->3->4 -> result = 1->1->2->3->4->4
//
// Approach:
//   Classic two-pointer merge (same idea as the merge step in merge sort).
//   Use a dummy head to simplify building the result list. At each step,
//   compare the current heads of l1 and l2, attach the smaller (or l1 on
//   ties) to the result, and advance that list's pointer. Once one list
//   is exhausted, the other is already sorted, so attach it wholesale.
//
// Time:  O(m + n)  where m, n are the lengths of l1 and l2
// Space: O(1)  extra (result reuses existing nodes, aside from the dummy)
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if(l1->val > l2->val){
            current->next = l2;
            l2 = l2->next;
        }
        else if(l1->val <= l2->val){
            current->next = l1;
            l1 = l1->next;
        }
        current = current->next;

        
    }
    if (l1 != nullptr) {
    current->next = l1;
} else {
    current->next = l2;
}

    // one list may still have leftover nodes — what do you do with them?

    return dummy->next;
}
};