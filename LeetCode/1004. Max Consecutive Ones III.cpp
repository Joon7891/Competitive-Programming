class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        
        int ans = 0;
        int count = 0;
        int i = 0,j = 0;
        for (i = 0; i < A.size(); i++){
            if (A[i] == 0) count++;
            
            while (count > K){
                if (A[j] == 0) count--;
                j++;
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};