class Solution {
public:
    string reduce(string s){
        int length = s.length();
        if (s[length - 1] == '0') return s.substr(0, length - 1);
        
        bool carry = true;
        string res = "";
        for (int i = length - 1; i >= 0; i--){
            if (carry){
                if (s[i] == '0') {
                    res += '1';
                    carry = false;
                }
                else {
                    res += '0';
                }
            }
            else {
                res += s[i];
            }
        }
        
        if (carry) res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
    
    int numSteps(string s) {
        int total = 0;
        while (s != "1") {
            s = reduce(s);
            total++;
        }
        
        return total;
    }
};