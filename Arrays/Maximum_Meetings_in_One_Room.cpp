// Problem: Maximum Meetings in One Room
// Approach: Greedy activity selection
// - Sort meeting indices by finish time (ties -> smaller index first)
// - Iterate in that order, selecting a meeting if its start time is
//   strictly greater than the finish time of the last selected meeting
// - Sort selected indices to return them in increasing (original) order
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (f[a] != f[b]) return f[a] < f[b];
            return a < b;
        });

        vector<int> selected;
        int lastFinish = -1;
        for (int i : idx) {
            if (s[i] > lastFinish) {
                selected.push_back(i);
                lastFinish = f[i];
            }
        }

        sort(selected.begin(), selected.end());
        vector<int> ans;
        for (int i : selected) ans.push_back(i + 1); 
        return ans;
    }
};