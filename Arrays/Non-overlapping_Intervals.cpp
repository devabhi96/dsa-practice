// Problem: 435. Non-overlapping Intervals
// Approach: Greedy interval scheduling
// - Sort intervals by end time (earliest finishing first)
// - Keep an interval if its start >= end time of the last kept interval
// - Otherwise it overlaps -> count it as removed
// Time Complexity: O(n log n) for sorting + O(n) scan
// Space Complexity: O(1) extra (excluding sort's internal space)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // sort by end time
        });

        int count = 0;          // intervals removed
        int lastEnd = intervals[0][1];
        int kept = 1;           // keep the first interval

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEnd) {
                // no overlap, keep it
                lastEnd = intervals[i][1];
                kept++;
            } else {
                // overlap, remove this one
                count++;
            }
        }

        return count;
    }
};