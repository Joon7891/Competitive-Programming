class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int oneFreq[32];
        int zeroFreq[32];
        
        memset(oneFreq, 0, sizeof(oneFreq));
        memset(zeroFreq, 0, sizeof(zeroFreq));
        for (int i = 0; i < 32; i++){
            int bit = 1 << i;
            for (int num : nums){
                if (bit & num) oneFreq[i]++;
                else zeroFreq[i]++;
            }
        }
        
        int total = 0;
        for (int i = 0; i < 32; i++){
            total += oneFreq[i] * zeroFreq[i];
        }
        
        return total;
    }
};