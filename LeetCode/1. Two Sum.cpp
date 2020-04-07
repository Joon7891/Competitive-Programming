class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indicies;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (!(nums[i] + nums[j] - target))
                {
                    indicies.push_back(j);
                    indicies.push_back(i);
                    return indicies;                    
                }
            }
        }
        
        return indicies;
    }
};