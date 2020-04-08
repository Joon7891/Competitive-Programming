#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define i64 long long
#define pii pair<i64, i64>

using namespace std;

struct Edge{
	i64 next, weight;
};

const int MAXN = 100005;
vector<Edge> adj[MAXN];
int back[MAXN];
i64 weight[MAXN];
int N, M;

int main(){
	cin >> N >> M;
	
	for (int i = 1, a, b, w; i <= M; i++){
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	
	fill(weight, weight + MAXN, LLONG_MAX);	
	weight[1] = 0;
	back[1] = 1;
	
	priority_queue<pii, vector<pii>, greater<pii>> q; 
	q.push({0, 1});
	
	while (!q.empty()){
		pii cur = q.top(); q.pop();		
		if (cur.second == N) break;
		
		for (Edge e : adj[cur.second]){
			if (cur.first + e.weight < weight[e.next]){
				weight[e.next] = cur.first + e.weight;
				
				q.push({weight[e.next], e.next});
				back[e.next] = cur.second;
			}
		}
	}
	
	if (weight[N] == LLONG_MAX){
		cout << -1 << endl;
		return 0;
	}
	
	int cur = N;
	vector<int> path;
	while (cur != back[cur]){
		path.push_back(cur);
		cur = back[cur];
	}
	
	cout << "1 ";
	for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
	cout << endl;
}