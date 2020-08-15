class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) { 
        vector<int> ans;
        for (int i = A.size(); i > 0; i--){
            if (A[i - 1] == i) continue;
            
            int j;
            for (j = 0; j < A.size(); j++){
                if (i == A[j]) break;
            }
                        
            if (j != 0){                
                ans.push_back(j + 1);
            }
            
            ans.push_back(i);
            reverse(A.begin(), A.begin() + j + 1);
            reverse(A.begin(), A.begin() + i);
        }
        
        return ans;
    }
};