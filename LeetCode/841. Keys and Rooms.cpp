class Solution {
public:
    set<int> visited;
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(0, rooms);
        return visited.size() == rooms.size();
    }
    
    void dfs(int cur, vector<vector<int>> rooms){
        visited.insert(cur);
        
        for (int next : rooms[cur]){
            if (visited.find(next) == visited.end()) dfs(next, rooms);
        }
    }
};