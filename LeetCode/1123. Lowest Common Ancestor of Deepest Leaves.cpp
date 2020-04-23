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
    map<TreeNode*, int> heightMap;
    
    int height(TreeNode * root){
        if (root == NULL) return 0;
        
        if (heightMap[root] != 0) return heightMap[root];
        
        return heightMap[root] = 1 + max(height(root->left), height(root->right));
        
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
                
        if (leftHeight > rightHeight) return lcaDeepestLeaves(root->left);
        else if (rightHeight > leftHeight) return lcaDeepestLeaves(root->right);
        else return root;
    }
};