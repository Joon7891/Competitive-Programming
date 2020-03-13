#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 105;
int h[MAXN];

int main(){
    int T; cin >> T;

    while (T--){
        int n, m, k; cin >> n >> m >> k;

        for (int i = 1; i <= n; i++) cin >> h[i];

        for (int i = 1; i <= n; i++){
            if (i == n){
                cout << "YES" << endl;
            }
            else {
                if (h[i + 1] - h[i] < k && h[i] > 0){
                    m += min(h[i], k - h[i + 1] + h[i]);
                }

                if (h[i + 1] - h[i] > k){
                    int dif = h[i + 1] - h[i] - k;

                    if (dif <= m){
                        m -= dif;
                    }
                    else {
                        cout << "NO" << endl;
                        break;
                    }
                }
            }
        }
    }
}
