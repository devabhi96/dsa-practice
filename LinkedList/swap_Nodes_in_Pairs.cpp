/**
 * LeetCode 24 - Swap Nodes in Pairs
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Approach: Iterative Pointer Swap (in-place, no dummy node)
 * -------------------------------------------------------------
 * Walk the list two nodes at a time. For each pair (temp, second):
 *   - Save `second` before rewiring, so it isn't lost.
 *   - Point `temp->next` past the pair (to what comes after `second`).
 *   - Point `second->next` back to `temp` (completes the swap).
 *   - Reconnect the previous pair's tail (`prev`) to `second`,
 *     the new front of this pair.
 * `newHead` is captured once up front, since the second node of the
 * first pair becomes the new head of the whole list.
 *
 * Time Complexity:  O(N) - each node visited once
 * Space Complexity: O(1) extra - only a few pointers, in-place rewiring
 *
 * Handles empty list and odd-length list (last unpaired node untouched)
 * via the initial null check and the while-loop condition.
 */

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
       
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* newHead = head->next;

        while(temp != nullptr && temp->next != nullptr ){
            ListNode* second = temp->next;
            
            temp->next = second->next;
            second->next = temp;

             if(prev != nullptr){
                prev->next = second;
            }
            prev = temp;
            temp = temp->next;
        }
return newHead;
    }
};