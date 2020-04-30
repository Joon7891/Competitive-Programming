class NumArray {
public:
    NumArray* left;
    NumArray* right;
    int l, r, sum;
        
    NumArray(vector<int>& nums) {
        if (nums.size() == 0) return;
        else if (nums.size() == 1){
            l = 0;
            r = 0;
            sum = nums[0];
        }
        else {
            l = 0;
            r = nums.size() - 1;
            int mid = (l + r) / 2;
            left = new NumArray(nums, l, mid);
            right = new NumArray(nums, mid + 1, r);
            sum = left->sum + right->sum;
        }
        
        cout << l << ", " << r << " : " << sum << endl;
    }
    
    NumArray(vector<int>& nums, int l, int r){
        this->l = l;
        this->r = r;
        
        if (l == r){
            sum = nums[l];
            left = NULL;
            right = NULL;
        }
        else {
            int mid = (l + r) / 2;
            left = new NumArray(nums, l, mid);
            right = new NumArray(nums, mid + 1, r);
            sum = left->sum + right->sum;
        }
    }
    
    void update(int i, int val) {
        if (i < l || i > r) return;
        
        if (l == r && i == l){
            sum = val;
        }
        else {
            left->update(i, val);
            right->update(i, val);
            sum = left->sum + right->sum;
        }
    }
    
    int sumRange(int i, int j) {        
        if (j < l || i > r) return 0;
        if (i <= l && r <= j) return sum;
        return left->sumRange(i, j) + right->sumRange(i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */