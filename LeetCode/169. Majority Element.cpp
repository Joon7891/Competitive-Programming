class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n / 2;
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = 0; i + k < n; i++){
            if (nums[i] == nums[i + k]){
                ans = nums[i];
                break;
            }
        }
        
        return ans;
    }
};