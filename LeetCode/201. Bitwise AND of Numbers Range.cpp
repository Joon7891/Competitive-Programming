class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        bool seen = false;
                
        for (int i = 30; i >= 0; i--){
            int mBit = m & (1 << i);
            int nBit = n & (1 << i);
            
            if (mBit == nBit) ans |= nBit;
            else break;
        }
        
        return ans;
    }
};