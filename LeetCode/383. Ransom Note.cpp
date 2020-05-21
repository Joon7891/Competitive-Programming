class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> noteFreq, magFreq;
        
        for (char c : ransomNote) noteFreq[c]++;
        for (char c : magazine) magFreq[c]++;
        
        for (char c = 'a'; c <= 'z'; c++){
            if (noteFreq[c] > magFreq[c]) return false;
        }
        
        return true;
    }
};