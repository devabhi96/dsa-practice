// Add Two Numbers
// LeetCode: https://leetcode.com/problems/add-two-numbers/
//
// Given two non-empty linked lists representing two non-negative integers
// in reverse order (least significant digit first), add the two numbers
// and return the sum as a linked list in the same reverse-order format.
// e.g. l1 = 2->4->3 (342), l2 = 5->6->4 (465) -> result = 7->0->8 (807)
//
// Approach:
//   Walk both lists in tandem, digit by digit, tracking a carry. If one
//   list runs out before the other, treat its missing digit as 0 and
//   keep going. Build a brand-new result list via a dummy head instead
//   of mutating either input list. Keep looping as long as either list
//   still has nodes or there's a leftover carry to place.
//
// Time:  O(max(m, n))  where m, n are the lengths of l1 and l2
// Space: O(max(m, n))  for the newly created result list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int left = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (temp1 != nullptr || temp2 != nullptr || left != 0) {
            int val1 = 0;
            if (temp1 != nullptr) {
                val1 = temp1->val;
            }

            int val2 = 0;
            if (temp2 != nullptr) {
                val2 = temp2->val;
            }

            int sum = val1 + val2 + left;
            left = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (temp1 != nullptr) {
                temp1 = temp1->next;
            }
            if (temp2 != nullptr) {
                temp2 = temp2->next;
            }
        }

        return dummy->next;
    }
};