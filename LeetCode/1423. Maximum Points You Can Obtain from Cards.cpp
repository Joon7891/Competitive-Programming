class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int size = n - k;
        
        int total = 0;
        for (int i = 0; i < size; i++) total += cardPoints[i];
        
        int ans = total;
        for (int i = 0; i < k; i++){
            total -= cardPoints[i];
            total += cardPoints[i + size];
            ans = min(ans, total);
        }
        
        int gTotal = 0;
        for (int i = 0; i < n; i++) gTotal += cardPoints[i];
        return gTotal - ans;
    }
};