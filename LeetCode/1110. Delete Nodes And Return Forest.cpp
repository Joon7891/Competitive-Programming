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
    set<TreeNode*> visited;
    
    TreeNode* getCurForest(TreeNode* root, vector<int>& to_delete){
        if (root == NULL) return NULL;
        
        visited.insert(root);
        for (int del : to_delete){
            if (root->val == del) return NULL;
        }
        
        TreeNode* ans = new TreeNode(root->val, getCurForest(root->left, to_delete), getCurForest(root->right, to_delete));
        return ans;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        if (root == NULL) return ans;
        
        TreeNode* cur = NULL;
        if (visited.find(root) == visited.end()) cur = getCurForest(root, to_delete);
        
        if (cur != NULL) ans.push_back(cur);
        
        vector<TreeNode*> left = delNodes(root->left, to_delete);
        vector<TreeNode*> right = delNodes(root->right, to_delete);
        
        for (TreeNode* i : left) ans.push_back(i);
        for (TreeNode* i : right) ans.push_back(i);
        return ans;
    }
};