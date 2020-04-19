class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        int pTotal = 0;
        vector<int> ans;
        for (int num : nums){
            pTotal += num;
            ans.push_back(num);
            
            if (pTotal > total - pTotal) break;
        }
        
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());

        return ans;
    }
};