class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0) return 0;
        
        sort(envelopes.begin(), envelopes.end(),
            [](vector<int> a, vector<int> b){
                if (a[0] == b[0]) return a[1] >= b[1];
                return a[0] > b[0];
            }
        );
        
        int N = envelopes.size();
        vector<int> dp(N, 1);
        
        int ans = 0;
        for (int i = 0; i < N; i++){
            for (int j = i - 1; j >= 0; j--){                
                if (envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};