/*
 * LeetCode 22 - Generate Parentheses
 * Difficulty: Medium
 *
 * Given n pairs of parentheses, generate all combinations of
 * well-formed parentheses.
 *
 * Approach: Backtracking
 * - Only add '(' if openN < n
 * - Only add ')' if closedN < openN
 * - A combination is valid when openN == closedN == n
 *
 * Time Complexity:  O(4^n / sqrt(n))  (nth Catalan number)
 * Space Complexity: O(n) recursion depth (excluding output storage)
 */
class Solution {
public:

    void backtrack(int openN,int closedN, int n,vector<char>& stack,vector<string> &res ){
        if(openN == closedN && closedN == n){
            string combination(stack.begin(),stack.end());
            res.push_back(combination);
            return;
        }

        if(openN < n){
            stack.push_back('(');
            backtrack(openN + 1,closedN,n,stack,res);
            stack.pop_back();
        }

        if(closedN < openN){
            stack.push_back(')');
            backtrack(openN,closedN + 1,n,stack,res);
            stack.pop_back();
        }

    }


    vector<string> generateParenthesis(int n) {
        vector<char> stack;
        vector<string> res;

        backtrack(0,0,n,stack,res);
        return res;
    }

};