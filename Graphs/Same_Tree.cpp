// LeetCode 100: Same Tree
// Approach: Recursive DFS
// Logic: Compare corresponding nodes of both trees.
// Check if both nodes are null, if only one is null, or if their values differ.
// Recursively compare left and right subtrees.
// Time Complexity: O(n) — Visit each corresponding node once.
// Space Complexity: O(h) — Recursion stack, where h is the tree height.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void treeTraversal(TreeNode* p, TreeNode* q, bool& ans) {
        if (p == nullptr && q == nullptr) {
            return;
        }

        if (p == nullptr || q == nullptr) {
            ans = false;
            return;
        }

        if (p->val != q->val) {
            ans = false;
        }

        treeTraversal(p->left, q->left, ans);
        treeTraversal(p->right, q->right, ans);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        treeTraversal(p, q, ans);
        return ans;
    }
};