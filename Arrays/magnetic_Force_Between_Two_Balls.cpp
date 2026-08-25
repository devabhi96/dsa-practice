// LeetCode 1552. Magnetic Force Between Two Balls
// Binary search on answer: search the minimum magnetic force `m` between
// baskets, then greedily place balls (largest possible gap) to check
// feasibility for a given force. Maximize the minimum force via binary search.
// Time: O(n log n) for sort + O(n log(maxPos)) for binary search
// Space: O(1) extra
class Solution {
public:

    bool canbeplaced(vector<int>&position,int m,int magnet){
        int count = 1;
        int lastPosition = position[0];
        for(int i =1; i<position.size(); i++ ){
            if(position[i] - lastPosition >= magnet){
                count++;
                lastPosition = position[i];
            }

        }
    return count>=m;
    }

    int maxDistance(vector<int>& position, int m) {
            sort(position.begin(),position.end());
            int low = 1; 
            int high = position.back() - position[0];
            int ans =0;

            while(low <= high){
                int mid = low + (high-low)/2;
                if(canbeplaced(position,m,mid)){
                    ans = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }   
            return ans;
    }
};