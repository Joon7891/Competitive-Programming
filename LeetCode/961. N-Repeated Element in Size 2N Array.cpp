class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> vis;
        
        int ans = 0;
        for (int a : A){
            if (vis.find(a) == vis.end()) vis.insert(a);
            else ans = a;
        }
        
        return ans;
    }
};