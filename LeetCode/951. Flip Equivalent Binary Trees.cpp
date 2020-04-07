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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL || root2 == NULL) return root1 == NULL && root2 == NULL;
        
        if (root1->val != root2->val) return false;
        
        bool checkOne = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool checkTwo = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return checkOne || checkTwo;
    }
};