#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int MAXN = 100005;
int par[MAXN];
int N, Q;

int get(int x) {
    if (par[x] != x) {
        par[x] = get(par[x]);
    }

    return par[x];

}

void combine(int a, int b) {
    int aPar = get(a);
    int bPar = get(b);

    if (aPar != bPar) par[bPar] = aPar;
}

int main()
{
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) par[i] = i;

    char a; int x, y;
    while (Q--) {
        cin >> a >> x >> y;

        if (a == 'A') {
            combine(x, y);
        }
        else {
            int xPar = get(x);
            int yPar = get(y);

            if (xPar != yPar) {
                cout << "N" << endl;
            } else {
                cout << "Y" << endl;
            }
        }
    }
}
