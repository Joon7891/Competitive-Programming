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
    int solve(TreeNode* root, map<int, int> freq) {
        freq[root->val]++;
        if (root->left == NULL && root->right == NULL) {
            int oddCount = 0;
            int total = 0;
            for (auto const k : freq) {
                oddCount += k.second % 2;
                total += k.second;                
            }
            
            if (oddCount < 2 && total >= 3) return 1;
            else if (total == 2 && oddCount == 0) return 1;
            else if (total == 1) return 1;
            else return 0;
        }
        
        int ans = 0;
        if (root->left != NULL) ans += solve(root->left, freq);
        if (root->right != NULL) ans += solve(root->right, freq);
        return ans;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int> freq;
        return solve(root, freq);
    }
};