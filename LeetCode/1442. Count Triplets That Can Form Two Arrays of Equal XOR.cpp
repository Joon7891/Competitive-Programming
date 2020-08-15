class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n, 0);
        
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] ^ arr[i];
                
        int total = 0;
        for (int k = 0; k < n; k++){
            for (int j = 0; j <= k; j++){
                for (int i = 0; i < j; i++){                    
                    int a = i == 0 ? prefix[j - 1] : prefix[j - 1] ^ prefix[i - 1];
                    int b = prefix[k] ^ prefix[j - 1];
                    
                    if (a == b) total++;
                }
            }
        }
        
        return total;
    }
};