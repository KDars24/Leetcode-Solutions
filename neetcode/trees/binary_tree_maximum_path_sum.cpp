/**
124. Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

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
    int dfs(TreeNode* root, int& res) {
        if(!root) return 0;

        int left_max  = dfs(root->left, res);
        int right_max = dfs(root->right, res);

        left_max  = max(0, left_max);
        right_max = max(0, right_max);

        res = max(res, left_max + root->val + right_max);

        return root->val + max(left_max, right_max); 
    }
    int maxPathSum(TreeNode* root) {
        int result = root->val;
        dfs(root, result);
        return result;
    }
};
