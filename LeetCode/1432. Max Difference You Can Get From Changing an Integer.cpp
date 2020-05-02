class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        int aChange = -1;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != '9') {
                aChange = s[i]-'0';
                break;
            }
        }
        
        int bChange = -1;
        bool useFront = false;
        if (s[0] != '1') {
            bChange = s[0] - '0';
            useFront = true;
        }
        else {
            for (int i = 1; i < s.size(); i++){
                if (s[i] != '0' && s[i] != '1') {
                    bChange = s[i] - '0';
                    break;
                }
            }
        }
                        
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++){
            a *= 10;
            if (s[i] - '0' == aChange) a += 9;
            else a += s[i] - '0';
            
            b *= 10;
            if (s[i] - '0' == bChange) b += useFront ? 1 : 0;
            else b += s[i] - '0';
        }
                
        return a - b;
    }
};