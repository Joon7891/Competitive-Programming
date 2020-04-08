#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<i64, i64>

using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> order;
int N, M;

int main(){
	fill(vis, vis + MAXN, false);
	
	cin >> N >> M;
	
	for (int i = 0, a, b; i < M; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	
	vis[1] = true;
	order.push_back(1);
	
	priority_queue<int, vector<int>, greater<int>> q;
	for (int e : adj[1]) q.push(e);
	
	while (order.size() < N){
		int cur = q.top(); q.pop();
		
		if (!vis[cur]){
			vis[cur] = true;
			order.push_back(cur);
			
			for (int e : adj[cur]) q.push(e);
		}
	}
	
	for (int e : order) cout << e << " ";
	cout << endl;
}