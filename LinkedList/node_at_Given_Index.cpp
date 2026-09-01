/*
 * Problem: Find Node at a Given Index in a Linked List
 *
 * Given the head of a singly linked list and an index k (assumed
 * 1-based here), return the data value at that index, or -1 if the
 * index is out of bounds.
 *
 * Approach:
 * Handle the empty list case first. Traverse the list one step at a
 * time, stopping either when the target position is reached or when
 * the list runs out — whichever comes first — to safely handle
 * out-of-range k.
 *
 * Time Complexity : O(N) - traversal up to position k or list end
 * Space Complexity: O(1) - no extra space used
 */

/* Node Structure
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    int getNode(Node* head, int k) {
    int cnt =1;
    
    if(head == nullptr){
        return -1;
    }
    
    Node* temp = head;
    
    while(cnt != k && temp != nullptr ){
        temp = temp->next;
        cnt++;
    }
    int ans = -1;
    if(temp != nullptr){
        ans = temp->data;
    }
    
    
    
    return ans;
        
    }
};