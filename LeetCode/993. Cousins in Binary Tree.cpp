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
    TreeNode* getPar(TreeNode* prev, TreeNode* cur, int target){
        if (cur == NULL) return NULL;
        
        if (cur->val == target) return prev;
        
        TreeNode* left = getPar(cur, cur->left, target);
        TreeNode* right = getPar(cur, cur->right, target);
        
        return left != NULL ? left : right;
    }
    
    int depth(TreeNode* cur, int target){
        if (cur == NULL) return INT_MIN;
        
        if (cur->val == target) return 1;
        
        return 1 + max(depth(cur->left, target), depth(cur->right, target));
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = depth(root, x);
        int yDepth = depth(root, y);
        
        TreeNode* xPar = getPar(NULL, root, x);
        TreeNode* yPar = getPar(NULL, root, y);
        
        return xDepth == yDepth && xPar != yPar;
    }
};