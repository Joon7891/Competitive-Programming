class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> key(m + 1, 0);
        vector<int> ans;
        
        for (int i = 0; i < m; i++) key[i] = i + 1;
        
        for (int i = 0; i < queries.size(); i++){
            int j;
            for (j = 0; i < m; j++){
                if (queries[i] == key[j]) break;
            }
            
            ans.push_back(j);
            for (int k = j; k > 0; k--){
                key[k] = key[k - 1];
            }
            key[0] = queries[i];
        }
        
        return ans;
    }
};