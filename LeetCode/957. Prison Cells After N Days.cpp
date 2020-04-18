class Solution {
public:
    int next(int cur){
        int ans = 0;
        for (int i = 1; i <= 6; i++){
            int left = cur & (1 << (i - 1));
            int right = cur & (1 << (i + 1));
            
            if ((left > 0) == (right > 0)) ans |= 1 << i;
        }
        
        return ans;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int mask = 0;
        for (int i = 0; i < 8; i++){
            mask |= cells[i] << i;
        }
        
        map<int, int> dayNum;
        while (N > 0){
            if (dayNum[mask] != 0){
                N %= dayNum[mask] - N;
            }
            else dayNum[mask] = N;
            
            if (N-- >= 1){
                mask = next(mask);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < 8; i++){
            if (mask & (1 << i)) ans.push_back(1);
            else ans.push_back(0);
        }
        
        return ans;
    }
};