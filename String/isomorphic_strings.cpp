// Problem: Isomorphic Strings
// Link: https://leetcode.com/problems/isomorphic-strings/
// Approach: Two hashmaps for bidirectional character mapping (s->t and t->s)
//           to ensure a strict one-to-one correspondence between characters.
// Time: O(n) | Space: O(1) (bounded by character set size)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        unordered_map<char,char> mpp1;
        
        if(s.length() != t.length()){
            return false;
        }

        for(int i =0; i<s.length(); i++){
            if(mpp.find(s[i]) != mpp.end() && mpp[s[i]] != t[i]){
                return false;
            }
            if(mpp1.find(t[i]) != mpp1.end() && mpp1[t[i]] != s[i]){
                return false;
            }
            mpp1[t.at(i)] = s.at(i);
            mpp[s.at(i)] = t.at(i);
        }   
    return true;
    }
};
