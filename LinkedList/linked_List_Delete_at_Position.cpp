/*
 * Problem: Delete a Node at a Given Position in a Linked List
 *
 * Given the head of a singly linked list and a 1-based position x,
 * delete the node at that position and return the new head.
 *
 * Approach:
 * Handle the empty list case first. If x is 1, delete the head
 * directly. Otherwise, traverse to the node just before the target
 * position, then bypass the target node by relinking pointers.
 *
 * Time Complexity : O(N) - traversal to reach the target position
 * Space Complexity: O(1) - no extra space used
 */



/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
       int cnt =1;
       
       if(head == nullptr){
           return head;
       }
       
       if (x == 1) {
           Node* toDelete = head;
           head = head->next;
           delete toDelete;
           return head;
       }
       
       
       Node* temp = head;
       while(cnt != x-1){
           temp = temp->next;
           cnt++;
       }
       
       temp->next = temp->next->next;
       return head;
        
    }
};