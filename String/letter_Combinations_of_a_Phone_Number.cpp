/*
 * 17. Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * Approach: Backtracking
 *   - Map each digit (2-9) to its letters.
 *   - Recurse over digit positions, choosing one letter per digit.
 *   - When every digit is used, save the current string as a combination.
 *
 * Time:  O(4^n * n), n = digits.length
 * Space: O(n) recursion depth (excluding output)
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        string current;
        backtrack(0, digits, mapping, current, ans);
        return ans;
    }

private:
    void backtrack(int idx, const string& digits, const vector<string>& mapping,
                   string& current, vector<string>& ans) {

        if (idx == digits.size()) {
            ans.push_back(current);
            return;
        }

        const string& letters = mapping[digits[idx] - '0'];
        for (char c : letters) {
            current.push_back(c);                       
            backtrack(idx + 1, digits, mapping, current, ans); 
            current.pop_back();                            
        }
    }
};