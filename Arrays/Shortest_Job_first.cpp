// GfG: Shortest Job First (SJF) Scheduling - Average Waiting Time
// Approach: Sort burst times ascending, then simulate SJF by
//           accumulating waiting time as running total of prior
//           burst times. Average is floored via integer division.
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding sort space)

class Solution {
  public:
    int solve(vector<int>& bt) {
     sort(bt.begin(),bt.end());
    int n  = bt.size();
     
     int totalWait = 0;
     int currentWaitTime = 0;
     
    for(int i =0; i<n; i++){
        totalWait += currentWaitTime;
        currentWaitTime += bt[i];
    }
     return totalWait/n;
        
    }
};