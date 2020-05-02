class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int best = 1;
        int prev = nums[0];
        int curLength = 1;
        for (int i = 1; i < nums.size(); i++){
            if (prev + 1 == nums[i]) curLength++;
            else if (prev == nums[i]) continue;
            else curLength = 1;
                        
            prev = nums[i];
            best = max(best, curLength);
        }
        
        return best;
    }
};