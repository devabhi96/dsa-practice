// LeetCode 135: Candy
// Two-pass greedy: left-to-right pass enforces "beat left neighbor if
// rating is higher"; right-to-left pass enforces "beat right neighbor
// if rating is higher", taking max() with the left pass's result since
// peaks must satisfy both constraints. Right-to-left pass must iterate
// backward so ans[i+1] is already finalized when computing ans[i].
// Time: O(n), Space: O(n).

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n,1);

        for(int i =1; i<n; i++){
            if(ratings[i-1] < ratings[i]){
                ans[i] = ans[i-1] + 1;
            }
        }

        for(int i = n-2; i>=0; i--){
            if(i+1 < n && ratings[i] > ratings[i+1] ){
                ans[i] = max(ans[i], ans[i+1]+1);
            }
        }
        
        int sum= 0;
        for(int x: ans){
            sum += x;
        }

return sum;
    }
};