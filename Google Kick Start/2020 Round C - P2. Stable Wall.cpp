#include <bits/stdc++.h>
using namespace std;

#define debug(var) cout << "[" << #var << " = " << var << "]" << endl;
typedef long long i64;

const int MAX = 35;
char grid[MAX][MAX];
vector<int> adj[26];
bool cVis[26];
bool vis[26];
bool exist[26];
bool flag;
string ans;

void dfs(int c){	
	vis[c] = cVis[c] = true;
	
	for (int next : adj[c]){
		if (cVis[next]) {
			flag = true;
			return;
		}
		else if (!vis[next]) dfs(next);
	}
	
	cVis[c] = false;
	ans += 'A' + c;
}

void solve(int caseNum){
	for (int i = 0; i < 26; i++){
		adj[i].clear();
	}
	ans = "";
	flag = false;
	memset(vis, 0, sizeof(vis));
	memset(exist, 0, sizeof(exist));
	
	int R, C; cin >> R >> C;
	
	for (int i = 0; i < R; i++){
		string line; cin >> line;
		
		for (int j = 0; j < C; j++){
			grid[i][j] = line[j];
			exist[grid[i][j] - 'A'] = 1;
		}
	}
	
	for (int i = 0; i < R - 1; i++){
		for (int j = 0; j < C; j++){
			int cur = grid[i][j]-'A';
			int below = grid[i + 1][j]-'A';
						
			if (cur != below && find(adj[cur].begin(), adj[cur].end(), below) == adj[cur].end()){
				adj[cur].push_back(below);
			} 
		}
	}
	
	for (int i = 0; i < 26; i++){
		if (exist[i] && !vis[i]){
			memset(cVis, 0, sizeof(cVis));
			dfs(i);
		}
		
		if (flag){
			cout << "Case #" << caseNum << ": -1" << endl;
			return;
		}
	}
	
	cout << "Case #" << caseNum << ": " << ans << endl;
}

int main(){
	int T; cin >> T;
	
	for (int i = 1; i <= T; i++) solve(i);
}