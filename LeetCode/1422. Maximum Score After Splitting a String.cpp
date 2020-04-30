class Solution {
public:
    int count(string s, char check){
        int total = 0;
        for (char c : s){
            if (c == check) total++;
        }
        
        return total;
    }
    
    int maxScore(string s) {
        int n = s.length();
        
        int ans = 0;
        for (int i = 1; i < n; i++){
            ans = max(ans, count(s.substr(0, i), '0') + count(s.substr(i), '1'));
        }
        
        return ans;
    }
};