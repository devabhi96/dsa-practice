// LeetCode 2410. Maximum Matching of Players With Trainers
// (Same as LC 455. Assign Cookies)
// Approach: Greedy — sort both arrays, two pointers match the
//           smallest available trainer capacity to the smallest
//           unmatched player ability whenever capacity >= ability.
// Time Complexity: O(n log n + m log m)
// Space Complexity: O(1) (excluding sort space)

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
   

sort(players.begin(),players.end());
sort(trainers.begin(),trainers.end());

        int cnt =0;
        int i =0;
        int j =0;
        int n1 = players.size();
        int n2 = trainers.size();

        while(i< n2 && j< n1){
            if(players[j] <= trainers[i]){
                cnt++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
return cnt;   
    }
};