class Solution {
public:
    map<int, vector<int>> adj;
    vector<int> ans;
    map<int, int> t;
    set<int> vis;
    int T = 0;
    
    void dfs(int c){
        vis.insert(c);
        
        for (int next : adj[c]){
            if (vis.find(next) == vis.end()) dfs(next);
        }
        
        ans.push_back(c);
        t[c] = T++;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int> pre : prerequisites){
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
        }
        
        for (int i = 0; i < numCourses; i++){
            if (vis.find(i) == vis.end()) dfs(i);
        }
                
        for (int i = 0; i < numCourses; i++){
            for (int next : adj[i]){
                if (t[next] > t[i]) return vector<int>();
            }
        }
                
        reverse(ans.begin(), ans.end());
        return ans;
    }
};