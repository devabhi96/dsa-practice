// Remove Duplicates from Sorted List II
// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
//
// Given the head of a sorted linked list, delete all nodes that have
// duplicate values, leaving only distinct numbers from the original list.
// e.g. head = 1->1->2->3->3 -> result = 2
//      head = 1->2->3->3->4->4->5 -> result = 1->2->5
//
// Approach:
//   Use a dummy head so the actual head can be removed if it's part of a
//   duplicate run. Walk the list with `temp`; for each value, an inner
//   loop advances `temp` through the entire run of matching values and
//   sets a flag if more than one node shared that value. If a duplicate
//   run was found, splice it out entirely via prev->next; otherwise the
//   node is unique, so prev catches up to it. `temp` always advances at
//   the end of the outer loop, guaranteeing forward progress.
//
// Time:  O(n)  (single pass)
// Space: O(1)  (excluding the dummy node)
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp != nullptr) {
            bool flag = false;

            while (temp->next != nullptr && temp->val == temp->next->val) {
                flag = true;
                temp = temp->next;
            }

            if (flag == true) {
                prev->next = temp->next;
            } else {
                prev = temp;
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};