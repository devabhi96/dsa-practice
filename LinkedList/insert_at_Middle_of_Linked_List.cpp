/*
    Approach: Slow and Fast Pointer Technique

    - Handle the empty linked list separately by creating and returning
      a new node containing x.
    - Use two pointers, slow and fast, to find the correct middle position.
    - Initialize slow at the head and fast at the second node.
    - Move slow one step at a time and fast two steps at a time.
    - When fast reaches the end, slow points to the node after which
      the new node should be inserted.
    - Create a new node containing x.
    - Connect the new node to slow's next node.
    - Update slow's next pointer to point to the new node.
    - Return the original head of the linked list.

    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/
class Solution {
  public:
    Node *insertInMiddle(Node *head, int x) {


        if (head == nullptr) {
            return new Node(x);
        }

        Node* slow = head;
        Node* fast = head->next;

    
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newNode = new Node(x);

        newNode->next = slow->next;
        slow->next = newNode;

        return head;
    }
};