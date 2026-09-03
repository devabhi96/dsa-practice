/*
 * Problem: Remove Duplicates from Sorted Linked List
 * ----------------------------------------------------
 * Given the head of a sorted (non-decreasing) singly linked list,
 * remove all duplicate nodes such that each distinct value appears
 * only once. The list must remain sorted.
 *
 * Approach:
 *   Traverse the list with a single pointer `temp`. If the current
 *   node's value equals the next node's value, skip the next node
 *   by relinking `temp->next`. Otherwise, advance `temp`.
 *
 * Time Complexity:  O(n)  -- single pass through the list
 * Space Complexity: O(1)  -- in-place, no extra data structures
 */

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        Node* temp = head;
        
        while(temp != nullptr && temp->next != nullptr){
            if(temp->data == temp->next ->data){
                temp->next = temp->next->next;
            }
            else{
            temp = temp->next;
        }}
        return head;
    }
};