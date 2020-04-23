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
    int maxAncestorDiff(TreeNode* root) {
        vector<int> empty;
        return dfs(root, empty);
    }
    
    int dfs(TreeNode* root, vector<int> prev){
        if (root == NULL) return 0;
        
        int best = 0;
        for (int i : prev){
            best = max(best, abs(i - root->val));
        }
        
        prev.push_back(root->val);
        best = max(best, dfs(root->left, prev));
        best = max(best, dfs(root->right, prev));
        return best;
    }
};