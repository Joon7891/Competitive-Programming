class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> start;
        for (vector<string> path : paths){
            start.insert(path[0]);
        }
        
        string ans = "";
        for (vector<string> path : paths){
            if (start.find(path[1]) == start.end()) ans = path[1];
        }
        
        return ans;
    }
};