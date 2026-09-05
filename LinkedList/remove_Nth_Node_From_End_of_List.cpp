// Remove Nth Node From End of List
// LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
// Given the head of a linked list, remove the nth node from the end of
// the list and return the head of the modified list.
// e.g. head = 1->2->3->4->5, n = 2 -> result = 1->2->3->5
//
// Approach:
//   Two-pass approach. First pass counts total nodes (cnt). This gives
//   the target node's position from the head: ans = cnt - n (1-indexed
//   position of the node just BEFORE the one to delete). Handle two
//   special cases separately: (1) n == 1, i.e. removing the last node,
//   including the edge case of a single-node list; (2) ans == 0, i.e.
//   the node to delete is the head itself, which has no predecessor.
//   Otherwise, walk to the predecessor node and skip over the target.
//
// Time:  O(n)  (two linear passes)
// Space: O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* temp1 = head;
        int cnt =0;

        while(temp1 != nullptr){
            temp1 = temp1->next;
            cnt++;
        }

        temp1 = head;
        int ans = cnt-n;
        int pnt =1;

        if(n == 1){
            if(temp1->next == nullptr){
                return nullptr;
            }

            while(temp1->next->next != nullptr){
                temp1 = temp1->next;
            }
            temp1->next = nullptr;
            return head;
        }
        if(ans == 0){
            return head->next;
        }



        while(temp1 != nullptr){
                if(pnt == ans && temp1->next != nullptr){
                    temp1->next = temp1->next->next;
                }
                temp1 = temp1->next;
                pnt++;
        }
        return head;
    }
};