class Solution {
public:
    string reformat(string s) {
        vector<char> nums;
        vector<char> alpha;
        
        for (char c : s){
            if ('0' <= c && c <= '9') nums.push_back(c);
            else alpha.push_back(c);
        }
        
        string ans = "";
        if (nums.size() == alpha.size() + 1){
            for (int i = 0; i < alpha.size(); i++){
                ans += nums[i];
                ans += alpha[i];
            }
            
            ans += nums[nums.size() - 1];
        }
        else if (nums.size() + 1 == alpha.size() || nums.size() == alpha.size()){
            for (int i = 0; i < nums.size(); i++){
                ans += alpha[i];
                ans += nums[i];
            }
            
            if (nums.size() != alpha.size()) ans += alpha[alpha.size() - 1];
        }
        
        return ans;
    }
};