/**
 * Problem: Find the Smallest Divisor Given a Threshold
 * Approach: Binary search on the answer over divisor range
 * [1, max(nums)]. For each candidate divisor, compute the sum of
 * ceiling divisions and check against threshold.
 * Time: O(n log(max(nums))) | Space: O(1)
 */
class Solution {
public:

     int sumofdivi(vector<int> &nums,int mid){
        int sum = 0;
        for(int x : nums){
            sum += (x+ mid-1)/mid;
        }
        return sum;
    }
        

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int st = 1;
        int end =*max_element(nums.begin(),nums.end());
        int ans =-1;

    while(st <= end){

            int mid = st+ (end-st)/2;

        if(sumofdivi(nums,mid) <= threshold){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }
return ans;
   
    }
};