// LeetCode 860. Lemonade Change
// Approach: Greedy — track count of $5 and $10 bills held.
//           Prefer giving change using a $10 + $5 combo over
//           three $5 bills whenever possible (to conserve $5s).
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fivecnt =0;
        int tencnt =0;

        for(int i =0; i<n; i++){

            if(bills[i] == 5){
                fivecnt++;
            }

            if(bills[i] == 10){
                if(fivecnt == 0){
                    return false;
                }
                else{
                    tencnt++;
                    fivecnt--;
                }
            }

        if(bills[i] == 20){
            if((tencnt == 0 && fivecnt <3) || (tencnt >= 1 && fivecnt == 0)){
                return false;
            }

            else if(tencnt >0 && fivecnt >0){
                tencnt--;
                fivecnt--;
            }
            else{
                fivecnt -= 3;
            }
        }
        }


return true;

    }
};