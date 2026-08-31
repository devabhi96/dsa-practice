/*
 * Problem: Search for a Key in a Linked List
 *
 * Given the head of a singly linked list and an integer key, determine
 * whether the key exists among the node values in the list.
 *
 * Approach:
 * Traverse the list using a temporary pointer, comparing each node's
 * data against the key. The last node is checked separately after the
 * loop since the loop condition stops one node early.
 *
 * Time Complexity : O(N) - single traversal of the list in the worst case
 * Space Complexity: O(1) - only a pointer is used
 */

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
       Node* temp = head;
       
       while(temp->next != nullptr){
           if(temp->data == key){
               return true;
           }
           temp= temp->next;
       }
       
         if(temp->data == key){
               return true;
           }
       
       
       return false;
    }
};
