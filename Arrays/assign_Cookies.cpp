// LeetCode 455. Assign Cookies
// Approach: Greedy — sort both greed factors and cookie sizes,
//           use two pointers to match the smallest cookie that
//           satisfies the smallest unsatisfied child.
// Time Complexity: O(n log n + m log m)
// Space Complexity: O(1) (excluding sort space)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

sort(g.begin(),g.end());
sort(s.begin(),s.end());

        int cnt =0;
        int i =0;
        int j =0;
        int n1 = g.size();
        int n2 = s.size();

        while(i< n1 && j< n2){
            if(s[j] >= g[i]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
return cnt;

    }
};