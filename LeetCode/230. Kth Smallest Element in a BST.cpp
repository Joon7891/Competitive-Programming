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
    map<TreeNode*, int> size;
    
    int getSize(TreeNode* root){
        if (root == NULL) return 0;
        
        if (size.find(root) != size.end()) return size[root];
        
        return size[root] = 1 + getSize(root->left) + getSize(root->right);   
    }
    
    int solve(TreeNode* root, int l, int r, int k){        
        int leftSize = getSize(root->left);
        int rightSize = getSize(root->right);
        
        int leftEnd = l + leftSize - 1;
        int rightEnd = r - rightSize + 1;
        int cur = (leftEnd + rightEnd) / 2;
        
        if (cur == k) return root->val;
        else if (k <= leftEnd) return solve(root->left, l, leftEnd, k);
        else return solve(root->right, rightEnd, r, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int s = getSize(root);
        return solve(root, 1, s, k);
    }
};