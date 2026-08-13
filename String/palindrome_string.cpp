// Valid Palindrome - LeetCode 125
// Remove non-alphanumeric characters, convert to lowercase,
// and check whether the remaining string is a palindrome.
class Solution {
public:
    bool isPalindrome(string s) {
     int n = s.length();
    string ans ="";

    for(char c: s){
        if(isalnum(c)){
            ans+= tolower(c);
        }
    }

    int st =0;
    int end = ans.length()-1;

    while(st < end){
        if(ans.at(st) != ans.at(end)){
            return false;
        }
        st++;
        end--;
    }
        return true;
    }
};