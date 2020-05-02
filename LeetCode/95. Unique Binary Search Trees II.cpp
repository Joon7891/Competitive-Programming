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
    map<pair<int, int>, vector<TreeNode*>> memo;
    
    vector<TreeNode*> solve(int a, int b){
        if (b < a) return {NULL};
        
        pair<int, int> key = make_pair(a, b);
        if (memo.find(key) != memo.end()) return memo[key];
        
        vector<TreeNode*> ans;
        for (int i = a; i <= b; i++){
            vector<TreeNode*> left = solve(a, i - 1);
            vector<TreeNode*> right = solve(i + 1, b);
            
            for (TreeNode* l : left){
                for (TreeNode* r : right){
                    TreeNode* cur = new TreeNode(i, l, r);
                    ans.push_back(cur);
                }
            }
        }
        
        return memo[key] = ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return n == 0 ? vector<TreeNode*>() : solve(1, n);
    }
};