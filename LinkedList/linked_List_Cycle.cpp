//Linked List Cycle
// LeetCode 141. Linked List Cycle
// Approach: Floyd's Cycle Detection (slow & fast pointers)
//           If a cycle exists, fast will eventually meet slow.
// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
     ListNode* slow = head;
     ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }

return false;

    }
};