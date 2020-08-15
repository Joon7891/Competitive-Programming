class Solution {
public:
    string gen(string S, int mask) {
        int m = 0;
        
        string ss = "";
        for (char c : S) {
            if (c >= '0' && c <= '9') ss += c;
            else {
                int ind = (1 << m) & mask;                
                if (ind != 0) ss += toupper(c);
                else ss += tolower(c);
                m++;
            }
        }
                
        return ss;
    }
    
    vector<string> letterCasePermutation(string S) {
        int n = 0;
        for (char c : S) {
            if (c < '0' || c > '9') n++;
        }
        
        vector<string> result;
        for (int i = 0; i < (1 << n); i++) {
            result.push_back(gen(S, i));
        }
        
        return result;
    }
};