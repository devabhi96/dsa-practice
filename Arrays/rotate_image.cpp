/*
    LeetCode #48 - Rotate Image

    Approach:
    Transpose the Matrix + Reverse Each Row

    First, transpose the matrix by swapping elements across the
    main diagonal. Then reverse every row to rotate the matrix
    90 degrees clockwise.

    Time Complexity: O(n²)
    Space Complexity: O(1) auxiliary space

    Question:
    https://leetcode.com/problems/rotate-image/
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transposing the matrix
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reversing the array
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};