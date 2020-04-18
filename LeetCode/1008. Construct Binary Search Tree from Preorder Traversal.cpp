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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *cur = NULL;
        
        if (preorder.size() == 0) return cur;
        
        cur = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        cur->val = preorder[0];
        
        vector<int> left;
        vector<int> right;
        for (int a : preorder){
            if (a < cur->val) left.push_back(a);
            else if (a > cur->val) right.push_back(a);
        }
        
        cur->left = bstFromPreorder(left);
        cur->right = bstFromPreorder(right);
        return cur;
    }
};