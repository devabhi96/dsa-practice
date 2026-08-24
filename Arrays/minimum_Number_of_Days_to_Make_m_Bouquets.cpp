//LeetCode 1482 - Minimum Number of Days to Make m Bouquets | Binary Search on Answer + Greedy Bouquet 
//Counting
class Solution {
public:

    bool canbloom(vector<int> & bloomDay,int m ,int k,int day){
        int flower = 0;
        int bouq = 0;

        for(int i =0; i< bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                flower ++;

                if(flower == k){
                    bouq++;
                    flower =0;
                }
            }
            else{
                flower =0;
            }
        }
        return bouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();

            if((long long)m * k >n)
            return -1;

            int st = *min_element(bloomDay.begin(),bloomDay.end());
            int end = *max_element(bloomDay.begin(),bloomDay.end());
            int answer =-1;

            while(st<=end){
                int mid =st + (end-st)/2;

                if(canbloom(bloomDay,m,k,mid)){
                    answer = mid;
                    end = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
            return answer;
    }
};