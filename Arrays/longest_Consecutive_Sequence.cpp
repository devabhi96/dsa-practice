/*
 * LeetCode 128 - Longest Consecutive Sequence
 * Approach: Hashing with Set (O(n))
 * - Insert all elements into an unordered_set for O(1) lookup.
 * - For each number, check if it's the start of a sequence (num-1 not in set).
 * - If yes, expand forward (num+1, num+2, ...) and track streak length.
 * - Track the max streak length across all starts.
 * Time: O(n) | Space: O(n)
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int length = 0;

            for(int i: st){

                    if(st.find(i - 1) == st.end()){
                        int curri = i;
                        int currlen = 1; 

                        while(st.find(curri +1 ) != st.end()){
                            curri++;
                            currlen++;
                        }
                        length = max(length,currlen);
                    }

            }
            return length;
    }
};