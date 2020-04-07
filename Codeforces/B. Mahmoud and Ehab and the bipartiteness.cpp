#include<bits/stdc++.h>
 
using namespace std;
const int MAXN = 100005;
vector<int> adj[MAXN];
int aColour = 0, bColour = 0;
int colour[MAXN];
 
void dfs(int cur, int prev, int c){
	if (c == 1) aColour++;
	else bColour++;
	
	colour[cur] = c;
	for (int next : adj[cur]) {
		if (prev ^ next) dfs(next, cur, -c);
	}
}
 
int main(){
	int N; cin >> N;
	
	for (int i = 0, u, v; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, -1, 1);
	
	long long total = 0;
	for (int i = 1; i <= N; i++){
		if (colour[i] == 1){
			total += bColour - adj[i].size();
		}
		else {
			total += aColour - adj[i].size();
		}
	}
	total /= 2;
	
	cout << total << endl;
}