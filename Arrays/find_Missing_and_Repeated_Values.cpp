/**
 * LeetCode 2965. Find Missing and Repeated Values
 *
 * Given an n x n grid containing values from 1 to n*n where exactly one
 * number is missing and exactly one number is repeated twice, find both.
 *
 * Approach: Sum & Sum-of-Squares
 *   Let diff       = actualSum - expectedSum        = repeated - missing
 *   Let squareDiff  = actualSquareSum - expectedSquareSum
 *                    = repeated^2 - missing^2
 *                    = (repeated - missing)(repeated + missing)
 *   => sum = squareDiff / diff = repeated + missing
 *   Solve the two linear equations for repeated and missing.
 *
 * Time:  O(n^2)
 * Space: O(1)
 */
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = 1LL * n*n;   
        long long expectedSum = N*(N+1)/2;
        long long expectedSquareSum = N*(N+1)*(2*N+1)/6;
        long long actualSum = 0;
        long long actualSquareSum = 0;

        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                long long x = grid[i][j];
                actualSum += x;
                actualSquareSum += x*x;
            }
        }

        long long diff = actualSum - expectedSum;

        long long squareDiff = actualSquareSum - expectedSquareSum;

        long long sum = squareDiff / diff;

        long long repeated = (diff + sum) / 2;
        long long missing = (sum - diff) / 2;

        return {(int)repeated, (int)missing};

    }
};