/**
 * LeetCode 6 - Zigzag Conversion
 * ---------------------------------
 * Converts a string into a zigzag pattern across `numRows` rows,
 * then reads it row by row to produce the final output.
 *
 * Approach: Simulate row traversal directly using index math instead
 * of building the full 2D grid.
 *   - Each "cycle" spans `2*(numRows-1)` characters.
 *   - For top/bottom rows, only one char per cycle is added.
 *   - For middle rows, a second "in-between" char is added per cycle.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n) (excluding output string)
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string ans;
        int n = s.size();
        int charinsection = 2* (numRows -1);

        for(int currRow = 0; currRow < numRows; currRow++){
            int index = currRow;
            while(index < n){
                ans += s[index];
                if(currRow != 0 && currRow != numRows-1){
                    int charinbetween = charinsection - 2*(currRow);
                    int secondindex = index + charinbetween;

                    if(secondindex <n){
                        ans += s[secondindex];
                    }
                }
                index += charinsection;
            }
        }

return ans;
    }
};