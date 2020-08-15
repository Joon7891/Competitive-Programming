class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int cap = nums[0];
        for (int i = 1; i < n; i++){
            cap--;
            if (cap == -1) return false;
            
            cap = max(cap, nums[i]);
        }
        
        return true;
    }
};