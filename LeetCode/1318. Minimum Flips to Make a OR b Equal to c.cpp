class Solution {
public:
    int minFlips(int a, int b, int c) {
        int total = 0;
        for (int i = 0; i < 32; i++){
            int bit = 1 << i;
            int aBit = a & bit;
            int bBit = b & bit;
            int cBit = c & bit;
            int orBit = aBit | bBit;
            
            if (orBit != cBit){
                if (cBit > 0) total++;
                else total += (aBit > 0) + (bBit > 0);
            }
        }
        
        return total;
    }
};