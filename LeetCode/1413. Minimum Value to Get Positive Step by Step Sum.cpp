class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int low = INT_MAX;
        
        int cur = 0;
        for (int a : nums){
            cur += a;
            low = min(low, cur);
        }
        
        return max(1, 1 - low);
    }
};