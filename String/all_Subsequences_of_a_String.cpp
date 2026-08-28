/*
 * All Subsequences of a String (Power Set of a String)
 * Difficulty: Medium
 *
 * Given a string s, generate all possible subsequences of the string
 * (including the empty subsequence) and return them in lexicographical
 * order. Duplicate subsequences (from repeated characters) are kept,
 * not removed.
 *
 * Approach: Bitmasking
 * - Each subsequence corresponds to a binary mask of length n, where
 *   bit i decides whether s[i] is included (1) or skipped (0)
 * - Iterate mask from 0 to 2^n - 1 to cover every include/skip
 *   combination, building each subsequence in original character order
 * - Sort the resulting list to get lexicographic order
 *
 * Time Complexity:  O(2^n * n) to generate + O(2^n * log(2^n) * n) to sort
 * Space Complexity: O(2^n * n) to store all subsequences
 *
 * Constraints: 1 <= n <= 16
 */
class Solution {
  public:
    vector<string> powerSet(string &s) {
        int n = s.size();
        int total = 1 <<n;
        vector<string> result;
        
        for(int mask = 0; mask <total; mask++){
            string subseq = "";
            for(int i =0; i<n; i++){
                if(mask & (1 << i)){
                    subseq += s[i];
                }
            }
            result.push_back(subseq);
        }
        sort(result.begin(),result.end());
        return result;
    }
};