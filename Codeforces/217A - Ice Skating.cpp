#include<bits/stdc++.h>

using namespace std;
const int MAXN = 105;
pair<int, int> p[MAXN];
int par[MAXN];
int N;

int get_par(int index){
	if (par[index] == index) return index;
	return par[index] = get_par(par[index]);
}

void merge(int a, int b){
	int x = get_par(a);
	int y = get_par(b);
	par[x] = y;
}

int main(){
	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;
	
	for (int i = 0; i < N; i++) par[i] = i;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < i; j++){
			if (p[i].first == p[j].first || p[i].second == p[j].second) merge(i, j);
		}
	}
	
	int total = 0;
	int target = get_par(0);
	for (int i = 0; i < N; i++){
		int parent = get_par(i);
		if (parent != target){
			merge(parent, target);	
			total++;
		}		
	}
	
	cout << total << endl;
}