// Sort Characters By Frequency - LeetCode 451
// Count the frequency of each character and sort the string
// based on frequency in descending order.
class Solution {
public:
    string frequencySort(string s) {

        vector<int> freq(128, 0);

        
        for(int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {

         
            if(freq[a] == freq[b]) {
                return a < b;
            }

           
            return freq[a] > freq[b];
        });

        return s;
    }
};