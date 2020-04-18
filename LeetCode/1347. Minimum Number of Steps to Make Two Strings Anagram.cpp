class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> sFreq, tFreq;
        
        for (char c : s) sFreq[c]++;
        for (char c : t) tFreq[c]++;
        
        int total = 0;
        for (char c = 'a'; c <= 'z'; c++){
            total += abs(sFreq[c] - tFreq[c]);
        }
        
        return total / 2;
    }
};