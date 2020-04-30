class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> adj(N + 1, vector<pair<int, int>>());
        
        for (vector<int> t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }        
        
        int t[N + 1];
        memset(t, 0x3f3f3f3f, sizeof(t));
        
        t[K] = 0;
        queue<int> q; q.push(K);
        while (!q.empty()){
            int c = q.front(); q.pop();
            
            for (pair<int, int> next : adj[c]){
                int newCost = t[c] + next.second;
                if (newCost < t[next.first]){
                    t[next.first] = newCost;
                    q.push(next.first);
                }
            }
        }
        
        int best = 0;
        for (int i = 1; i <= N; i++) best = max(best, t[i]);
            
        return best == 0x3f3f3f3f ? -1 : best;
    }
};