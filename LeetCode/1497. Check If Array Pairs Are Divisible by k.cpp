class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> freq;
        
        for (int a : arr) {
            int mod = ((a % k) + k) % k;
            freq[mod]++;
        }
        
        if (freq[0] % 2 == 1) return false;
        
        for (int i =  1; i < k; i++) {
            if (freq[i] != freq[k - i]) return false;
        }
        
        return true;
    }
};