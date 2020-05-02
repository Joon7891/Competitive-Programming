class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int best = 0;
        for (int candy : candies) best = max(best, candy);
            
        vector<bool> ans;
        for (int i = 0; i < candies.size(); i++){
            ans.push_back(candies[i] + extraCandies >= best);
        }
        
        return ans;
    }
};