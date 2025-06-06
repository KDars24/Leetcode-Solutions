/**
Given a binary tree, return true if it is height-balanced and false otherwise.

A height-balanced binary tree is defined as a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

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
    int max_height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(max_height(root->left), max_height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int left  = max_height(root->left);
        int right = max_height(root->right);

        if(abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};

