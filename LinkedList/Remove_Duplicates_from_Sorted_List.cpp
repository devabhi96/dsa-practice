// Remove Duplicates from Sorted List
// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//
// Given the head of a sorted linked list, delete all duplicates such that
// each element appears only once, and return the modified sorted list.
// e.g. head = 1->1->2->3->3 -> result = 1->2->3
//
// Approach:
//   Single pointer walk. Since the list is already sorted, duplicates are
//   always adjacent, so only neighboring nodes need to be compared. If the
//   current node's value matches the next node's value, splice the next
//   node out (skip it). Only advance the pointer when no duplicate was
//   found, so runs of 3+ identical values are fully collapsed to one.
//
// Time:  O(n)  (single pass)
// Space: O(1)  (in-place, no extra data structures)
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
        struct ListNode* temp = head;

        while(temp != nullptr && temp->next != nullptr){
            if(temp->val == temp->next->val){
                temp->next = temp->next->next;
            }
            else{

            
            temp =temp->next;
        }}

        return head;
    }
};