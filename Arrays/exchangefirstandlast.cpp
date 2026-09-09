//Exchange first and last nodes in singly linked list



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void swapFirstLast(Node*& head) {
    // Empty list or only one node
    if (head == nullptr || head->next == nullptr)
        return;

    Node* first = head;
    Node* prevLast = nullptr;
    Node* last = head;

    // Find the last node and its previous node
    while (last->next != nullptr) {
        prevLast = last;
        last = last->next;
    }

    // Make last node the new head
    last->next = first->next;

    // Previous last node points to first
    prevLast->next = first;

    // First node becomes the last node
    first->next = nullptr;

    head = last;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before: ";
    printList(head);

    swapFirstLast(head);

    cout << "\nAfter: ";
    printList(head);

    return 0;
}