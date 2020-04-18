class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        
        for (int i = 0; i <= num; i++){
            for (int j = 0; j < 31; j++){
                if (i & (1 << j)) ans[i]++;
            }
        }
        
        return ans;
    }
};