class Solution {
public:
    bool isEdge(int a, int b, vector<int>& edge){
        return (a == edge[0] && b == edge[1]) || (a == edge[0] && b == edge[1]);
    }
    
    bool dfs(int c, int target, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& skip){
        vis[c] = true;
        
        if (c == target) return true;
        
        bool ans = false;
        for (int next : adj[c]){
            if (!vis[next] && !isEdge(c, next, skip)) ans |= dfs(next, target, adj, vis, skip);
        }
        
        return ans;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<vector<int>> adj(N + 1, vector<int>());
        
        for (vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ans;
        for (vector<int> edge : edges){
            vector<bool> vis(N + 1, false);
            
            if (dfs(edge[0], edge[1], adj, vis, edge)) ans = edge;
        }
        
        return ans;
    }
};