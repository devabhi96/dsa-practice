/*
 * Problem: Count Nodes in a Linked List
 * 
 * Given the head of a singly linked list, return the total number
 * of nodes present in the list.
 *
 * Approach:
 * Traverse the list from head to tail using a temporary pointer,
 * incrementing a counter for each node visited.
 *
 * Time Complexity : O(N) - single traversal of the list
 * Space Complexity: O(1) - only a pointer and counter are used
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
    int getCount(Node* head) {
        Node* temp = head;
        int length = 1;
        
        while(temp -> next != nullptr){
            length++;
            temp = temp->next;
        }
        return length;
    }
};