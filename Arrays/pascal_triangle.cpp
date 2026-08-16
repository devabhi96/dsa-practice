/*
    LeetCode #118 - Pascal's Triangle

    Approach:
    Generate Each Row Using Binomial Coefficients

    Generate each row independently using the formula for
    consecutive binomial coefficients. The first element of
    every row is 1, and each subsequent element is calculated
    from the previous value using:
    
        C(n, k) = C(n, k-1) * (n-k+1) / k

    Time Complexity: O(numRows²)
    Space Complexity: O(numRows²) for the output

    Question:
    https://leetcode.com/problems/pascals-triangle/
*/
class Solution {
public:
    vector<int> generaterow(int row){
        vector<int> temp;
        long long ans = 1;
        temp.push_back(1);

        for(int col = 1; col< row; col++){
            ans = ans *(row-col);
            ans = ans/col;
            temp.push_back(ans);
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i =1; i<=numRows; i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};