/*
    Approach: Forward and Backward Traversal of a Doubly Linked List

    - Traverse the doubly linked list from the head to the last node using
      the `next` pointer.
    - Store the data of each node in `ans1` to represent the list in
      forward order.
    - After reaching the last node, traverse backwards using the `prev`
      pointer.
    - Store the data of each node in `ans2` to represent the list in
      reverse order.
    - Return both vectors as a 2D vector, where:
        ans1 -> Forward traversal
        ans2 -> Backward traversal

    Time Complexity: O(n)
    Auxiliary Space: O(n)
*/
/* Structure of doubly linked list Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
    vector<vector<int>> displayList(Node *head) {
    
        vector<int> ans1;
        vector<int> ans2;
        Node* temp = head;
        while(temp->next != nullptr){
            ans1.push_back(temp->data);
            temp = temp->next;
        }
        ans1.push_back(temp->data);
        
        while(temp->prev != nullptr){
            ans2.push_back(temp->data);
            temp = temp->prev;
        }
        ans2.push_back(temp->data);
        
       return {ans1,ans2};
    }
};