//Longest Substring Without Repeating Characters
// LeetCode 3. Longest Substring Without Repeating Characters
// Approach: Sliding window + hash map (stores last seen index of each char)
// Time Complexity: O(n)
// Space Complexity: O(min(n, charset size))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int left =0;
        int maxlen =0;

        for(int right = 0; right < s.length(); right++){
            
            char c = s[right];

            if(mpp.find(c) != mpp.end() && mpp[c] >= left){
                left = mpp[c] +1;
            }
            mpp[c] = right;
            maxlen = max(maxlen,right-left+1);
        }
return maxlen;
    }
};