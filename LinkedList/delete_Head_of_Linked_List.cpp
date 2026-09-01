/*
 * Problem: Delete Head Node of a Linked List
 *
 * Given the head of a singly linked list, delete the head node and
 * return the new head.
 *
 * Approach:
 * Handle the empty list edge case first. Otherwise, simply move the
 * head pointer to the second node.
 *
 * Time Complexity : O(1) - constant time operation
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
    Node *deleteHead(Node *head) {
        if(head == nullptr){
            return head;
        }
        head = head->next;
        return head;
    }
};
