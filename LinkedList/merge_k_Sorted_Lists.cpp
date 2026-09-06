/**
 * LeetCode 23 - Merge k Sorted Lists
 * https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * Approach: Brute Force (Linear Scan)
 * -------------------------------------
 * Maintain a "current pointer" for each of the k lists inside the `lists`
 * array itself. On every iteration, scan all k pointers to find the
 * smallest current value, attach that node to the result list, and
 * advance that list's pointer to its next node. Repeat until all
 * pointers are null.
 *
 * Time Complexity:  O(N * k)
 *   - N = total number of nodes across all lists
 *   - k = number of lists
 *   - For each of the N nodes placed into the result, we scan up to k
 *     lists to find the minimum.
 *
 * Space Complexity: O(1) extra (excluding the output list)
 *   - Only a dummy node and a few pointers/ints are used;
 *     `lists` is reused in place as the "current pointer" tracker.
 *
 * Note: Not optimal for large k. A min-heap or divide-and-conquer merge
 * reduces this to O(N log k). Kept here as the baseline/brute-force
 * solution for clarity.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(true){
            int minval = INT_MAX;
            int minidx = -1;

            for(int i =0; i<lists.size(); i++){
                if(lists[i] != nullptr && lists[i]->val<minval){
                    minval = lists[i]->val;
                    minidx = i;
                }
            }
            if(minidx == -1) break;
            tail->next = lists[minidx];
            tail = tail->next;

            lists[minidx] = lists[minidx]->next;
        }
return dummy.next;
    }
};