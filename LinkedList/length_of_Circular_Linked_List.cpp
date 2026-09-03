/*
    Approach: Traverse the Circular Linked List

    - Initialize a counter `cnt` to 0 and a temporary pointer `temp`
      to the head of the circular linked list.
    - Use a `do-while` loop because the head node must be processed
      at least once.
    - Increment the counter for every node visited.
    - Move `temp` to the next node after processing each node.
    - Stop the traversal when `temp` reaches the head again, which
      indicates that all nodes in the circular linked list have been
      visited exactly once.
    - Return the total number of nodes.

    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

/* Linked List Node Structure
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
    int getLength(Node *head) {
       int cnt = 0;
       Node* temp = head;
       
       do{
           cnt++;
           temp =temp->next;
       }
       while(temp != head);
        
        return cnt;
    }
};