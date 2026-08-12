// Problem: Rotate String
// Link: https://leetcode.com/problems/rotate-string/
// Approach: Concatenate s with itself (s+s), then manually scan for goal
//           as a substring using a naive pattern-matching pointer (j),
//           backtracking i on mismatch to avoid skipping valid start positions.
// Time: O(n) average, O(n*m) worst case | Space: O(n) (for doubled string)

class Solution {
public:
    bool rotateString(string s, string goal) {

            if(s.length() != goal.length()){
                return false;
            }

            int n = s.length();
            s += s;
            int j = 0;
            n *=2;

            for(int i =0; i<n; i++){

                if(s.at(i) == goal.at(j)){
                    j++;
                }
               else if(s.at(i) != goal.at(j)){
    i -= j;   
    j = 0;
}
                if(j == goal.length()){
                    return true;
                }
            }
return false;
    }
};