/*
    Question: Subarray Sum Equals K
    Link: https://leetcode.com/problems/subarray-sum-equals-k/
    Difficulty: Medium

    Approach: Brute Force
    For every starting index i, extend the subarray one element at a
    time (j from i to n-1), maintaining a running sum. Whenever the
    running sum equals k, increment the count. Checks every possible
    subarray exactly once.

    Time Complexity: O(n^2)  — nested loop over all subarrays
    Space Complexity: O(1)   — no extra data structure used
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans =0;
        int n  =nums.size();
        int sum =0;

        for(int i = 0; i<n; i++){
            sum =0;
            for(int j = i; j<n; j++){
                    sum += nums[j];
                     if(sum == k){
                ans++;
            }
            }
           
        }
        return ans;
        
    }
};

/*
    Question: Subarray Sum Equals K
    Link: https://leetcode.com/problems/subarray-sum-equals-k/
    Difficulty: Medium

    Approach: Prefix Sum + Hashmap
    Maintain a running prefix sum while iterating through the array,
    and store the frequency of each prefix sum seen so far. For each
    index, check if (sum - k) has occurred before — if it has, every
    such occurrence marks the start of a valid subarray ending here,
    so add its frequency to count. freq[0] = 1 handles the case where
    the subarray starts from index 0.

    Time Complexity: O(n)  — single pass, O(1) average hashmap ops
    Space Complexity: O(n) — hashmap stores up to n distinct prefix sums
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
     freq[0] = 1;
        int count = 0;
        int sum = 0;

        for(int x : nums){
            sum += x;
           if(freq.find(sum-k) != freq.end()){
            count += freq[sum-k];
           }
           freq[sum]++;

        }
        
        return count;
    }
};