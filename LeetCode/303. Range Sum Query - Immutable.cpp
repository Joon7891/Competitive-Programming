class NumArray {
public:
    vector<int> prefix;
    
    NumArray(vector<int>& nums) {
        if (nums.size() == 0) return;
        
        prefix.resize(nums.size(), 0);
        
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return prefix[j];
        else return prefix[j] - prefix[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */