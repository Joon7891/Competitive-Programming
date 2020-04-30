class Solution {
public:
    vector<int> adj[100005];
    bool vis[100005];
    int t[100005];
    int T = 0;
    
    void dfs(int c){
        vis[c] = true;
        for (int next : adj[c]){
            if (!vis[next]) dfs(next);
        }
        
        t[c] = T++;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(vis, false, sizeof(vis));
        memset(t, 0, sizeof(t));
        
        for (vector<int> prereq : prerequisites){
            int a = prereq[0];
            int b = prereq[1];
            adj[b].push_back(a);
        }
        
        for (int i = 0; i < numCourses; i++){
            if (!vis[i]) dfs(i);
        }
        
        for (int i = 0; i < numCourses; i++){
            cout << t[i] << endl;
        }
        
        for (int i = 0; i < numCourses; i++){
            for (int next : adj[i]){
                if (t[next] > t[i]) return false;
            }
        }
        
        return true;
    }
};