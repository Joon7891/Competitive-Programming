#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
int dp[MAXN];
int v[MAXN];
int N;

int main(){
    cin >> N;

    for (int i = 1; i <= N; ++i) cin >> v[i];

    int best = 0;
    for (int i = 1; i <= N; ++i){
        int index = (int)(lower_bound(dp, dp + best, v[i]) - dp);
        dp[index] = v[i];

        if (index == best) best++;
    }

    cout << best << endl;
}
