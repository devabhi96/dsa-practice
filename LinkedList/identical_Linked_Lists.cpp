/*
    Approach: Two-Pointer Traversal

    - Use two temporary pointers to traverse both linked lists simultaneously.
    - Compare the data of the corresponding nodes at each position.
    - If any pair of nodes contains different data, the linked lists are not
      identical, so return false immediately.
    - Move both pointers to their next nodes after each comparison.
    - After traversal, check that both pointers reached nullptr.
      This ensures that both linked lists have the same length as well as
      the same values in the same order.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

/* Strucutre of a Node in linked list
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
    bool areIdentical(Node *head1, Node *head2) {
        struct Node* temp = head1;
    struct Node* temp2 = head2;
    
    while(temp != nullptr && temp2 != nullptr){
        if(temp->data != temp2->data ){
            return false;
        }
        temp = temp->next;
        temp2= temp2->next;
    }
    return (temp == nullptr && temp2 == nullptr);
        
    }
};