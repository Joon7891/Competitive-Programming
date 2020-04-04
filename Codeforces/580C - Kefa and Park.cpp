#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
bool cat[MAXN];
bool vis[MAXN];
int N, M;

int main(){
	memset(vis, 0, sizeof(vis));
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) cin >> cat[i];

	for (int i = 0, x, y; i < N - 1; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	int ans = 0;
	queue<pair<int, int>> q;
	
	q.push({1, cat[1]});
	while (!q.empty()){
		pair<int, int> cur = q.front(); q.pop();
		vis[cur.first] = 1;
		
		if (adj[cur.first].size() == 1 && vis[adj[cur.first][0]]){
			ans++;
			continue;
		}
		
		for (int next : adj[cur.first]){
			if (!vis[next] && cur.second + cat[next] <= M){
				if (cat[next]) q.push({next, cur.second + 1});
				else q.push({next, 0});				
			}
		}
	}
	
	cout << ans << endl;
}