/*
 * Problem: Insert a Node at the End of a Linked List
 *
 * Given the head of a singly linked list and an integer x, insert a
 * new node with value x at the end of the list and return the new head.
 *
 * Approach:
 * Create the new node first. If the list is empty, the new node
 * becomes the head. Otherwise, traverse to the last node using a
 * temporary pointer and link it to the new node.
 *
 * Time Complexity : O(N) - traversal to reach the last node
 * Space Complexity: O(1) - excluding the newly allocated node
 */


/*
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
    Node *insertAtEnd(Node *head, int x) {
         
        Node* newNode = new Node(x);
           if (head == nullptr) {
                return newNode;
            }
              
        
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        
        return head;
    }
};