#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 105;
int a[MAXN][MAXN];

int main(){
	int N, M, D;	
	cin >> N >> M >> D;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) cin >> a[i][j];
	}
	
	int front = a[0][0] % D;
	int highest = -INF;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (a[i][j] % D != front){
				cout << -1 << endl;
				return 0;
			}
			else {
				a[i][j] = (a[i][j] - front) / D;
				highest = max(highest, a[i][j]);
			}
		}
	}
	
	int best = INF;
	for (int x = 0; x <= highest; x++){
		int counter = 0;
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				counter += abs(x - a[i][j]);
			}
		}
		
		best = min(best, counter);
	}
	
	cout << best << endl;
}