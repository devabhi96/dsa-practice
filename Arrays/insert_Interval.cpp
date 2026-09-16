// LeetCode 57 - Insert Interval
// https://leetcode.com/problems/insert-interval/
//
// Insert newInterval into a sorted, non-overlapping list of intervals,
// merging where necessary, and return the resulting sorted, non-overlapping list.
//
// Approach: single pass, three phases
//   1. Copy intervals ending before newInterval starts
//   2. Merge (absorb) all intervals overlapping newInterval
//   3. Copy remaining intervals starting after newInterval ends
//
// Time:  O(n) - one pass through intervals
// Space: O(n) - output array

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        int start = newInterval[0], end = newInterval[1];

     
        while (i < n && intervals[i][1] < start) {
            result.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        result.push_back({start, end});
        
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};