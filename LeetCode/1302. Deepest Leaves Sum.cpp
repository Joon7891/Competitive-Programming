/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxHeight;
    
    int height(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    int dfs(TreeNode *root, int curHeight){
        if (root == NULL) return 0;
        if (curHeight == maxHeight) return root->val;
        return dfs(root->left, curHeight + 1) + dfs(root->right, curHeight + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        maxHeight = height(root);
        return dfs(root, 1);
    }
};