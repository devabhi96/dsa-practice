/*
 * Problem: Kth Node from the End of a Linked List
 * 
 * Given the head of a singly linked list and an integer k, 
 * find the value of the k-th node from the end of the list.
 * If k is invalid (<= 0 or greater than the length of the list), return -1.
 *
 * Approach:
 * 1. Traverse the list once to compute its total length (cnt).
 * 2. Validate k against the length.
 * 3. Compute the position from the start: (total - k + 1).
 * 4. Traverse again to that position and return its data.
 *
 * Time Complexity: O(N) - two passes through the list
 * Space Complexity: O(1)
 */


/* Structure of Linked List Node
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
    int getKthFromLast(Node* head, int k) {
        
        int cnt =1;
        if(head == nullptr){
            return -1;
        }
        
        Node* temp = head;
        while(temp->next != nullptr){
            cnt++;
            temp = temp->next;
        }
        
        if(k <= 0 || k > cnt){
            return -1;
        }
    
        int total = cnt;
        cnt =1 ;
        Node* temptwo = head;
        while(cnt != (total-k+1)){
            cnt++;
            temptwo = temptwo->next;
        }
        return temptwo ->data;
           
        
        
        
     
        
    }
};