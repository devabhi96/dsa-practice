/*
    Approach: Two-Pass Traversal with Node Count

    - Traverse the linked list once to calculate the total number of nodes.
    - Determine the middle position based on the total number of nodes.
    - For an even number of nodes, select the first middle node.
    - For an odd number of nodes, select the exact middle node.
    - Reset the temporary pointer to the head and traverse the list again.
    - When the counter reaches the calculated middle position, return
      the data stored in that node.
    - Return -1 if the middle node cannot be found.

    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
       Node* temp = head;
       int cnt =1;
       while(temp != nullptr){
           temp = temp->next;
           cnt++;
       }
       
       int mid;
        if(cnt%2 == 0){
            mid = cnt/2;
        }
        else{
            mid = cnt/2 +1;
        }
        cnt = 1;
        temp =head;
        while(temp != nullptr){
            if(cnt == mid){
                return temp->data;
            }
            cnt++;
            temp = temp->next;
        }
        return -1;
    }
};