/*
 * Problem: Remove Duplicates from an Unsorted Linked List
 * ----------------------------------------------------------
 * Given the head of a singly linked list (not necessarily sorted),
 * remove all duplicate-valued nodes so that each distinct value
 * appears only once, preserving the order of first occurrence.
 *
 * Approach:
 *   Traverse the list with a `prev`/`temp` pair while maintaining an
 *   unordered_set of values already seen. If temp's value is a
 *   duplicate, unlink it via prev->next; otherwise record its value
 *   and advance both pointers.
 *
 * Time Complexity:  O(n)  -- single pass, O(1) average set operations
 * Space Complexity: O(n)  -- extra space for the hash set
 */
/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        unordered_set<int> st;

        Node* prev = nullptr;
        Node* temp = head;

        while (temp != nullptr) {
            if (st.find(temp->data) != st.end()) {
                // duplicate: unlink temp from the list
                prev->next = temp->next;
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            } else {
                st.insert(temp->data);
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};