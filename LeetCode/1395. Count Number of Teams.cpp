class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                for (int k = 0; k < j; k++){
                    if (rating[i] < rating[j] && rating[j] < rating[k]) ans++;
                    if (rating[i] > rating[j] && rating[j] > rating[k]) ans++;
                }
            }
        }
        
        return ans;
    }
};