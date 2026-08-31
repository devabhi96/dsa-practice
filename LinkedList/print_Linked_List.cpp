/*
 * Problem: Print/Traverse a Linked List
 *
 * Given the head of a singly linked list, return a vector containing
 * the data of all nodes in order from head to tail.
 *
 * Approach:
 * Traverse the list using a temporary pointer, pushing each node's
 * data into a result vector until the last node is reached (handled
 * separately since the loop stops one node early).
 *
 * Time Complexity : O(N) - single traversal of the list
 * Space Complexity: O(N) - to store the result vector
 */


/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> printList(Node *head) {
        vector<int> ans;
        Node* temp = head;
        
        while(temp->next != nullptr){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        ans.push_back(temp->data);
        return ans;
        
    }
};