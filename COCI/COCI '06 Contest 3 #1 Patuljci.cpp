#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 105;
vector<int> dp[MAXN]; 
int a[MAXN];
int N = 9;

int main(){
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        dp[a[i]].push_back(1 << i);
    }

    for (int i = 0; i <= 100; ++i){
        for (int j = 0; j < N; ++j){
            if (i - a[j] >= 0){
                for (int mask : dp[i - a[j]]){
                    if (!(mask & (1 << j))){
                        dp[i].push_back(mask | (1 << j));
                    }
                }
            }
        }
    }

    int finalMask;
    for (int mask : dp[100]){
        if (__builtin_popcount(mask) == 7) finalMask = mask;
    }

    for (int i = 0; i < 20; ++i){
        if (finalMask & (1 << i)){
            cout << a[i] << endl;
        }
    }
}
