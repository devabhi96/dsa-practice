// Rotate List
// LeetCode 61. Rotate List
// Approach: Find length + tail, make it circular, then break at the new tail
//           (n - k % n - 1 steps from head)
// Time Complexity: O(n)
// Space Complexity: O(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }   

        int n = 1;
        ListNode* tail = head;
        while(tail ->next != nullptr){
            tail = tail->next;
            n++;
        }
        k = k%n;

        if(k == 0) return head;

        ListNode* newTail = head;
        for(int i =0; i<n-k-1; i++){
            newTail = newTail->next;
        }

        ListNode* newHead  = newTail->next;
        newTail ->next = nullptr;
        tail->next = head;

        return newHead;

    }
};