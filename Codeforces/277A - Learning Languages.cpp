#include<bits/stdc++.h>

using namespace std;
const int MAXN = 105;
vector<int> lang[MAXN];
int par[MAXN];
int N, M;

bool similar(vector<int> x, vector<int> y){
	for (int xi : x){
		for (int yi : y){
			if (xi == yi) return true;
		}
	}
	
	return false;
}

int get_par(int index){
	if (index == par[index]) return index;
	return par[index] = get_par(par[index]);
}

void merge(int a, int b){
	int x = get_par(a);
	int y = get_par(b);
	par[x] = y;
}

int main(){
	cin >> N >> M;
	
	for (int i = 0, x; i < N; i++){
		par[i] = i;
		cin >> x;
		
		for (int j = 0, y; j < x; j++){
			cin >> y;
			lang[i].push_back(y);
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (similar(lang[i], lang[j])){
				merge(i, j);
			}
		}
	}
	
	bool noLang = true;
	for (int i = 0; i < N; i++){
		if (lang[i].size() > 0) noLang = false;
	}
	
	int total = noLang;
	int target = get_par(0);
	for (int i = 0; i < N; i++){
		int parent = get_par(i);
		if (parent != target){
			total++;
			merge(parent, target);
		}
	}
	
	cout << total << endl;
}