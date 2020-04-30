class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++){
            int bit = 1 << i;
            
            int counter = 0;
            for (int a : nums){                
                if ((a & bit) == 0) counter++;
            }
                        
            if (counter % 3 == 0) ans |= bit;
        }
        
        return ans;
    }
};