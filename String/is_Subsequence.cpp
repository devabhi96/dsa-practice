/**
 * LeetCode 392 - Is Subsequence
 * --------------------------------
 * Checks whether string `s` is a subsequence of string `t`
 * (i.e., `s` can be formed by deleting some characters from `t`
 * without reordering the remaining ones).
 *
 * Approach: Two-pointer greedy matching.
 *   - Walk through `t` with index `i`.
 *   - Advance pointer `j` on `s` whenever characters match.
 *   - If `j` reaches the length of `s`, every character of `s`
 *     was matched in order, so `s` is a subsequence of `t`.
 *
 * Time Complexity:  O(n) where n = length of t
 * Space Complexity: O(1)
 */ 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j =0;
        int n1 = s.length();
        
        for(int i =0; i<t.length(); i++){
            if( s[j] ==  t[i] && j<n1){
                j++;
            }
        }

        if(j == n1 ){
            return true;
        }
        return false;
    }
};