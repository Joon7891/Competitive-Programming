class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int total = 0;
        for (char j : J){
            for (char s : S){
                if (j == s) total++;
            }
        }
        
        return total;
    }
};