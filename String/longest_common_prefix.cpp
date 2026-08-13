// Problem: Longest Common Prefix
// Link: https://leetcode.com/problems/longest-common-prefix/
// Approach: Sort the array — the common prefix of ALL strings must match
//           the common prefix of the lexicographically first and last strings
//           (since sorting brings the most "different" strings to the ends).
//           Compare char by char until mismatch or shortest string ends.
// Time: O(n log n) for sort + O(m) for comparison, m = length of shortest string
// Space: O(1) extra (excluding sort's internal space)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        string ans = "";

        for(int i =0; i<min(first.length(),last.length()); i++){
            if(first[i] != last[i]){
                break;
            }
        ans += first[i];
        }
return ans;
    }
};