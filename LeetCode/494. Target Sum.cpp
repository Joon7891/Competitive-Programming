class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        set<int> s;
        vector<int> cur;
        map<int, int> freq;
        
        s.insert(nums[0]);
        s.insert(-nums[0]);
        freq[nums[0]] = 1;
        freq[-nums[0]] = 1;
        cur.push_back(nums[0]);
        cur.push_back(-nums[0]);
        
        for (int i = 1; i < nums.size(); i++){
            set<int> newS;
            vector<int> newCur;
            map<int, int> newFreq;
            
            for (int c : cur){
                newFreq[c + nums[i]] += freq[c];
                newFreq[c - nums[i]] += freq[c];
                
                if (newS.find(c + nums[i]) == newS.end()){
                    newS.insert(c + nums[i]);
                    newCur.push_back(c + nums[i]);
                }
                
                if (newS.find(c - nums[i]) == newS.end()){
                    newS.insert(c - nums[i]);
                    newCur.push_back(c - nums[i]);
                }
            }
            
            s = newS;
            cur = newCur;
            freq = newFreq;
        }
        
        return freq[S];
    }
};