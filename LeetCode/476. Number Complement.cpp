class Solution {
public:
    int findComplement(int num) {
        int hi = 0;
        for (int i = 0; i < 31; i++) {
            if (num & (1 << i)) hi = i;
        }
        
        int ans = 0;
        for (int i = 0; i <= hi; i++){
            if ((num & (1 << i)) == 0) ans |= (1 << i);
        }
        
        return ans;
    }
};