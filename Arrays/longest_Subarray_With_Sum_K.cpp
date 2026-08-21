/*
    Question: Longest Subarray with Sum K
    Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
    Difficulty: Medium

    Approach:
    Use prefix sum + hashmap. Maintain a running sum while iterating
    through the array, and store the first index at which each prefix
    sum occurs. For each index i, check if (sum - k) has occurred
    before — if so, the subarray between that index and i has sum k.
    Also directly check if sum == k (subarray starting from index 0).
    Only the first occurrence of each prefix sum is stored, since we
    want the longest possible subarray. Handles negative numbers
    correctly (unlike Kadane-style reset-on-negative approaches).

    Time Complexity: O(n)  — single pass, O(1) average hashmap ops
    Space Complexity: O(n) — hashmap can store up to n distinct prefix sums
*/
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
    
            unordered_map<long long, int> firstIndex;
            long long sum = 0;
            int maxlen = 0;

            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];

                if (sum == k) maxlen = i + 1;

                if (firstIndex.find(sum - k) != firstIndex.end()) {
                    maxlen = max(maxlen, i - firstIndex[sum - k]);
                }

                if (firstIndex.find(sum) == firstIndex.end()) {
                    firstIndex[sum] = i;
                }
            }
            return maxlen;
        
        
        
        
        
        
        
    }
};