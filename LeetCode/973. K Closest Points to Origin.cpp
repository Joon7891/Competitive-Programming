class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), 
             [](vector<int> a, vector<int> b){
                 int aLen = a[0] * a[0] + a[1] * a[1];
                 int bLen = b[0] * b[0] + b[1] * b[1];
                 return aLen <= bLen;
             }
            );
        
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) ans.push_back(points[i]);
        
        return ans;
    }
};