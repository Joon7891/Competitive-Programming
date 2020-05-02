class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int dp[41][1024];
        
    int dfs(int hat, vector<int>& hatsToPeople, int n, int assigned){        
        if (hat == 41){
            if (__builtin_popcount(assigned) == n) return 1;
            else return 0;
        }
        
        if (dp[hat][assigned] != -1) return dp[hat][assigned];
        
        int ans = dfs(hat + 1, hatsToPeople, n, assigned) % MOD;
        for (int i = 0; i < n; i++){
            int bit = 1 << i;
            
            if (bit & assigned) continue;
            
            if (hatsToPeople[hat] & bit){
                ans += dfs(hat + 1, hatsToPeople, n, assigned | bit);
                ans %= MOD;
            }
        }
        
        return dp[hat][assigned] = ans;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<int> hatToPeople(41, 0);
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < hats[i].size(); j++){
                hatToPeople[hats[i][j]] |= (1 << i);
            }
        }
        
        memset(dp, -1, sizeof(dp));
        return dfs(1, hatToPeople, n, 0);
    }
};