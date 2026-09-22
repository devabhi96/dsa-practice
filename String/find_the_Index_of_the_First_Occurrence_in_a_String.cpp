// LeetCode 28: Find the Index of the First Occurrence in a String
// Brute-force substring search: for each valid starting index i in
// haystack, try to match needle character by character. Time: O(m*n)
// in the worst case, Space: O(1).

class Solution {
public:

int strStr(string haystack, string needle) {
    int m = haystack.length();
    int n = needle.length();

    for (int i = 0; i + n <= m; i++) {
        int j = 0;
        while (j < n && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == n) return i;
    }
    return -1;
}
};