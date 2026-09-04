// Pairwise Swap Elements of a Linked List
// GeeksforGeeks: https://www.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
//
// Given a singly linked list, swap every pair of adjacent nodes in place
// (swap the nodes themselves, not just their data). If the list has an
// odd number of nodes, the last node is left untouched.
// e.g. 1->2->3->4 becomes 2->1->4->3
//
// Approach:
//   Walk the list two nodes at a time. For each pair (first, second),
//   rewire pointers so second comes before first, then link the previous
//   pair's tail to this pair's new head.
//
// Time:  O(n)  (single pass)
// Space: O(1)  (in-place, only a few pointers)

/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* pairwiseSwap(Node* head) {
       if(head == nullptr || head->next == nullptr){
           return head;
       }
       
       Node* newHead = head->next;
       Node* prev = nullptr;
       Node* curr = head;
       
       while(curr != nullptr && curr->next != nullptr){
            Node* first = curr;
            Node* second = curr->next;
            Node* nextPair = second->next;
            
            second->next = first;
            first->next  = nextPair;
            
            if(prev != nullptr){
                prev ->next  = second;
            }
            prev = first;
            curr = nextPair;
       }
       
       
       return newHead;
    }
};