class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {        
        vector<int> prev;
        for (int e : mat[0]) prev.push_back(e);
        sort(prev.begin(), prev.end());
        
        for (int i = 1; i < mat.size(); i++){
            vector<int> cur = mat[i];
            
            vector<int> next;
            for (int e : mat[i]){
                for (int f : prev){
                    next.push_back(e + f);
                }
            }
            
            sort(next.begin(), next.end());
            
            vector<int> fNext;
            for (int i = 0; i < min((int)next.size(), 200); i++){
                fNext.push_back(next[i]);
            }
            
            prev = fNext;
        }
        
        return prev[k - 1];
    }
};