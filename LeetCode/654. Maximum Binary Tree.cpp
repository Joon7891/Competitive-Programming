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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *cur = NULL;
        
        if (nums.size() == 0) return NULL;
                
        int best = INT_MIN;
        int bestIndex;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > best){
                best = nums[i];
                bestIndex = i;
            }
        }
                
        vector<int> left;
        for (int i = 0; i < bestIndex; i++){
            left.push_back(nums[i]);
        }
        
        vector<int> right;
        for (int i = bestIndex + 1; i < nums.size(); i++){
            right.push_back(nums[i]);
        }
        
        cur = new TreeNode(best, constructMaximumBinaryTree(left), constructMaximumBinaryTree(right));
        return cur;
    }
};