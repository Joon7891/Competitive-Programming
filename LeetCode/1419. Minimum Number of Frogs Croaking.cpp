class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int freq[4];
        memset(freq, 0, sizeof(freq));

        int best = 0;
        for (char c : croakOfFrogs){
            if (c == 'c') freq[0]++;
            else if (c == 'r') freq[1]++;
            else if (c == 'o') freq[2]++;
            else if (c == 'a') freq[3]++;
            else for (int i = 0; i < 4; i++) freq[i]--;
            
            for (int i = 0; i < 4; i++){
                for (int j = 0; j < i; j++){
                    if (freq[i] > freq[j]) return -1;
                }
            }
                        
            int pos = INT_MIN;
            for (int i = 0; i < 4; i++) pos = max(pos, freq[i]);
            
            best = max(best, pos);
        }
                
        for (int i = 0; i < 4; i++){
            if (freq[i] != 0) return -1;
        }
        
        return best;
    }
};