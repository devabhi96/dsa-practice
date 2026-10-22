// LeetCode 94: Binary Tree Inorder Traversal
// Approach: Recursive Inorder Traversal (DFS)
// Logic: Visit the left subtree, process the root, then visit the right subtree (Left → Root → Right).
// Time Complexity: O(n) — Visit each node once.
// Space Complexity: O(n) — Result vector and recursion stack.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

 void inOrder(TreeNode* root, vector<int>& res) {

            if(root == nullptr){
                    return;
            }
    
            inOrder(root->left,res);
            res.push_back(root -> val);
            inOrder(root->right,res);

 }

    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            inOrder(root,res);
            return res;
    }
};