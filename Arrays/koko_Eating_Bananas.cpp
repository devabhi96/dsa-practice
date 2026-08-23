/*
 * 875. Koko Eating Bananas
 * https://leetcode.com/problems/koko-eating-bananas/
 *
 * Binary search on the answer (eating speed k).
 * Feasibility check: total hours = sum(ceil(pile / k)) for all piles,
 * must be <= h. Hours needed is monotonically non-increasing in k,
 * so binary search for the minimum valid k in [1, max(piles)].
 *
 * Time:  O(n log(max(piles)))
 * Space: O(1)
 */
class Solution {
public:
    long long sumofdivi(vector<int>&nums , long long mid){  long long sum = 0;
        for(int x : nums){
            sum += (x+mid-1)/mid;
        }   
        return sum;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();
        int st =1;
        long long end = *max_element(nums.begin(),nums.end());
        long long ans =-1;

        while(st <= end){

            int mid = st+ (end-st)/2;

        if(sumofdivi(nums,mid) <= h){
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