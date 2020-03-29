#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

const int MAXN = 100005;
int a[MAXN];
long long track[MAXN];
long long ans[MAXN];
long long BIT[MAXN];
long long total = 0;
int N;

void updateBIT(int index){
    while (index <= N){
        BIT[index]++;
        index += index & -index;
    }
}

long long getBIT(int index){
    long long total = 0;
    while (index > 0){
        total += BIT[index];
        index -= index & -index;
    }

    return total;
}

void getInversions(){
    updateBIT(N + 1 - a[1]);
    for (int i = 2; i <= N; i++){
        long long res = getBIT(N - a[i]);
        total += res;
        track[a[i]] += res;
        updateBIT(N - a[i] + 1);
    }
}

int main(){
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    memset(track, 0, sizeof(track));
    memset(BIT, 0, sizeof(BIT));

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i + 1];

    getInversions();

    for (int i = N - 1; i >= 0; i--){
        total -= track[i];
        ans[i] = total;
    }

    for (int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
}