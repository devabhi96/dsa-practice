// Majority Element II
// Given an integer array of size n, find all elements that appear
// more than ⌊n/3⌋ times.
// Approach: Sort the array, then count consecutive runs of equal
// elements. Any run longer than n/3 qualifies (at most 2 such
// elements can exist).
// Time: O(n log n)  |  Space: O(1) extra (excluding output)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            int n= nums.size();
            sort(nums.begin(),nums.end());
            vector<int> ans;
            int freq =1;
            
            for(int i=1; i<n; i++){
                if(nums[i]== nums[i-1]){
                    freq++;
                }
              else{
                if(freq > n/3){
                    ans.push_back(nums[i-1]);
                }
                freq = 1;
              }    
            }
        if(freq > n/3){
            ans.push_back(nums[n-1]);
        }    
           return ans;        
    }
};