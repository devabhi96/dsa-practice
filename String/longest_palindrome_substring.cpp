/*
 * LeetCode 5 - Longest Palindromic Substring
 * Difficulty: Medium
 *
 * Problem:
 * Given a string s, return the longest palindromic substring in s.
 *
 * Approach: Expand Around Center
 * Every palindrome is centered at a single character (odd length)
 * or between two characters (even length). Try all 2n-1 centers
 * and expand outward while characters match.
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(1)
 */


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);       // odd length
            int len2 = expandAroundCenter(s, i, i + 1);   // even length
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};