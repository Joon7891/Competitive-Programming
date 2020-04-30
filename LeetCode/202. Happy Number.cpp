class Solution {
public:
    bool isHappy(int n) {
        set<int> vis;
        
        while (n != 1){
            if (vis.find(n) != vis.end()) return false;
            
            vis.insert(n);
            string num = to_string(n);
            
            n = 0;
            int length = num.length();
            for (int i = 0; i < length; i++){
                n += (num[i]-'0') * (num[i]-'0');
            }
        }
        
        return true;
    }
};