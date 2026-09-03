/*
    Approach: Traverse the Linked List and Count Nodes

    - Initialize a counter to 1 because the given head represents the
      first node of the linked list.
    - Traverse the linked list until the last node is reached.
    - Increment the counter for every additional node encountered.
    - After traversal, check whether the total number of nodes is even.
    - If the count is divisible by 2, return true; otherwise, return false.

    Note:
    - This solution assumes the linked list contains at least one node.

    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/
/* Structure of link list node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class Solution {
  public:
    bool isEven(Node* head) {
        int cnt =1;
        Node* temp = head;
        while(temp->next != nullptr){
            cnt++;
            temp = temp->next;
        }
        if(cnt %2 == 0){
            return true;
        }   
        return false;
    }
};