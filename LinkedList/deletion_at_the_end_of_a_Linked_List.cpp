/*
 * Problem: Remove the Last Node of a Linked List
 *
 * Given the head of a singly linked list, delete the last node and
 * return the new head.
 *
 * Approach:
 * Handle the empty list and single-node list cases separately.
 * Otherwise, traverse to the second-to-last node and set its next
 * pointer to nullptr to drop the last node.
 *
 * Time Complexity : O(N) - single traversal of the list
 * Space Complexity: O(1) - no extra space used
 */

/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        
        if(head == nullptr){
            return head;
        }
        
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }
        
        Node* temp = head;
        
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        
        temp->next = nullptr;
        return head;
    }
};