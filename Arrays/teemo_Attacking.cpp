// 495. Teemo Attacking
// Approach: Greedy Algorithm
// Initialize n with the size of the array and ans = 0.
// Iterate through the array from index 0 to n-2.
// For each attack, calculate the effective poisoned duration using: min(duration, arr[i+1] - arr[i])
// Add this value to ans.
// If the gap between two attacks is smaller than the duration, only the gap contributes.
// Otherwise, the full duration contributes.
// After the loop, if the array is not empty, add the duration of the last attack.
// Return the total poisoned duration.
// Time Complexity
// O(n): A single traversal of the array.
// Space Complexity
// O(1): Only constant extra space is used.
// Key Idea

// Avoid counting overlapping poisoned intervals multiple times by adding the minimum of the attack duration and the gap between consecutive attacks.



class Solution {
public:
    int findPoisonedDuration(vector<int>& arr, int duration) {
            int n = arr.size();
            int ans =0;

            for(int i =0; i<n-1; i++){
                ans+= min(duration,arr[i+1]-arr[i]);
            }
        
        if(n>0){
            ans+= duration;
        }


            return ans;
    }
};