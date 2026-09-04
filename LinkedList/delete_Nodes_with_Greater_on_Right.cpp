// Delete Nodes with Greater Value on Right
// GeeksforGeeks: https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
//
// Given a singly linked list, delete every node that has some node with a
// greater value anywhere to its right.
//
// Approach:
//   1. Reverse the list.
//   2. Scan left to right, tracking the max value seen so far. Delete any
//      node smaller than that max; otherwise it becomes the new max.
//   3. Reverse the list back to restore original order.
//
// Time:  O(n)  (three linear passes)
// Space: O(1)  (in-place, no extra data structures)

/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
  
  Node *reverse(Node* head){
      
       Node* prev = nullptr;
      Node* curr = head;
      
      while(curr != nullptr){
          Node* nextNode = curr->next;
          curr->next = prev;
          prev = curr;
          curr= nextNode;
      }
      return prev;
        
    
      
  }
  
    Node *compute(Node *head) {
     
        head = reverse(head);
        
        Node* curr = head;
        int maxVal = curr->data;
        while(curr->next != nullptr){
            if(curr->next->data < maxVal){
                Node* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            }
            else{
                curr = curr->next;
                maxVal = curr->data;
            }
        }
        head = reverse(head);
        return head;
    
    }
    
    
};