class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        vector<int> prefix(n, 0);
        
        prefix[0] = (A[0] + K * 10000) % K;
        for (int i = 1; i < n; i++) prefix[i] = (prefix[i - 1] + A[i] + K * 10000) % K;
        
        map<int, int> freq;
        
        int ans = 0;
        for (int i = 0; i < n; i++){
            int p = prefix[i];            
            ans += freq[p];
            freq[p]++;
            
            if (p == 0) ans++;
        }
                
        return ans;
    }
};