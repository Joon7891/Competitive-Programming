class Solution {
public:
    int maxProfit(vector<int>& prices) {        
        int ans = 0;
        int low = INT_MAX;
        for (int i = 0; i < prices.size(); i++){
            ans = max(ans, prices[i] - low);
            low = min(low, prices[i]);
        }
        
        return ans;
    }
};