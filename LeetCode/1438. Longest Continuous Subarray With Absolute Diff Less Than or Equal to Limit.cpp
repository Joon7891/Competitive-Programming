class Solution {
public:
    
    
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> low;
        deque<int> high;
        
        int ans = 0;
        int left = 0, right = 0;
        while (right < nums.size()){
            int a = nums[right];
            
            while (!low.empty() && nums[low.back()] >= a){
                low.pop_back();
            }
            low.push_back(right);
            
            while (!high.empty() && nums[high.back()] <= a){
                high.pop_back();
            }
            high.push_back(right);
            
            int lowVal = nums[low.front()];
            int highVal = nums[high.front()];
            
            if (highVal - lowVal <= limit){
                ans = max(ans, right - left + 1);
                right++;
            }
            else {
                left++;
                if (left > low.front()){
                    low.pop_front();
                }
                if (left > high.front()){
                    high.pop_front();
                }
            }
        }
        
        return ans;
    }
};