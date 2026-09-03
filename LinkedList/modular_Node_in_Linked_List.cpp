/*
    Approach: Traverse the Linked List and Track the Last Modular Node

    - Traverse the linked list using a temporary pointer.
    - Maintain a counter starting from 1 to represent the position of
      each node in the linked list.
    - For every node, check whether its position is divisible by k.
    - Whenever the position is a multiple of k, store that node's data
      in `lastpos`.
    - Continue traversing so that `lastpos` always contains the data of
      the latest node whose position is divisible by k.
    - If no such position exists, `lastpos` remains -1.
    - Return `lastpos` after completing the traversal.

    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

/*Struture of the node of the linked list is as:

struct Node {
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
    int modularNode(Node *head, int k) {
       Node* temp = head;
        int lastpos =-1;
        int cnt =1;
        while(temp != nullptr){
            if(cnt % k == 0){
                lastpos = temp->data;
            }
            cnt++;
            temp = temp->next;
        }
       
        return lastpos;
    }
};