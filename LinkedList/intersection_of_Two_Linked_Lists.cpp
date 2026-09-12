//Intersection of Two Linked Lists
// LeetCode 160. Intersection of Two Linked Lists
// Approach: Two pointers traverse both lists; when one hits the end,
//           redirect it to the other list's head. This equalizes the
//           distance traveled so both pointers meet at the intersection
//           (or both reach nullptr if there's no intersection).
// Time Complexity: O(m + n)
// Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode* pointerA = headA;
        ListNode* pointerB = headB;

        while (pointerA != pointerB) {

            if (pointerA == NULL) {
                pointerA = headB;
            } else {
                pointerA = pointerA->next;
            }

            if (pointerB == NULL) {
                pointerB = headA;
            } else {
                pointerB = pointerB->next;
            }
        }

        return pointerA;
    }
};