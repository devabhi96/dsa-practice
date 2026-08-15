/*
    GeeksforGeeks - Leaders in an Array

    Approach:
    Traverse from Right to Left

    Start from the last element and maintain the maximum element
    encountered so far. If the current element is greater than or
    equal to the maximum, it is a leader and is inserted at the
    beginning of the result vector.

    Time Complexity: O(n²) in the worst case due to insert()
    Space Complexity: O(n)

    Question:
    https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
*/
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        int maxel = -1;
        vector<int> ans;
        
        for(int i =n-1; i>= 0; i--){
            if(arr[i] >= maxel){
                maxel = arr[i];
                ans.insert(ans.begin(),arr[i]);
            }
        }
        return ans;
        
    }
};