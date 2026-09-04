/*
    Approach: Traverse the Linked List and Check for a Return to Head

    - Handle the empty linked list separately. An empty list is considered
      circular, so return true.
    - Start traversal from `head->next` because `temp` should move through
      the list and eventually either return to `head` or reach `nullptr`.
    - Continue traversing while `temp` is neither `head` nor `nullptr`.
    - If `temp` becomes `head`, the linked list forms a cycle back to its
      starting node and is therefore circular.
    - If `temp` becomes `nullptr`, the list reaches its end and is not circular.
    - Finally, return whether `temp` is equal to `head`.

    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    bool isCircular(Node *head) {
       
       if(head == nullptr){
           return true;
       }
       
       
       Node* temp = head->next;
       while(temp != head && temp != nullptr){
           temp = temp->next;
       }
       return temp == head;
        
    }
};