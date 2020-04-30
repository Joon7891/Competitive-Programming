class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int prefixXor[arr.size()];
        prefixXor[0] = arr[0];
        for (int i = 1; i < arr.size(); i++){
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }
        
        vector<int> ans;
        for (vector<int> query : queries){
            int l = query[0];
            int r = query[1];
            
            if (l == 0) ans.push_back(prefixXor[r]);
            else ans.push_back(prefixXor[r] ^ prefixXor[l - 1]);
        }
        
        return ans;
    }
};