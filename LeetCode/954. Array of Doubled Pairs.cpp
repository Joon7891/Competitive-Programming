class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> freq;
        for (int a : A) freq[a]++;
        
        sort(A.begin(), A.end(), [](int a, int b){ return std::abs(a) < std::abs(b); });
        
        for (int a : A){            
            if (freq[a] == 0) continue;
            
            if (freq[2 * a] > 0){
                freq[2 * a]--;
                freq[a]--;
            }
            else return false;
        }
        
        return true;
    }
};