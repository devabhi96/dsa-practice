/*
LC 39 (Combination Sum) — \
https://leetcode.com/problems/combination-sum/ — 
Backtracking with include/idx-repeat/skip branches and a set for 
deduplication — Time: O(2^target) worst case (three-way branching 
per call, target/min(arr) max depth) — Space: O(target/min(arr)) 
recursion depth + O(k × count) for the set storing all 
combinations of average length k
*/


class Solution {
public:
    set<vector<int>> s;

    void getallcombin(vector<int>&arr,int target,int idx,vector<vector<int>>& ans,vector<int>&combin){
        if(idx == arr.size() || target<0){
            return;
        }
        if(target == 0){
            if(s.find(combin) == s.end()){
                ans.push_back({combin});
                s.insert(combin);
            }
            return;
        }

        combin.push_back(arr[idx]);
        getallcombin(arr,target-arr[idx],idx+1,ans,combin);

        getallcombin(arr,target-arr[idx],idx,ans,combin);
        combin.pop_back();

        getallcombin(arr,target,idx+1,ans,combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getallcombin(arr,target,0,ans,combin);
        return ans;
    }
};