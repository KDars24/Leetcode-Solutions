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
    int dfs(TreeNode* root, int& res) {
        if(!root) return 0;

        int left  = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);

        return 1 + max(left, right);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
         dfs(root, result);
        return result;
    }
};

