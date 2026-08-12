// Problem: Valid Anagram
// Link: https://leetcode.com/problems/valid-anagram/
// Approach: Frequency count using a fixed-size array — increment counts
//           for chars in s, decrement for chars in t, check all counts are 0.
// Time: O(n + m) | Space: O(1) (fixed-size array)

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr(300,0);

        for(int i =0; i<s.size(); i++){
            arr[s.at(i) - '0']++;
        }

        for(int i =0; i<t.size(); i++){
            arr[t.at(i) - '0']--;
        }

        for(int i =0; i<arr.size(); i++){
            if(arr[i] != 0 ){
                return false;
            }
        }
        return true;
    }
};