#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    int t; cin >> t;

    while (t--){
        int n, m; cin >> n >> m;

        int first; cin >> first;

        int total = 0;
        for (int i = 1, x; i < n; i++) {
            cin >> x;
            total += x;
        }

        int ans = min(m, first + total);
        cout << ans << endl;
    }
}
