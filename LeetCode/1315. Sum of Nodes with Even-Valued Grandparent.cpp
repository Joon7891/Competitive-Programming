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
    int getTotal(TreeNode* root, int n){
        if (n == 2) return root->val;
        
        int total = 0;
        if (root->left != NULL) total += getTotal(root->left, n + 1);
        if (root->right != NULL) total += getTotal(root->right, n + 1);        
        return total;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) return 0;
        
        int total = 0;
        if (root->val % 2 == 0) total += getTotal(root, 0);
        
        if (root->left != NULL) total += sumEvenGrandparent(root->left);
        if (root->right != NULL) total += sumEvenGrandparent(root->right);
        return total;
    }
};