class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> oneLoc;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1) oneLoc.push_back(i);
        }
                
        if (oneLoc.size() <= 1) return true;
        
        for (int i = 0; i < oneLoc.size() - 1; i++){
            if (oneLoc[i + 1] - oneLoc[i] - 1 < k) return false;
        }
            
        return true;
    }
};