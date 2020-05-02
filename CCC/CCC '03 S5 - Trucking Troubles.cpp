#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;
const int MAXN = 10005;
vector<pii> adj[MAXN];
int best[MAXN];
vector<int> t;
int c, r, d;

int main(){
	memset(best, 0, sizeof(best));
	
	cin >> c >> r >> d;
	
	for (int i = 0, x, y, w; i < r; i++){
		cin >> x >> y >> w;
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
	
	for (int i = 0, x; i < d; i++){
		cin >> x;
		t.push_back(x);
	}
	
	best[1] = INT_MAX;
	queue<int> q; q.push(1);
	while (!q.empty()){
		int x = q.front(); q.pop();
		
		for (pii next : adj[x]){
			int newCost = min(best[x], next.second);			
			if (newCost > best[next.first]){
				best[next.first] = newCost;
				q.push(next.first);
			}
		}
	}

	int ans = INT_MAX;
	for (int dest : t){
		ans = min(ans, best[dest]);
	}
	
	cout << ans << endl;
}
