class Solution {
public:
    int bSearch(vector<int> fib, int k){
        int low = 0;
        int high = fib.size() - 1;
        while (low != high){
            int mid = (low + high + 1) / 2;
            if (fib[mid] <= k){
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        
        return fib[low];
    }
    
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        fib.push_back(0);
        fib.push_back(1);
        
        int cur = 1;
        int index = 1;
        while (cur <= k && cur > 0){
            cur = fib[index] + fib[index - 1];
            fib.push_back(cur);
            index++;
        }
        
        int total = 0;
        while (k > 0){
            int remove = bSearch(fib, k);
            k -= remove;
            total++;
        }
        
        return total;
    }
};