
class Solution {
public:
    vector<int> getSubset(vector<int> nums, int bitmask){
        vector<int> ans;
        for (int i = 0; i < 32; i++){
            if (bitmask & (1 << i)) ans.push_back(nums[i]);
        }
        
        return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int pSize = 1 << nums.size();
        
        vector<vector<int>> ans;
        for (int i = 0; i < pSize; i++){
            ans.push_back(getSubset(nums, i));
        }
        
        return ans;
    }
};