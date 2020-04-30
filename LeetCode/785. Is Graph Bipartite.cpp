class Solution {
public:
    bool dfs(int c, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& colour, int curColour){
        vis[c] = true;
        colour[c] = curColour;
        
        bool ans = true;
        for (int next : adj[c]){
            if (!vis[next]) ans &= dfs(next, adj, vis, colour, -curColour);
            else if (colour[next] != -curColour) return false;
        }
        
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> colour(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; i++){
            for (int next : graph[i]){
                adj[i].push_back(next);
            }
        }
        
        bool ans = true;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++){
            if (!vis[i]) ans &= dfs(i, adj, vis, colour, 1);
        }
        
        return ans;
    }
};